#include <map>
#include <vector>
#include <set>

#include "gtest/gtest.h"
#include "gmock/gmock.h"

namespace GraphLoop {
    using namespace std;
    using namespace testing;

    class GraphNode {
        private:
            int id;
            set<int> links;
        
        public:
            explicit GraphNode(int n) : id(n) {}
            GraphNode() :id{-1} {}

            void addLink(const GraphNode& nd) {
                if( nd.id >= 0 )
                    links.insert(nd.id);
            }
    };

    class Graph {
        private:
            map<int, GraphNode> _nodes;
            
            GraphNode getNode(int nodeId) {
                auto it = _nodes.find(nodeId);
                if( it == _nodes.end() ) {
                    _nodes.insert(make_pair(nodeId, GraphNode{nodeId}));
                }

                return _nodes[nodeId];
            }

        public:
            void addEdge(int nodeIdSource, int nodeIdDest) {
                auto& nodeSource { getNode(nodeIdSource) };
                auto& nodeDest { getNode(nodeIdDest) };

                nodeSource.addLink(nodeDest);
            }

            bool hasLoop() {
                return false;
            }
    };

    GTEST_TEST(GraphLoop, basicTest) {
        Graph g;
        
        g.addEdge(0,1);
        g.addEdge(1,2);
        g.addEdge(2,3);

        ASSERT_EQ(g.hasLoop(), false);

        g.addEdge(3,0);
        ASSERT_EQ(g.hasLoop(), true);
    }
};