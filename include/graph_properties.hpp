#ifndef GRAPH_PROPERTIES_HPP
#define GRAPH_PROPERTIES_HPP

#include "graph.h"
#include <vector>
#include <map>

namespace graph_properties {
    // --- Connectivity ---

    // Returns the number of connected components in an undirected graph.
    // Concept: A connected component is a maximal set of nodes where every node is reachable from every other.
    // Strategy: Run DFS/BFS from each unvisited node; each new traversal start = one new component.
    template <typename T>
    int connected_components(Graph<T>& graph) {
        // TODO: implement
        return 0;
    }

    // Returns true if all nodes in the graph are reachable from a single starting node.
    // Concept: A connected graph has exactly one connected component.
    // Strategy: Run DFS/BFS from any node; if the visited set equals all nodes, the graph is connected.
    template <typename T>
    bool is_connected(Graph<T>& graph) {
        // TODO: implement
        return false;
    }

    // --- Cycle Detection ---

    // Returns true if the undirected graph contains at least one cycle.
    // Concept: A cycle exists when a path leads back to an already-visited node (excluding the direct parent).
    // Strategy: DFS — track the parent of each node; if a neighbor is visited and isn't the parent, a cycle exists.
    template <typename T>
    bool has_cycle_undirected(Graph<T>& graph) {
        // TODO: implement
        return false;
    }

    // Returns true if the directed graph contains at least one cycle.
    // Concept: In a directed graph, a cycle is detected by a "back edge" — an edge pointing to an ancestor in the DFS tree.
    // Strategy: DFS with a "currently in stack" set; if you visit a node already in the stack, a cycle exists.
    template <typename T>
    bool has_cycle_directed(Graph<T>& graph) {
        // TODO: implement
        return false;
    }

    // --- Topological Sort ---

    // Returns nodes in topological order (only valid for Directed Acyclic Graphs).
    // Concept: Topological order means for every directed edge u->v, u appears before v in the result.
    // Strategy: DFS — push a node onto the result AFTER all its descendants are fully processed (post-order).
    //           Reverse the result at the end. Returns empty vector if the graph has a cycle.
    template <typename T>
    std::vector<GraphNode<T>*> topological_sort_dfs(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Returns nodes in topological order using Kahn's algorithm.
    // Concept: Nodes with no incoming edges have no dependencies — they can always come first.
    // Strategy: Build an in-degree map; repeatedly enqueue nodes with in-degree 0 and decrement
    //           neighbors' in-degrees. If not all nodes are processed, a cycle exists.
    template <typename T>
    std::vector<GraphNode<T>*> topological_sort_kahns(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // --- Bipartite Check ---

    // Returns true if the graph is bipartite (nodes can be split into 2 groups with no edges within a group).
    // Concept: A graph is bipartite if and only if it contains no odd-length cycles. Equivalent to being 2-colorable.
    // Strategy: BFS/DFS — assign alternating colors (0/1) to nodes. If two adjacent nodes share a color, not bipartite.
    //           Fills `coloring` map with each node's assigned group (0 or 1) if bipartite.
    template <typename T>
    bool is_bipartite(Graph<T>& graph, std::map<GraphNode<T>*, int>& coloring) {
        // TODO: implement
        return false;
    }

    // --- Bridges and Articulation Points ---

    // Finds all bridges — edges whose removal increases the number of connected components.
    // Concept: A bridge is an edge not part of any cycle; removing it splits the graph.
    // Strategy: DFS tracking each node's discovery time (disc) and lowest reachable time (low).
    //           Edge (u,v) is a bridge if low[v] > disc[u] — meaning v cannot reach u without this edge.
    template <typename T>
    std::vector<std::pair<GraphNode<T>*, GraphNode<T>*>> find_bridges(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Finds all articulation points — nodes whose removal increases the number of connected components.
    // Concept: An articulation point is a node that acts as the only connection between parts of the graph.
    // Strategy: Same DFS disc/low approach as bridge finding.
    //           Node u is an AP if: it's the DFS root with 2+ children, OR it has a child v where low[v] >= disc[u].
    template <typename T>
    std::vector<GraphNode<T>*> find_articulation_points(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // --- Strongly Connected Components (Directed Graphs) ---

    // Finds all SCCs using Kosaraju's algorithm (two-pass DFS).
    // Concept: An SCC is a maximal set of nodes where every node is reachable from every other via directed edges.
    // Strategy: 1) DFS on original graph — push each node to a stack in finish order.
    //           2) Build the transposed graph (reverse all edges).
    //           3) DFS on the transposed graph in stack order — each DFS tree is one SCC.
    template <typename T>
    std::vector<std::vector<GraphNode<T>*>> kosaraju(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

    // Finds all SCCs using Tarjan's algorithm (single-pass DFS).
    // Concept: Same SCC definition as Kosaraju's, but found in one pass using a node stack and low-link values.
    // Strategy: DFS — each node gets a discovery time (disc) and a low-link value (lowest disc reachable).
    //           When disc[u] == low[u], u is the root of an SCC; pop the stack until u is removed.
    template <typename T>
    std::vector<std::vector<GraphNode<T>*>> tarjan(Graph<T>& graph) {
        // TODO: implement
        return {};
    }

} // namespace graph_properties

#endif // GRAPH_PROPERTIES_HPP
