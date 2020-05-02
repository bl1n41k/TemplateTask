using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1_sharp
{
	class Stack<T>
	{
        private T[] array; 
        private int head;  

        public Stack(int count)
        {
            array = new T[count]; 
        }
       
        public void Push(T element)
        {
            if (head == array.Length) throw new OutOfMemoryException("Stack is full!");
            else array[head++] = element;
        }
        public T Pop()
        {
            if (head < 1) throw new ArgumentOutOfRangeException("Stack is empty!");
            T element = array[head--]; 
            array[head] = default(T); 
            return element; 
        }

        public Stack<T> Merge(Stack<T> stack2) 
        {
            Stack<T> stack3 = new Stack<T>(head + stack2.head);
            
            while (stack3.head != head)
            {   
                stack3.Push(array[stack3.head]);
            }
            int i = 0;
            while (stack3.head != stack2.head + head) 
            {
                stack3.Push(stack2.array[i]);
                i++;
            }
            return stack3;
        }

		public void Print() 
		{
			for (int i = 0 ; i < head; i++) Console.Write(array[i] + " ");
			Console.WriteLine();
		}
	}
}
