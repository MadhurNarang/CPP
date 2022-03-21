#include <iostream>
#include <queue>
using namespace std;

int checkDFS(int **edges, int n, int sv, bool *visited, int ev)
{
    visited[sv] = true;

    int ans = 0;
    if (sv == ev)
    {
        return 1;
    }

    for (int i = 0; i < n; i++)
    {
        if (i == sv)
        {
            continue;
        }
        if (edges[sv][i] == 1 && !visited[i])
        {
            return ans || checkDFS(edges, n, i, visited, ev);
        }
    }
    return ans;
}

void haspathDFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << checkDFS(edges, n, sv, visited, ev) << endl;

    delete[] visited;
}

int checkBFS(int **edges, int n, int sv, bool *visited, int ev)
{
    queue<int> pendingvertices;
    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
        if (currentvertex == ev)
        {
            return 1;
        }
        pendingvertices.pop();

        for (int i = 0; i < n; i++)
        {
            if (i == currentvertex)
            {
                continue;
            }
            if (edges[currentvertex][i] == 1 && !visited[i])
            {
                pendingvertices.push(i);
                visited[i] = true;
            }
        }
    }

    return 0;
}

void haspathBFS(int **edges, int n, int sv, int ev)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    cout << checkBFS(edges, n, sv, visited, ev) << endl;

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

    haspathDFS(edges, n, sv, ev);

    // haspathBFS(edges, n, sv, ev);

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
}