using System;

namespace CollectionApp1
{
    class Program
    {
        static void Main(string[] args)
        {
            int depth = 6;
            var rootNode = TreeDepthTraverser.TreeNodeBuilder.BuildTreeNodes(depth);
            TreeDepthTraverser.TreeTravrser trvs = new TreeDepthTraverser.TreeTravrser(rootNode);
            Console.WriteLine("Depth:{0}", trvs.Depth - 1);

            for (int i = depth - 1; i >= 0; i--)
            {
                var itemsAtLevel = trvs.GetNodesAtDepth(i);
                foreach (var d in itemsAtLevel)
                    Console.Write("{0} ", d);
                Console.WriteLine();
            }
        }
    }
}
