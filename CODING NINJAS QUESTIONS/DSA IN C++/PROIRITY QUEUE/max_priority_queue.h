#include <iostream>
#include <climits>
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

    int getmax()
    {
        if (isempty())
            return INT_MIN; // priority queue is empty
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
            if (pq[childindex] > pq[parentindex])
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

    int removemax() // down-heapify
    {
        if (isempty())
        {
            return INT_MIN; // priority queue is empty
        }

        int ans = pq.at(0);
        pq[0] = pq[pq.size() - 1];
        pq.pop_back();

        int parentindex = 0;
        int lci = (2 * parentindex) + 1;
        int rci = (2 * parentindex) + 2;

        while (lci < pq.size())
        {
            int maxindex = parentindex;

            if (pq[maxindex] < pq[lci])
            {
                maxindex = lci;
            }
            if (rci < pq.size() && pq[maxindex] < pq[rci])
            {
                maxindex = rci;
            }

            if (parentindex != maxindex)
            {
                int temp = pq[parentindex];
                pq[parentindex] = pq[maxindex];
                pq[maxindex] = temp;
            }
            else
            {
                break;
            }

            parentindex = maxindex;
            lci = (2 * parentindex) + 1;
            rci = (2 * parentindex) + 2;
        }

        return ans;
    }
};