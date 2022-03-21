#include <iostream>
#include <vector>
using namespace std;

void getDFS(int **edges, int n, int sv, bool *visited, int ev, vector<int> *path)
{
    visited[sv] = true;

    if (sv == ev)
    {
        path->push_back(sv);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i])
        {
            getDFS(edges, n, i, visited, ev, path);

            if (!path->empty())
            {
                path->push_back(sv);
                return;
            }
        }
    }
}

void getpathDFS(int **edges, int n, int sv, int ev, vector<int> *path)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    getDFS(edges, n, sv, visited, ev, path);

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

    int sv, ev;
    cin >> sv >> ev;
    vector<int> *path = new vector<int>;

    getpathDFS(edges, n, sv, ev, path);

    for (int i = 0; i < path->size(); i++)
    {
        cout << path->at(i) << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}