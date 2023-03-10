#include <iostream>
#include <utility>
#include <stack>
#include <vector>
#include <list>
#include <unordered_set>

using namespace std;

// WARNING: This is O(n), not O(1) like it is for a vector/array
int& elementAt(list<int>& lList, int index) {
    int i = 0;
    for (int& element : lList) {
        if (i == index) {
            return element;
        }
        ++i;
    }
    throw out_of_range("index out of range");
}

class Digraph {
    private:
        using node = pair<int, list<int>>;
        vector<node> m_graph;

        // returns -1 if not found
        int indexOf(int node) const {
            for (int i = 0; i < m_graph.size(); ++i) {
                if (m_graph[i].first == node) {
                    return i;
                }
            }
            return -1;
        }

        // determine whether the given node is part of a cycle
        bool hasCycle(int start, unordered_set<int>& visited) const {
            int index = indexOf(start);
            if (index == -1) {
                return false;
            }

            visited.insert(start);
            for (int next : m_graph[index].second) {
                if (visited.find(next) != visited.end()) {
                    return true;
                }
                if (hasCycle(next, visited)) {
                    return true;
                }
            }
            return false;
        }

        bool hasCycle(int start) const {
            unordered_set<int> visited;
            return hasCycle(start, visited);
        }
    public:
        // true if it succeeds, false if it fails
        bool addEdge(int first, int second) {
            // find or add the first node
            int index = indexOf(first);
            if (index == -1) {
                index = m_graph.size();
                m_graph.emplace_back(first, list<int>());
            }

            // add the second node if it doesn't exist
            if (indexOf(second) == -1) {
                m_graph.emplace_back(second, list<int>());
            }

            m_graph[index].second.push_front(second);

            // ensure there's no cycle
            if (hasCycle(first)) {
                // oops
                m_graph[index].second.pop_front();
                return false;
            }
            return true;
        }
        void removeEdge(int first, int second) {
            int index = indexOf(first);
            if (index == -1) {
                // Nothing to do. The node doesn't exist, so the edge can't.
                return;
            }
            m_graph[index].second.remove(second);
        }
        list<int> topologicalSort() const {
            // gives us a list with `m_graph.size()` zeros
            list<int> initialList (m_graph.size(), 0);
            int counter = m_graph.size() - 1;

            // & here means capture initialList by reference instead of by value (by copy)
            auto helper = [&](int vertex) -> void {
                // ...
                // for (int & element : initialList) {
                //     element = 1;

                //     for (node w : m_graph) {
                        
                //     }
                // }

                elementAt(initialList, 0) = 1;

                // this also needs to still check adjacency list of v contains w
                for (node w : m_graph) {

                }
            };

            // int i = 0;
            for (int& element : initialList) {
                // ++i;
                // if (i == 2) {
                //     element = 1;
                // }
                // if (element == 0) {

                // }
            }
        }
};
