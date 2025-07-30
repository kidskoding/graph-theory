#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "graph.h"
#include <algorithm>
#include <tuple>
#include <vector>

template <typename T>
Graph<T>::~Graph() {
    for(auto& node : graph) {
        delete node;
    }
}

template <typename T>
void Graph<T>::addNode(GraphNode<T>* graphNode) {
    graph.push_back(graphNode);
}

template <typename T>
void Graph<T>::removeNode(GraphNode<T>*& graphNode) {
    graph.erase(
        std::remove(graph.begin(), graph.end(), graphNode),
        graph.end()
    );

    for(GraphNode<T>*& node : graph) {
        node->neighbors.erase(
            std::remove_if(node->neighbors.begin(), node->neighbors.end(), 
                [&graphNode](const auto& tup) {
                    GraphNode<T>*& ptr = std::get<0>(tup);
                    return ptr == graphNode; 
                }),
            node->neighbors.end()
        );
    }
}

template <typename T>
void Graph<T>::addEdge(GraphNode<T>*& a, GraphNode<T>*& b, T weight) {
    a->neighbors.push_back(std::make_tuple(b, weight));
    b->neighbors.push_back(std::make_tuple(a, weight));
}

template <typename T>
void Graph<T>::removeEdge(GraphNode<T>*& a, GraphNode<T>*& b) {
    a->neighbors.erase(
        std::remove_if(a->neighbors.begin(), a->neighbors.end(),
            [&b](const auto& tup) {
                GraphNode<T>* ptr = std::get<0>(tup);
                return ptr == b;
            }),
        a->neighbors.end()
    );

    b->neighbors.erase(
        std::remove_if(b->neighbors.begin(), b->neighbors.end(), 
            [&a](const auto& tup) {
                GraphNode<T>*& ptr = std::get<0>(tup);
                return ptr == a;
            }),
        b->neighbors.end()
    ); 
}

#endif //GRAPH_HPP
