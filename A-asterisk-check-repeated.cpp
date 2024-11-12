// A* algorithm with systematic checking for repeated states
#include <bits/stdc++.h>

using namespace std;

struct Node {
    int id;                  // Unique identifier for the node
    int g;                   // Cost from the start node to this node
    int h;                   // Heuristic estimate from this node to the goal
    int f;                   // Total estimated cost (f = g + h)
    Node* parent;            // Pointer to the parent node for path reconstruction

    // Constructor
    Node(int id, int g, int h, Node* parent = nullptr) : id(id), g(g), h(h), f(g + h), parent(parent) {}

    // Overload < operator for priority queue
    bool operator>(const Node& other) const {
        return f > other.f;
    }
};

// Function to calculate the heuristic (e.g., Euclidean distance)
int heuristic(int node, int goal) {
    // Example heuristic (change this according to your problem)
    return abs(goal - node); // Here we assume goal and node are integers for simplicity
}

// Function to reconstruct and print the path from start to goal
void reconstruct_path(Node* goalNode) {
    vector<int> path;
    for (Node* node = goalNode; node != nullptr; node = node->parent) {
        path.push_back(node->id);
    }
    reverse(path.begin(), path.end());
    cout << "Path: ";
    for (int n : path) {
        cout << n << " ";
    }
    cout << endl;
}

// A* Search Algorithm with repeated state checking
void AStar(int start, int goal, map<int, vector<pair<int, int>>>& graph) {
    priority_queue<Node, vector<Node>, greater<Node>> openSet;
    unordered_set<int> closedSet;

    // Start node with g = 0 and calculated heuristic h
    Node* startNode = new Node(start, 0, heuristic(start, goal));
    openSet.push(*startNode);

    while (!openSet.empty()) {
        // Get the node with the lowest f value
        Node current = openSet.top();
        openSet.pop();

        // Check if we have reached the goal
        if (current.id == goal) {
            cout << "Goal reached with cost: " << current.g << endl;
            reconstruct_path(&current);
            return;
        }

        // Add current node to closedSet
        closedSet.insert(current.id);

        // Explore neighbors
        for (auto& neighbor : graph[current.id]) {
            int neighborId = neighbor.first;
            int cost = neighbor.second;

            // Skip if the neighbor is already in closedSet (already visited)
            if (closedSet.find(neighborId) != closedSet.end()) continue;

            // Calculate g, h, and f values for the neighbor
            int g = current.g + cost;
            int h = heuristic(neighborId, goal);
            Node neighborNode(neighborId, g, h, new Node(current));

            // Push neighbor to openSet
            openSet.push(neighborNode);
        }
    }

    cout << "No path found to the goal." << endl;
}

int main() {
    // Example graph: adjacency list where each pair is (neighbor, cost)
    map<int, vector<pair<int, int>>> graph;
    graph[0] = {{1, 1}, {2, 4}};
    graph[1] = {{2, 2}, {3, 5}};
    graph[2] = {{3, 1}};
    graph[3] = {{4, 3}};
    graph[4] = {};

    int start = 0;
    int goal = 4;
    AStar(start, goal, graph);

    return 0;
}
