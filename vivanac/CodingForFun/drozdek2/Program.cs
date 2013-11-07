using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace drozdek2
{
	public class TreeNode
	{
		private int value;

		public int Value
		{
			get { return value; }
			set { this.value = value; }
		}
		public TreeNode Left { get; set; }
		public TreeNode Right { get; set; }

		public TreeNode(int value)
		{
			this.value = value;
			Left = null;
			Right = null;
		}
	}
	public class BSTree
	{
		public TreeNode Root { get; private set; }

		public BSTree()
		{
			Root = null;
		}
		public void AddNode(int value)
		{
			TreeNode newNode = new TreeNode(value);
			addNode(Root, newNode);
		}
		public TreeNode Find(int value)
		{
			TreeNode curr = Root;
			while (curr != null)
			{
				if (curr.Value == value)
					return curr;

				if (curr.Value > value)
					curr = curr.Left;
				else
					curr = curr.Right;
			}
			return null;
		}

		public void BFS()
		{
			Queue<TreeNode> queue = new Queue<TreeNode>();

			if (Root == null) return;
			queue.Enqueue(Root);
			while (queue.Count != 0)
			{
				TreeNode tn = queue.Dequeue();
				Console.WriteLine(tn.Value);
				if (tn.Left != null)
					queue.Enqueue(tn.Left);
				if (tn.Right != null)
					queue.Enqueue(tn.Right);
			}
		}
		public void DFSPreorder()
		{
			dfsPreorder(Root);
		}
		private void dfsPreorder(TreeNode node)
		{
			if (node == null)
				return;

			Console.WriteLine(node.Value);
			dfsPreorder(node.Left);
			dfsPreorder(node.Right);
		}
		public void DFSInorder()
		{
			dfsInorder(Root);
		}
		private void dfsInorder(TreeNode node)
		{
			if (node == null)
				return;

			dfsInorder(node.Left);
			Console.WriteLine(node.Value);
			dfsInorder(node.Right);
		}
		public void DFSPostorder()
		{
			dfsPostorder(Root);
		}
		private void dfsPostorder(TreeNode node)
		{
			if (node == null)
				return;

			dfsPostorder(node.Left);
			dfsPostorder(node.Right);
			Console.WriteLine(node.Value);

		}

		public void DFSPreorderStack()
		{
			Stack<TreeNode> stack = new Stack<TreeNode>();
			if (Root == null)
				return;

			TreeNode curr = Root;

			while (true)
			{
				do
				{
					Console.WriteLine(curr.Value);
					stack.Push(curr);
					curr = curr.Left;
				} while (curr != null);

				do
				{
					if (stack.Count == 0) break;
					curr = stack.Pop().Right;
				} while (curr == null);

				if (stack.Count == 0 && curr == null)
					break;
			}

		}

		public void DeleteByMerging(int value)
		{
			TreeNode curr = Root;
			TreeNode parent = null;

			while (curr != null)
			{
				if (curr.Value == value)
					break;

				parent = curr;

				if (curr.Value > value)
					curr = curr.Left;
				else
					curr = curr.Right;
			}

			if (curr == null)
				return;

			if (curr.Left == null && curr.Right == null)
			{
				if (parent != null)
				{
					if (parent.Value > curr.Value)
						parent.Left = null;
					else
						parent.Right = null;
				}
				else
					Root = null;
				curr = null;

			}
			else
			{
				if (curr.Left == null)
				{
					if (parent != null)
					{
						if (parent.Value > curr.Value)
							parent.Left = curr.Right;
						else
							parent.Right = curr.Right;
					}
					else
						parent = curr.Right;
					curr = null;
				}
				else if (curr.Right == null)
				{
					if (parent != null)
					{
						if (parent.Value > curr.Value)
							parent.Left = curr.Left;
						else
							parent.Right = curr.Left;
					}
					else
						parent = curr.Left;
					curr = null;
				}
				else
				{
					//find right-most node
					TreeNode tmp = curr.Left;
					while (tmp.Right != null)
					{
						tmp = tmp.Right;
					}
					if (parent != null)
					{
						if (parent.Value > curr.Value)
							parent.Left = curr.Left;
						else
							parent.Right = curr.Left;
					}
					else
						Root = curr.Left;
					tmp.Right = curr.Right;
					curr = null;
				}
			}
		}

		public void DeleteByCopying(int value)
		{
			TreeNode curr = Root;
			TreeNode parent = null;

			while (curr != null)
			{
				if (curr.Value == value)
					break;

				parent = curr;

				if (curr.Value > value)
					curr = curr.Left;
				else
					curr = curr.Right;
			}

			if (curr == null)
				return;

			if (curr.Left == null && curr.Right == null)
			{
				if (parent != null)
				{
					if (parent.Value > curr.Value)
						parent.Left = null;
					else
						parent.Right = null;
				}
				else
					Root = null;
				curr = null;

			}
			else
			{
				if (curr.Left == null)
				{
					if (parent != null)
					{
						if (parent.Value > curr.Value)
							parent.Left = curr.Right;
						else
							parent.Right = curr.Right;
					}
					else
						parent = curr.Right;
					curr = null;
				}
				else if (curr.Right == null)
				{
					if (parent != null)
					{
						if (parent.Value > curr.Value)
							parent.Left = curr.Left;
						else
							parent.Right = curr.Left;
					}
					else
						parent = curr.Left;
					curr = null;
				}
				else
				{
					//find the rightmost node
					TreeNode tmp = curr.Left;
					TreeNode tmpParent = curr;
					while (tmp.Right != null)
					{
						tmpParent = tmp;
						tmp = tmp.Right;
					}

					curr.Value = tmp.Value;

					if (tmpParent != curr)
						tmpParent.Right = tmp.Left;
					else
						tmpParent.Left = tmp.Left;

					tmp = null;

				}
			}
		}

		private void addNode(TreeNode parent, TreeNode child)
		{
			if (parent == null)
			{
				Root = child;
				return;
			}
			if (parent.Value == child.Value)
				return;

			if (parent.Value > child.Value)
			{
				if (parent.Left == null)
					parent.Left = child;
				else
					addNode(parent.Left, child);
			}
			else
			{
				if (parent.Right == null)
					parent.Right = child;
				else
					addNode(parent.Right, child);
			}
		}


	}

	public class Node
	{
		private char value;
		private int tag;
		private List<Node> adjencyNodes;

		public char Value
		{
			get { return value; }
		}
		public List<Node> AdjencyNodes
		{
			get { return adjencyNodes; }
		}
		public int Tag
		{
			get { return tag; }
			set { tag = value; }
		}

		public Node(char value)
		{
			this.value = value;
			this.tag = tag;
			this.adjencyNodes = new List<Node>();
		}

		public void AddAdjencyNode(Node n)
		{
			adjencyNodes.Add(n);
		}
	}

	public class Edge
	{
		private Node a;
		private Node b;
		private int weight;
		private string name;

		public Node A { get { return a; } }
		public Node B { get { return b; } }
		public int Weight { get { return weight; } }
		public string Name { get { return name; } }

		public Edge(Node a, Node b)
		{
			this.a = a;
			this.b = b;
			this.weight = 0;
			this.name = a.Value.ToString() + b.Value.ToString();
		}
		public Edge(Node a, Node b, int weight)
		{
			this.a = a;
			this.b = b;
			this.weight = weight;
			this.name = a.Value.ToString() + b.Value.ToString();
		}
	}

	public class Graph
	{
		public List<Node> Nodes { get; private set; }
		public Dictionary<string, Edge> Edges { get; private set; }

		public Graph()
		{
			Nodes = new List<Node>();
			Edges = new Dictionary<string, Edge>();
		}

		public void AddEdge(Edge e)
		{
			Edges.Add(e.Name, e);
			e.A.AddAdjencyNode(e.B);
		}

		public void Dijkstra(Node n)
		{
			foreach (Node node in Nodes)
				node.Tag = 1000;

			n.Tag = 0;
			List<Node> toBeChecked = new List<Node>(Nodes);

			while (toBeChecked.Count != 0)
			{
				//find minimum dist
				int min = 1000;
				Node minNode = null;
				for (int i = 0; i < toBeChecked.Count; i++)
				{
					if (min > toBeChecked[i].Tag)
					{
						minNode = toBeChecked[i];
						min = minNode.Tag;
					}
				}
				toBeChecked.Remove(minNode);

				if (minNode.AdjencyNodes.Count != 0)
				{
					foreach (Node an in minNode.AdjencyNodes)
					{
						if (toBeChecked.Contains(an))
						{
							string key = minNode.Value.ToString() + an.Value.ToString();
							if (minNode.Tag + Edges[key].Weight < an.Tag)
							{
								an.Tag = minNode.Tag + Edges[key].Weight;
							}
						}
					}
				}
				//for ajd call new dist and if distance is smaller then current, update and
				//and put adj node to toBeChecked

			}

		}
		public List<Edge> BFS()
		{
			foreach (Node n in Nodes)
				n.Tag = 0;

			List<Edge> edges = new List<Edge>();
			Queue<Node> queue = new Queue<Node>();
			int index = 0;
			foreach (Node n in Nodes)
			{
				if (n.Tag == 0)
				{
					n.Tag = ++index;
					queue.Enqueue(n);
				}

				while (queue.Count > 0)
				{
					Node qn = queue.Dequeue();
					foreach (Node an in qn.AdjencyNodes)
					{
						if (an.Tag == 0)
						{
							an.Tag = ++index;
							edges.Add(new Edge(qn, an));
							queue.Enqueue(an);
						}
					}
				}
			}
			return edges;
		}
		public List<Edge> DFS()
		{
			foreach (Node n in Nodes)
				n.Tag = 0;

			int index = 0;
			List<Edge> edges = new List<Edge>();

			foreach (Node n in Nodes)
			{
				if (n.Tag == 0)
				{
					dfs(n, edges, ref index);
				}
			}

			return edges;
		}
		private void dfs(Node n, List<Edge> edges, ref int index)
		{
			n.Tag = ++index;
			foreach (Node an in n.AdjencyNodes)
			{
				if (an.Tag == 0)
				{
					edges.Add(new Edge(n, an));
					dfs(an, edges, ref index);
				}
			}
		}

	}



	class Program
	{
		static void InsertionSort(int[] arr)
		{
			for (int i = 1; i < arr.Count(); i++)
			{
				int tmp = arr[i];
				int lastIndex = i;
				for (int j = i; j > 0 && tmp < arr[j - 1]; j--)
				{
					arr[j] = arr[j - 1];
					lastIndex = j - 1;
				}
				arr[lastIndex] = tmp;
			}
			int a = 5;
		}

		static void BubbleSort(int[] arr)
		{
			for (int i = arr.Count() - 1; i > 0; i--)
			{
				for (int j = 0; j < i; j++)
				{
					if (arr[j] > arr[j + 1])
					{
						int tmp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = tmp;
					}
				}
			}
		}

		static void SelectionSort(int[] arr)
		{
			for (int i = arr.Count() - 1; i > 0; i--)
			{
				int max = Int32.MinValue;
				int maxIndex = 0;
				for (int j = 0; j < i; j++)
				{
					if (arr[j] > max)
					{
						max = arr[j];
						maxIndex = j;
					}
				}
				if (max > arr[i])
				{
					arr[maxIndex] = arr[i];
					arr[i] = max;
				}
			}
		
		}

		static void swap(int[] arr, int i, int j)
		{
			int tmp = arr[i];
			arr[i] = arr[j];
			arr[j] = tmp;
		}

		static void quickSrt(int[] arr, int begin, int end)
		{
			//find pivot
			int pivotIndex = (begin + end) / 2;
			int pivotValue = arr[pivotIndex];
			swap(arr, begin, pivotIndex);
			int first = begin + 1;
			int last = end;
			//swap elements based on pivot
			while (first <= last)
			{
				while (arr[first] < pivotValue)
					first++;
				while (arr[last] > pivotValue)
					last--;
				if (first < last)
					swap(arr, first++, last++);
				else
					first++;
			}
			swap(arr, begin, last);
			if (begin < last - 1)
			{
				quickSrt(arr, begin, last - 1);
			}
			if (end > last + 1)
			{
				quickSrt(arr, last + 1, end);
			}
		}

		static void QuickSort(int[] arr)
		{
			if(arr.Length < 2)
				return;
			//find max and put it last
			int maxIndex = 0;
			for(int i = 0; i<arr.Length; i++)
			{
				if(arr[maxIndex] < arr[i])
				{
					maxIndex = i;
				}
			}
			swap(arr, maxIndex, arr.Length - 1);
			quickSrt(arr,0, arr.Length-2);
		}

		static string ReplaceSpacesWithCode(string s)
		{
			int spaceCount = 0;
			for (int i = 0; i < s.Length; i++)
			{
				if (s[i] == ' ')
					spaceCount++;
			}

			int newLength = s.Length+2*spaceCount;
			char[] newStringArr = new char[s.Length + 2 * spaceCount];
			int newIndex = newLength-1;
			int oldIndex = s.Length-1;
			while (newIndex >= 0)
			{
				if (s[oldIndex] == ' ')
				{
					newIndex = newIndex - 2;
					newStringArr[newIndex] = '%';
					newStringArr[newIndex + 1] = '2';
					newStringArr[newIndex + 2] = '0';

					oldIndex--;
					newIndex--;
				}
				else
				{
					newStringArr[newIndex--] = s[oldIndex--];
				}
			}

			return new string(newStringArr);
		
		}

		static void Main(string[] args)
		{
			string re55 = ReplaceSpacesWithCode("danas je lijep dan.");

			int[] arr = new int[] { 5, 2, 3, 8, 1 };
			InsertionSort(arr);

			int[] arr2 = new int[5] { 5, 2, 3, 8, 1 };
			BubbleSort(arr2);

			int[] arr3 = new int[] { 5, 2,3,8,1};
			SelectionSort(arr3);

			int[] arr4 = new int[] { 8, 5, 4, 7, 6, 1, 6, 3, 8, 12, 10 };
			QuickSort(arr4);

			int z = 55;

			//Graph graph = new Graph();

			//Node a = new Node('a'); graph.Nodes.Add(a);
			//Node b = new Node('b'); graph.Nodes.Add(b);
			//Node c = new Node('c'); graph.Nodes.Add(c);
			//Node d = new Node('d'); graph.Nodes.Add(d);
			//Node e = new Node('e'); graph.Nodes.Add(e);
			//Node f = new Node('f'); graph.Nodes.Add(f);
			//Node g = new Node('g'); graph.Nodes.Add(g);
			//Node h = new Node('h'); graph.Nodes.Add(h);
			//Node i = new Node('i'); graph.Nodes.Add(i);

			//a.AddAdjencyNode(e); a.AddAdjencyNode(f); a.AddAdjencyNode(g); a.AddAdjencyNode(i);
			//b.AddAdjencyNode(g);
			//c.AddAdjencyNode(h);
			//d.AddAdjencyNode(h);
			//e.AddAdjencyNode(a); e.AddAdjencyNode(f); e.AddAdjencyNode(i);
			//f.AddAdjencyNode(a); f.AddAdjencyNode(e); f.AddAdjencyNode(i);
			//g.AddAdjencyNode(a); g.AddAdjencyNode(b);
			//h.AddAdjencyNode(c); h.AddAdjencyNode(d);
			//i.AddAdjencyNode(a); i.AddAdjencyNode(e); i.AddAdjencyNode(f);

			//List<Edge> edges = graph.BFS();
			//foreach (Edge edge in edges)
			//{
			//  Console.WriteLine("{0}:{1}-{2}:{3}", edge.A.Value, edge.A.Tag, edge.B.Value, edge.B.Tag);
			//}

			Graph graph = new Graph();

			Node a = new Node('a'); graph.Nodes.Add(a);
			Node b = new Node('b'); graph.Nodes.Add(b);
			Node c = new Node('c'); graph.Nodes.Add(c);
			Node d = new Node('d'); graph.Nodes.Add(d);
			Node e = new Node('e'); graph.Nodes.Add(e);
			Node f = new Node('f'); graph.Nodes.Add(f);
			Node g = new Node('g'); graph.Nodes.Add(g);
			Node h = new Node('h'); graph.Nodes.Add(h);
			Node i = new Node('i'); graph.Nodes.Add(i);
			Node j = new Node('j'); graph.Nodes.Add(j);

			Edge e1 = new Edge(a, e, 1); graph.AddEdge(e1);
			Edge e2 = new Edge(a, h, 10); graph.AddEdge(e2);
			Edge e3 = new Edge(b, c, 2); graph.AddEdge(e3);
			Edge e4 = new Edge(d, a, 4); graph.AddEdge(e4);
			Edge e5 = new Edge(d, h, 1); graph.AddEdge(e5);
			Edge e6 = new Edge(e, f, 3); graph.AddEdge(e6);
			Edge e7 = new Edge(f, b, 1); graph.AddEdge(e7);
			Edge e8 = new Edge(f, c, 3); graph.AddEdge(e8);
			Edge e9 = new Edge(f, g, 7); graph.AddEdge(e9);
			Edge e10 = new Edge(f, i, 1); graph.AddEdge(e10);
			Edge e11 = new Edge(h, e, 5); graph.AddEdge(e11);
			Edge e12 = new Edge(h, i, 9); graph.AddEdge(e12);
			Edge e13 = new Edge(i, j, 2); graph.AddEdge(e13);
			Edge e14 = new Edge(j, g, 1); graph.AddEdge(e14);

			graph.Dijkstra(d);

			BSTree bsTree = new BSTree();
			bsTree.AddNode(15);
			bsTree.AddNode(5);
			bsTree.AddNode(1);
			bsTree.AddNode(8);
			bsTree.AddNode(25);
			bsTree.AddNode(20);
			bsTree.AddNode(41);
			bsTree.AddNode(36);

			bsTree.DeleteByCopying(15);
			bsTree.DeleteByCopying(1);
			bsTree.DeleteByCopying(5);
			bsTree.DeleteByCopying(25);

			bsTree.DeleteByMerging(15);
			bsTree.DeleteByMerging(1);
			bsTree.DeleteByMerging(5);
			bsTree.DeleteByMerging(25);

			int value = bsTree.Find(8).Value;
			TreeNode tn = bsTree.Find(111);

			bsTree.BFS();
			Console.WriteLine("--------------------------");

			bsTree.DFSPreorder();
			Console.WriteLine("--------------------------");

			bsTree.DFSInorder();
			Console.WriteLine("--------------------------");

			bsTree.DFSPostorder();
			Console.WriteLine("--------------------------");

			bsTree.DFSPreorderStack();

			int resa = 0;
		}
	}
}
