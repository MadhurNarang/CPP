#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class triplet
{
public:
    int number;
    int arrayindex;
    int elementindex;

    triplet(int number, int arrayindex, int elementindex)
    {
        this->number = number;
        this->arrayindex = arrayindex;
        this->elementindex = elementindex;
    }
};

class compare
{
public:
    bool operator()(const triplet &a, const triplet &b)
    {
        return a.number > b.number;
    }
};

vector<int> *merge_k_sorted_arrays(int k, int *n, int **aarr)
{
    priority_queue<triplet, vector<triplet>, compare> pq;

    for (int i = 0; i < k; i++)
    {
        triplet k = triplet(aarr[i][0], i, 0);
        pq.push(k);
    }

    vector<int> *ans = new vector<int>;

    while (!pq.empty())
    {
        triplet anstriplet = pq.top();
        pq.pop();
        ans->push_back(anstriplet.number);
        if (anstriplet.elementindex < n[anstriplet.arrayindex] - 1)
        {
            anstriplet.number = aarr[anstriplet.arrayindex][anstriplet.elementindex + 1];
            anstriplet.elementindex += 1;
            pq.push(anstriplet);
        }
    }

    return ans;
}

int main()
{
    int k;
    cout << "ENTER K : ";
    cin >> k;
    int *n = new int[k];
    int **aarr = new int *[k];
    for (int i = 0; i < k; i++)
    {
        cout << "ENTER N : ";
        cin >> n[i];
        int *arr = new int[n[i]];
        for (int j = 0; j < n[i]; j++)
        {
            cin >> arr[j];
        }
        aarr[i] = arr;
    }

    vector<int> *ans = merge_k_sorted_arrays(k, n, aarr);

    for (int i = 0; i < ans->size(); i++)
    {
        cout << ans->at(i) << " ";
    }
}