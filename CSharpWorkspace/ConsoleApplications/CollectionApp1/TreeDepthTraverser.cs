using System;
using System.Collections.Generic;

namespace TreeDepthTraverser
{
    class TreeNode
    {
        public int Data;
        public TreeNode LeftNode;
        public TreeNode RightNode;
    }

    class TreeNodeBuilder
    {
        public static TreeNode BuildTreeNodes(int numberOfNodes, int currentCount = 0)
        {
            TreeNode nd = new TreeNode
            {
                Data = currentCount,
                LeftNode = null,
                RightNode = null
            };

            if (currentCount < numberOfNodes)
            {
                nd.LeftNode = BuildTreeNodes(numberOfNodes, currentCount + 1);
                nd.RightNode = BuildTreeNodes(numberOfNodes, currentCount + 2);
            }

            return nd;
        }
    }

    class TreeTravrser
    {
        private TreeNode _root;
        private int _depth;

        public TreeTravrser(TreeNode n)
        {
            _root = n;
            _depth = -1;
        }

        private int CalculateDepth(TreeNode nd)
        {
            if (nd == null)
                return 0;

            int leftDepth = CalculateDepth(nd.LeftNode);
            int rightDepth = CalculateDepth(nd.RightNode);

            return 1 + Math.Max(leftDepth, rightDepth);
        }

        public int Depth
        {
            get
            {
                if (_depth == -1)
                    _depth = CalculateDepth(_root);

                return _depth;
            }
        }

        private List<int> GetResultsOnDepth(TreeNode nd, int d, int currentDepth = 1)
        {
            if (currentDepth == d)
            {
                return new List<int> { nd.Data };
            };

            var leftSide = GetResultsOnDepth(nd.LeftNode, d, currentDepth + 1);
            var rightSide = GetResultsOnDepth(nd.RightNode, d, currentDepth + 1);
            leftSide.AddRange(rightSide);

            // This is the resultant item
            return leftSide;
        }

        public List<int> GetNodesAtDepth(int depth)
        {
            if (depth > this.Depth)
                throw new Exception("Bad argument");

            return GetResultsOnDepth(_root, depth);
        }
    }
}
