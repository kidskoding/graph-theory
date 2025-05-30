#ifndef GRAPH_H
#define GRAPH_H

#include <algorithm>
#include <tuple>
#include <vector>

template <typename T>
struct GraphNode {
    T data;
    std::vector<std::tuple<GraphNode<T>*, T>> neighbors;

    GraphNode(const T& data) : data(data) { }
};

template <typename T>
class Graph {
public:    
    std::vector<GraphNode<T>*> graph;

    ~Graph() {
        for(auto& node : graph) {
            delete node;
        }
    }

    void addNode(GraphNode<T>*& graphNode) {
        graph.push_back(graphNode);
    }

    void removeNode(GraphNode<T>*& graphNode) {
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

    void addEdge(GraphNode<T>*& a, GraphNode<T>*& b, T weight) {
        a->neighbors.push_back(std::make_tuple(b, weight));
        b->neighbors.push_back(std::make_tuple(a, weight));
    }

    void removeEdge(GraphNode<T>*& a, GraphNode<T>*& b) {
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
};

#endif //GRAPH_H
