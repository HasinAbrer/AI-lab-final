#include <iostream>
#include <map>
#include <list>

using namespace std;

class Graph {
    map<char, list<char>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v].push_back(w);
    }

    bool DFSUtil(char node, char goal, map<char, bool> &visited) {
        visited[node] = true;
        cout << node << " ";

        // If we reach the goal node, return true
        if (node == goal) {
            cout << "\nGoal node " << goal << " found!" << endl;
            return true;
        }

        for (auto adjacent : adjList[node]) {
            if (!visited[adjacent]) {
                if (DFSUtil(adjacent, goal, visited)) {
                    return true;  // Stop traversal once goal is found
                }
            }
        }
        return false;
    }

    void DFS(char start, char goal) {
        map<char, bool> visited;
        cout << "DFS traversal order: ";
        if (!DFSUtil(start, goal, visited)) {
            cout << "\nGoal node " << goal << " not found in the graph." << endl;
        }
    }
};

int main() {
    Graph g;

    // Adding edges based on the given tree structure
    g.addEdge('A', 'B');
    g.addEdge('A', 'C');
    g.addEdge('A', 'D');
    g.addEdge('A', 'E');
    g.addEdge('B', 'F');
    g.addEdge('B', 'G');
    g.addEdge('C', 'H');
    g.addEdge('D', 'I');
    g.addEdge('D', 'J');
    g.addEdge('G', 'K');
    g.addEdge('G', 'L');
    g.addEdge('I', 'M');
    g.addEdge('J', 'N');
    g.addEdge('L', 'O');

    char startNode = 'A';
    char goalNode = 'O';
    g.DFS(startNode, goalNode);

    return 0;
}
