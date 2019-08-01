using System;

namespace CollectionApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Building a tree with 10 nodes");

            var rootNode = TreeDepthTraverser.TreeNodeBuilder.BuildTreeNodes(5);
            TreeDepthTraverser.TreeTravrser trvs = new TreeDepthTraverser.TreeTravrser(rootNode);
            Console.WriteLine("Depth:{0}", trvs.Depth);
            int lev = int.Parse(Console.ReadLine());
            var itemsAtLevel = trvs.GetNodesAtDepth(lev);
            foreach (var d in itemsAtLevel)
                Console.Write("{0} ", d);
            Console.WriteLine();
        }
    }
}
