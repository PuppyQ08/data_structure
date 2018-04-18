#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

#include "graph.cpp"
bool recurNode(std::unordered_map<Node *, int>& mp , Node * node);
// TODO: Implement this function
bool hasCycles(Graph const & g) {
    int V = g.nodes.size();
    bool ret = false;
    //for each node in g
    for(int i = 0; i < V; i++) {
        std::unordered_map<Node*, int> mp;
        Node* node = g.nodes[i];
        ret = recurNode(mp, node);
        // Do something
        if(ret) return true;

    }

    return false;
}

bool recurNode(std::unordered_map<Node*,int> &mp, Node * node){
    mp[node];
    if(node->outgoingNeighbors.size()!=0){
    for(Node * ref : node->outgoingNeighbors){
         if(mp.find(ref) != mp.end()) return true;
         else
            return recurNode(mp, ref);
    }
  }
    return false;
}
//std::pair<K, V>*  table[];
//pair ** ntable = table;
//table =  new pair<Kv> * [size];
