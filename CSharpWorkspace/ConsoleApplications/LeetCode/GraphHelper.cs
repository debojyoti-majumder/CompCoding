using System.Collections.Generic;

namespace LeetCode
{
    class GraphNode
    {
        public int NodeId;
        public List<int> Links;

        public GraphNode(int id)
        {
            NodeId = id;
            Links = new List<int>();
        }
    }

    class GraphHelper
    {
        private readonly int _nodeCount;
        Dictionary<int, GraphNode> _nodes;

        public GraphHelper(int nodeCount)
        {
            _nodeCount = nodeCount;
            _nodes = new Dictionary<int, GraphNode>();

            for( int i=0; i<nodeCount; i++)
            {
                // Id are not zero index based
                _nodes.Add(i+1, new GraphNode(i+1));
            }
        }

        public void AddUnidirectionEdge(int sourceId, int destinationId)
        {
            // Not checking if the destination node is present or not
            var sourceNode = _nodes[sourceId];
            sourceNode.Links.Add(destinationId);
        }
    }
}
