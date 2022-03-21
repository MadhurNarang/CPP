#include <iostream>
#include <queue>
#include <stack>
#include <unordered_map>
using namespace std;

void pathBFS(int **edges, int n, int sv, bool *visited, int ev, vector<int> *path)
{
    queue<int> pendingvertices;
    unordered_map<int, int> ansmap;
    int found = 0;

    pendingvertices.push(sv);
    visited[sv] = true;
    while (!pendingvertices.empty())
    {
        int currentvertex = pendingvertices.front();
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

                ansmap[i] = currentvertex;
                if (i == ev)
                {
                    found = 1;
                    break;
                }
            }
        }
    }

    if (found == 1)
    {
        path->push_back(ev);
        auto p = ansmap.find(ev);
        while (p->second != sv)
        {
            path->push_back(p->second);
            p = ansmap.find(p->second);
        }
        path->push_back(sv);
    }
}

void getpathBFS(int **edges, int n, int sv, int ev, vector<int> *path)
{
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }

    pathBFS(edges, n, sv, visited, ev, path);

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

    getpathBFS(edges, n, sv, ev, path);

    for (int i = 0; i < path->size(); i++)
    {
        cout << path->at(i) << " ";
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete path;
}