#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;

const int MAX_CITIES = 10;

vector<string> ap(MAX_CITIES);
vector<vector<int>> adjList(MAX_CITIES);

void Insert() {
    int nc;
    cout << "\nEnter no. of cities: ";
    cin >> nc;

    for (int i = 0; i < nc; i++) {
        cout << "Enter City " << i + 1 << " : ";
        cin >> ap[i];
    }

    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            int distance;
            cout << "Enter distance between " << ap[i] << " and " << ap[j] << " : ";
            cin >> distance;
            if (distance != 0) {
                adjList[i].push_back(j);
                adjList[j].push_back(i); // Undirected graph
            }
        }
    }
}

void Display() {
    cout << "\nDisplay cities with airport code: " << endl;

    for (int i = 0; i < ap.size(); i++) {
        cout << "City " << i + 1 << " -> " << ap[i] << endl;
    }
}

void DisplayGraph() {
    cout << "\nAdjacency List representation of graph: " << endl;

    for (int i = 0; i < adjList.size(); i++) {
        cout << ap[i] << " -> ";
        for (int j : adjList[i]) {
            cout << ap[j] << " ";
        }
        cout << endl;
    }
}

void DFSUtil(int v, vector<bool>& visited) {
    visited[v] = true;
    cout << ap[v] << " ";

    for (int u : adjList[v]) {
        if (!visited[u]) {
            DFSUtil(u, visited);
        }
    }
}

void DFS(int start) {
    cout << "\nDFS Traversal: ";
    vector<bool> visited(MAX_CITIES, false);
    DFSUtil(start, visited);
    cout << endl;
}

void BFS(int start) {
    cout << "\nBFS Traversal: ";
    vector<bool> visited(MAX_CITIES, false);
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();
        cout << ap[v] << " ";

        for (int u : adjList[v]) {
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << endl;
}

bool isConnected() {
    vector<bool> visited(MAX_CITIES, false);
    DFSUtil(0, visited);

    return all_of(visited.begin(), visited.end(), [](bool v) { return v; });
}

int main() {
    Insert();
    Display();
    DisplayGraph();
   
    int start;
    cout << "\nEnter the starting vertex for traversal: ";
    cin >> start;
    BFS(start);
    DFS(start);
   
    if (isConnected()) {
        cout << "\nThe graph is connected.\n";
    } else {
        cout << "\nThe graph is not connected.\n";
    }

    cout << "\n\tExiting...\n";

    return 0;
}
