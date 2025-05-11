#include <iostream>
#include <string>
#include <queue>
#include <stack>

using namespace std;

const int MAX_CITIES = 10;

int route[MAX_CITIES][MAX_CITIES] = {0};
int nc;
string ap[MAX_CITIES];

void Insert() {
    cout << "\nEnter no. of cities: ";
    cin >> nc;

    for (int i = 0; i < nc; i++) {
        cout << "Enter City " << i + 1 << " : ";
        cin >> ap[i];
    }

    for (int i = 0; i < nc; i++) {
        for (int j = i + 1; j < nc; j++) {
            cout << "Enter distance between " << ap[i] << " and " << ap[j] << " : ";
            cin >> route[i][j];
            route[j][i] = route[i][j];
        }
    }
}

void Display() {
    cout << "\nDisplay cities with airport code: " << endl;

    for (int i = 0; i < nc; i++) {
        cout << "City " << i + 1 << " -> " << ap[i] << endl;
    }
}

void DisplayGraph() {
    cout << "\nAdjacency Matrix representation of graph: " << endl;

    for (int i = 0; i < nc; i++) {
        for (int j = 0; j < nc; j++) {
            cout << route[i][j] << "\t";
        }
        cout << endl;
    }
}

void DFSUtil(int current, bool visited[]) {
    visited[current] = true;
    for (int i = 0; i < nc; i++) {
        if (route[current][i] != 0 && !visited[i]) {
            DFSUtil(i, visited);
        }
    }
}

bool IsConnected() {
    bool visited[MAX_CITIES] = {false};
    DFSUtil(0, visited);
    for (int i = 0; i < nc; i++) {
        if (!visited[i]) {
            return false;
        }
    }
    return true;
}

void DFS(int start) {
    bool visited[MAX_CITIES] = {false};
    stack<int> s;

    cout << "\nDFS Traversal: ";

    s.push(start);
    while (!s.empty()) {
        int current = s.top();
        s.pop();
        if (!visited[current]) {
            cout << ap[current] << " ";
            visited[current] = true;

            for (int i = 0; i < nc; i++) {
                if (route[current][i] != 0 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }

    cout << endl;
}

void BFS(int start) {
    bool visited[MAX_CITIES] = {false};
    queue<int> q;
    cout << "\nBFS Traversal: ";
    q.push(start);
   
    while (!q.empty()) {
        int current = q.front();
        q.pop();

        if (!visited[current]) {
            cout << ap[current] << " ";
            visited[current] = true;

            for (int i = 0; i < nc; i++) {
                if (route[current][i] != 0 && !visited[i]) {
                    q.push(i);
                }
            }
        }
    }
    cout << endl;
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
   
    if (IsConnected()) {
        cout << "\nThe graph is connected." << endl;
    } else {
        cout << "\nThe graph is not connected." << endl;
    }

    cout << "\n\tExiting...\n";

    return 0;
}
