#include <iostream>
#include <map>
#include <list>
#include <queue>

using namespace std;

class Graph {
    map <char, list<char>> adjList;

public:
    void addEdge(char v, char w) {
        adjList[v].push_back(w);
    }

    void BFS(char start, char goal) {
        map<char, bool> visited;
        queue<char> q;

        visited[start] = true;
        q.push(start);

        cout << "BFS traversal order: ";
        
        while (!q.empty()) {
            char node = q.front();
            q.pop();
            cout << node << " ";

            // If we reach the goal node, break the loop
            if (node == goal) {
                cout << "\nGoal node " << goal << " found!" << endl;
                return;
            }

            for (auto adjacent : adjList[node]) {
                if (!visited[adjacent]) {
                    visited[adjacent] = true;
                    q.push(adjacent);
                }
            }
        }

        cout << "\nGoal node " << goal << " not found in the graph." << endl;
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
    g.BFS(startNode, goalNode);

    return 0;
}
