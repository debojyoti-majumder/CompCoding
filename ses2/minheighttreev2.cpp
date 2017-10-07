// Problem URL:https://leetcode.com/problems/minimum-height-trees

#include <vector>
#include <iostream>
#include <map>

using namespace std;

class Solution {
private:
    map<int, vector<int>>   _spanningTree;

    void removeNeibour(int node, int item) {
        auto it = _spanningTree[node].begin();

        while( it != end(_spanningTree[node]) ) {
            if( *it == item )
                break;
            else
                ++it;
        }

        _spanningTree[node].erase(it);
    }
public:

    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        for(int i=0; i<n; i++) {
            auto v = vector<int>();
            _spanningTree.insert(make_pair(i,v));
        }

        for( auto edge : edges ) {
            _spanningTree[edge.first].push_back(edge.second);
            _spanningTree[edge.second].push_back(edge.first);
        }

        bool leaf_found = true;
        while( leaf_found ) {
            leaf_found = false;
            vector<int> vec_indexes;

            for( auto nd: _spanningTree ) {
                if(nd.second.size() <= 1 ) {
                    leaf_found = true;
                    vec_indexes.push_back(nd.first);
                }
            }

            // Nothing more to prune
            if( _spanningTree.size() == vec_indexes.size() )
                break;

            for( auto v: vec_indexes ) {
                auto it = _spanningTree.find(v);
                removeNeibour(it->second[0],it->first);
                _spanningTree.erase(it);
            }
        }

        vector<int> ret_val;
        for(auto e: _spanningTree)
            ret_val.push_back(e.first);

        return ret_val;
    }
};
