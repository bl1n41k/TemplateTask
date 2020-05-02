using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Task1_sharp
{
	class Program
	{
		static void Main(string[] args)
		{
			Stack<int> stack1 = new Stack<int>(4);
			Stack<int> stack2 = new Stack<int>(5);
			Stack<int> stack3 = new Stack<int>(9);
			stack1.Push(1);
			stack1.Pop();
			stack1.Push(3);
			stack1.Push(5);
			stack1.Push(7);
			stack1.Push(9);
			Console.Write("Стек 1: "); stack1.Print();
			stack2.Push(2);
			stack2.Push(4);
			stack2.Push(6);
			stack2.Push(8);
			stack2.Push(10);
			Console.Write("Стек 2: "); stack2.Print();
			stack3 = stack1.Merge(stack2);
			Console.Write("Стек 1 + 2: "); stack3.Print();
		}
	}
}
