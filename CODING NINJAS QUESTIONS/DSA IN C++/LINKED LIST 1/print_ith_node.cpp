#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

node *takeinput()
{
    int data;
    cin >> data;
    node *head = NULL, *tail = NULL;
    while (data != -1)
    {
        node *n = new node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = n;
        }
        cin >> data;
    }
    return head;
}

void print_i_node(node *head, int i)
{
    int len = 0;
    while (head != NULL)
    {
        if (len == i)
        {
            cout << head->data;
            return;
        }
        head = head->next;
        len++;
    }
    return;
}

int main()
{
    int n, i;
    cin >> n;

    while (n > 0)
    {
        node *head = takeinput();
        cin >> i;
        print_i_node(head, i);
        delete head;
        n--;
    }
}