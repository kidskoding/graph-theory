#include "graph.h"
#include "graph_node.h"

template<typename T>
void Graph<T>::addNode(std::shared_ptr<GraphNode<T>> node) {
    this->graph.insert(std::make_pair(node, std::unordered_set<std::tuple<std::shared_ptr<GraphNode<T>>, T>>()));
}

template<typename T>
void Graph<T>::removeNode(std::shared_ptr<GraphNode<T>> node) {
    this->graph.erase(this->graph.find(node));
}

template<typename T>
void Graph<T>::addEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b, std::shared_ptr<T> weight) {
    this->graph[a].insert(std::make_tuple(b, weight));
    this->graph[b].insert(std::make_tuple(a, weight));
}

template<typename T>
void Graph<T>::removeEdge(std::shared_ptr<GraphNode<T>> a, std::shared_ptr<GraphNode<T>> b) {
    auto neighborsA = this->graph[a];
    for(auto neighbor : neighborsA) {
        if(std::get<0>(neighbor) == b) {
            neighborsA.erase(neighbor);
            break;
        }
    }

    auto neighborsB = this->graph[b];
    for(auto neighbor : neighborsB) {
        if(std::get<0>(neighbor) == a) {
            neighborsB.erase(neighbor);
            break;
        }
    }
}
