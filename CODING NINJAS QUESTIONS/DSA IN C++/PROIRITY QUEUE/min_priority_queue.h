#include <iostream>
using namespace std;
#include <vector>

class priorityqueue
{
    vector<int> pq;

public:
    priorityqueue()
    {
    }

    bool isempty()
    {
        return pq.size() == 0;
    }

    int getsize()
    {
        return pq.size();
    }

    int getmin()
    {
        if (isempty())
            return 0; // priority queue is empty
        else
            return pq.at(0);
    }

    void insert(int element)
    {
        pq.push_back(element);

        int childindex = pq.size() - 1;

        while (childindex > 0)
        {
            int parentindex = (childindex - 1) / 2;
            if (pq[childindex] < pq[parentindex])
            {
                int temp = pq[childindex];
                pq[childindex] = pq[parentindex];
                pq[parentindex] = temp;
            }
            else
            {
                break;
            }

            childindex = parentindex;
        }
    }

    int removemin() // down-heapify
    {
        if (isempty())
        {
            return 0; // priority queue is empty
        }

        int ans = pq.at(0);
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int lci = (2 * parentindex) + 1;
        int rci = (2 * parentindex) + 2;

        while (lci < pq.size())
        {
            int minindex = parentindex;

            if (pq[minindex] > pq[lci])
            {
                minindex = lci;
            }
            if (rci < pq.size() && pq[minindex] > pq[rci])
            {
                minindex = rci;
            }

            if (parentindex != minindex)
            {
                int temp = pq[parentindex];
                pq[parentindex] = pq[minindex];
                pq[minindex] = temp;
            }
            else
            {
                break;
            }

            parentindex = minindex;
            lci = (2 * parentindex) + 1;
            rci = (2 * parentindex) + 2;
        }

        return ans;
    }
};