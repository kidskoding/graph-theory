#include "graph_utilities.h"

template<typename T>
bool GraphUtilities<T>::isIsomorphic(Graph<T>& a, Graph<T>& b) {
    if(a.graph.size() != b.graph.size()) {
        return false;
    }

    std::unordered_map<std::shared_ptr<GraphNode<T>>, std::shared_ptr<GraphNode<T>>> nodeMap;
    for(auto node : a.graph) {
        nodeMap.insert(std::make_pair(node.first, nullptr));
    }

    return true;
}
