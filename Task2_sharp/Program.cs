using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task2_sharp
{
	class Program
	{
		static void Main(string[] args)
		{
			BinaryTree<int> Tree = new BinaryTree<int>();
			List<int> Path;
			List<int> Leaves;
			Tree.insert(2);
			Tree.insert(14);
			Tree.insert(8);
			Tree.insert(10);
			Tree.insert(32);
			Tree.remove(14);
			Console.WriteLine("Дерево: {0}",Tree.ToString());

			Path = Tree.buildPath();
			Console.Write("Путь обхода вершин: ");
			for (int i = 0; i < Path.Count(); i++) Console.Write("{0} ", Path[i]);
			Console.WriteLine();

			Console.Write("Список листьев: ");
			Leaves = Tree.listOfLeaves();
			for (int i = 0; i < Leaves.Count(); i++) Console.Write("{0} ", Leaves[i]);
			Console.WriteLine();

			if (Tree.Search(2)) Console.WriteLine("Элемент найден!");
			Tree.remove(2);
			if (!Tree.Search(2)) Console.WriteLine("Элемент не найден!");

			Tree.insert(12);
			Tree.insert(3);
			Tree.insert(9);
			Tree.insert(5);
			Tree.insert(7);
			Tree.insert(6);
			Tree.insert(18);
			Console.WriteLine("Дерево: {0}", Tree.ToString());

			Path = Tree.buildPath();
			Console.Write("Путь обхода вершин: ");
			for (int i = 0; i < Path.Count(); i++) Console.Write("{0} ", Path[i]);
			Console.WriteLine();

			Console.Write("Список листьев: ");
			Leaves = Tree.listOfLeaves();
			for (int i = 0; i < Leaves.Count(); i++) Console.Write("{0} ", Leaves[i]);
			Console.WriteLine();
		}
	}
}
