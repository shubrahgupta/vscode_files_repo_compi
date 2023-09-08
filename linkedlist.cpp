#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *sortedMerge(struct Node *a, struct Node *b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n != NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int data;
        cin >> data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin >> data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin >> data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for (int i = 1; i < m; i++)
        {
            cin >> data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}
Node *sortedMerge(Node *head1, Node *head2)
{
    struct Node *temp1 = head1;
    struct Node *temp2 = head2;
    while (temp1->next != NULL && (temp2->next != NULL))
    {
        if (temp1->data < temp2->data)
        {
            struct Node *x1 = temp1->next;
            struct Node *x2 = temp2->next;
            temp1->next = temp2;
            temp2->next = x1;
            temp1 = temp2;
            temp2 = x2;
        }
        else
        {
            struct Node *x2 = temp2->next;
            temp2->next = temp1;
            temp1 = temp2;
            temp2 = x2;
        }
    }

    return head1;

    // code here
}