using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2_sharp
{
	class BinaryTree<T> where T : IComparable
	{
        class Node
        {
            public T info;
            public Node left;
            public Node right;

            public Node(T info) 
            {
                left = null;
                this.info = info;
                right = null;
            }
        }
        Node root;

        public BinaryTree()
        {
            root = null;
        }

        public List<T> buildPath()
        {
            List<T> top = new List<T>();
            void buildPath(Node root)
            {
                if (root != null)
                {
                    buildPath(root.left);
                    top.Add(root.info);
                    buildPath(root.right);
                }
            }
            buildPath(root);
            return top;
        }

        public void insert(T info)
        {
            if (root == null) root = new Node(info);
            else insert(info, ref root);
        }

        private void insert(T info, ref Node root)
        {
            if (root == null) root = new Node(info);
            else if (info.CompareTo(root.info) < 0) insert(info, ref root.left);
            else if (info.CompareTo(root.info) > 0) insert(info, ref root.right);
            else throw new ArgumentException("This element already exists!");
        }

        public void remove(T info)
        {
            remove(info, ref root);
        }

        private void remove(T info, ref Node root)
        {
            if (root == null) throw new ArgumentException("This element was not found!");
            if (info.CompareTo(root.info) > 0) remove(info, ref root.right);
            else if (info.CompareTo(root.info) < 0) remove(info, ref root.left);
            else
            {
                Node temp = root;
                if (temp.left == null && temp.right == null) root = null;
                else if (temp.left != null && temp.right == null) root = temp.left;
                else if (temp.left == null && temp.right != null) root = temp.right;
                else
                {
                    Node max = temp.left;
                    while (max.right != null) max = max.right;
                    temp.info = max.info;
                    remove(max.info, ref temp.left);
                }
            }
        }

        public List<T> listOfLeaves()
        {
            List<T> leafList = new List<T>();
            void leaf(Node root)
            {
                if (root.left == null && root.right == null)
                    leafList.Add(root.info);
                else
                {
                    if (root.left != null) leaf(root.left);
                    if (root.right != null) leaf(root.right);
                }
            }
            leaf(root);
            return leafList;
        }

        private bool Search(T info, Node root)
        {
            if (root == null) return false;
            else if (info.CompareTo(root.info) == 0) return true;
            else if (info.CompareTo(root.info) > 0) return Search(info, root.right);
            else return Search(info, root.left);
        }

        public bool Search(T info)
        {
            return Search(info, root);
        }

        private string PrintTree(Node node)
        {
            string leftChild = (node.left == null) ? "()" : PrintTree(node.left);
            string rightChild = (node.right == null) ? "()" : PrintTree(node.right);
            string result = "{" + leftChild+ ", " + (node.info).ToString() + ", " + rightChild + "}";
            return result;
        }

        public override string ToString()
        {
            if (root == null) return "()";
            else return PrintTree(root);
        }
    }
}

