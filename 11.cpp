#include <iostream>
#include <vector>
using namespace std;
const int MaxCost = 999;
void primsMST(int n, vector<vector<int>>& cost)
{
    vector<int> visit(n + 1, 0);
    int mincost = 0;

    int s;
    cout << "Enter Starting Vertex (1 to " << n << "): ";
    cin >> s;
    visit[s] = 1;

    cout << "Selected Edges in MST:" << endl;
    for (int k = 1; k < n; ++k)
    {
        int min = MaxCost;
        int row, col;

        for (int i = 1; i <= n; ++i)
        {
            if (visit[i] == 1) {
                for (int j = 1; j <= n; ++j)
                {
                    if (visit[j] == 0 && cost[i][j] != -1 && min > cost[i][j])
                    {
                        min = cost[i][j];
                        row = i;
                        col = j;
                    }
                }
            }
        }

        cout << "Edge: " << row << " - " << col << endl;
        mincost += min;
        visit[col] = 1;
        cost[row][col] = -1;
        cost[col][row] = -1;
    }

    cout << "Total Min Cost: " << mincost << endl;
}

int main()
{
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    string cities[n];

    for (int i = 0; i < n; i++)
    {
        cout << "Enter city " << i + 1 << ": ";
        cin >> cities[i];
    }

    vector<vector<int>> cost(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++)
        {
            char op;
            cout << "Is there an edge between " << cities[i - 1] << " and " << cities[j - 1] << " (y/n)? ";
            cin >> op;
            if (op == 'y' || op == 'Y')
            {
                cout << "Enter time: ";
                cin >> cost[i][j];
                cost[j][i] = cost[i][j];
            }
            else {
                cost[i][j] = cost[j][i] = -1;
            }
        }
    }

    primsMST(n, cost);

    return 0;
}
