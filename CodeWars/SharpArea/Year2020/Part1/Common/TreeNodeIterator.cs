using System.Collections;

namespace Part1.Common
{
    public class TreeNodeIterator
    {
        private TreeNode Root;
        private int Mode;       // 1 means BFS 0 means DFS

        public delegate void OnNodeVisitedCallback(TreeNodeContext nd);

        public class TreeNodeContext
        {
            public readonly TreeNode Node;
            public readonly int Depth;
            public readonly int Position;

            public TreeNodeContext(TreeNode nd, int d, int p)
            {
                Node = nd;
                Depth = d;
                Position = p;
            }
        }

        public TreeNodeIterator(TreeNode root, int mode)
        {
            Root = root;
            Mode = mode;
        }

        public TreeNodeIterator(TreeNode root)
        {
            Root = root;
            Mode = 1;
        }

        private void DoBreathFirst(OnNodeVisitedCallback callback)
        {
            Queue visitQueue = new Queue();
            visitQueue.Enqueue(new TreeNodeContext(Root, 0, 1));

            // Traver till the queue is empty
            while (visitQueue.Count != 0)
            {
                TreeNodeContext ctx = (TreeNodeContext)visitQueue.Dequeue();
                var nd = ctx.Node;

                if (nd.left != null)
                {
                    TreeNodeContext leftCtx = new TreeNodeContext(nd.left, ctx.Depth + 1, ctx.Position);
                    visitQueue.Enqueue(leftCtx);
                }

                if (nd.right != null)
                {
                    TreeNodeContext rightCtx = new TreeNodeContext(nd.right, ctx.Depth + 1, ctx.Position + 1);
                    visitQueue.Enqueue(rightCtx);
                }
                
            }
        }

        private void DoDepthFirst(OnNodeVisitedCallback visit)
        {
            Stack visitStack = new Stack();
            visitStack.Push(new TreeNodeContext(Root, 0, 1));

            while( visitStack.Count != 0 )
            {
                TreeNodeContext ctx = (TreeNodeContext) visitStack.Pop();
                var nd = ctx.Node;
                var newDepth = ctx.Depth + 1;

                if (nd.left != null) visitStack.Push(new TreeNodeContext(nd.left, newDepth, ctx.Position));
                if (nd.right != null) visitStack.Push(new TreeNodeContext(nd.right, newDepth, ctx.Position + 1));

                visit(ctx);
            }
        }

        public void Traverse(OnNodeVisitedCallback visit)
        {
            if (Mode == 1)
            {
                DoBreathFirst(visit);
            }
            else
            {
                DoDepthFirst(visit);
            }
        }
    }
}
