using NUnit.Framework;
using System;

using Part1.Common;
 
namespace Part1
{
    
    [TestFixture]
    class TreelibTest
    {
        [Test]
        public void BasicTest()
        {
            TreeNode myTree = TreeBuilder.SimpleTree();

            // TODO add array based testing
            TreeNodeIterator it = new TreeNodeIterator(myTree);
            it.Traverse((TreeNodeIterator.TreeNodeContext ctx) =>
            {
                Console.WriteLine(ctx.Node.val);                
            });

            TreeNodeIterator dfsIt = new TreeNodeIterator(myTree,0);
            dfsIt.Traverse((TreeNodeIterator.TreeNodeContext ctx) =>
            {
                Console.Write(ctx.Node.val);
            });
        }
    }
}
