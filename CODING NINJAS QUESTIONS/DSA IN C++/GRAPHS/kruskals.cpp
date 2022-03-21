#include <iostream>
#include <algorithm>
using namespace std;

class edge
{
public:
    int source;
    int dest;
    int weight;
};

int findparent(int v, int *parent)
{
    if (parent[v] == v)
    {
        return v;
    }
    return findparent(parent[v], parent);
}

bool compare(edge e1, edge e2)
{
    return e1.weight < e2.weight;
}

void kruskals(edge *input, int n, int e)
{
    sort(input, input + e, compare);

    edge *output = new edge[n - 1];

    int *parent = new int[n];
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }

    int count = 0;
    int i = 0;

    while (count != n - 1)
    {
        edge currentedge = input[i];

        int sourceparent = findparent(currentedge.source, parent);
        int destparent = findparent(currentedge.dest, parent);

        // check for union-cyclic method
        if (sourceparent != destparent)
        {
            output[count] = currentedge;
            count++;

            // update parent for union cyclic method
            parent[sourceparent] = destparent;
        }
        i++;
    }

    cout << endl;
    for (int i = 0; i < n - 1; i++)
    {
        if (output[i].source < output[i].dest)
        {
            cout << output[i].source << " " << output[i].dest << " " << output[i].weight << endl;
        }
        else
        {
            cout << output[i].dest << " " << output[i].source << " " << output[i].weight << endl;
        }
    }
}

int main()
{
    int n, e;
    cin >> n >> e;

    // not using adjancency matrix
    edge *input = new edge[e];

    for (int i = 0; i < e; i++)
    {
        int s, d, w;
        cin >> s >> d >> w;

        input[i].source = s;
        input[i].dest = d;
        input[i].weight = w;
    }

    kruskals(input, n, e);
}