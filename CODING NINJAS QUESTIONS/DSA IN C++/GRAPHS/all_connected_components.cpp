#include <iostream>
#include <vector>
using namespace std;

void DFS(int **edges, int n, int sv, bool *visited, vector<int> *smallvector)
{
    visited[sv] = true;
    smallvector->push_back(sv);

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i])
        {
            DFS(edges, n, i, visited, smallvector);
        }
    }
}

void connectedDFS(int **edges, int n, vector<vector<int> *> *ans)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    vector<int> *smallvector;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            smallvector = new vector<int>;
            DFS(edges, n, i, visited, smallvector);
            ans->push_back(smallvector);
        }
    }

    delete[] visited;
}

int main()
{
    int n, e;
    cin >> n >> e;

    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<vector<int> *> *ans = new vector<vector<int> *>;

    connectedDFS(edges, n, ans);

    for (int i = 0; i < ans->size(); i++)
    {
        for (int j = 0; j < (ans->at(i))->size(); j++)
        {
            cout << (ans->at(i))->at(j) << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}