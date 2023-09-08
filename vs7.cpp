#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long int
#define ll long long int
typedef long long LL;
#define vi vector<int>
#define vd vector<double>
#define vs vector<string>
#define vll vector<long long>
typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef pair<string, string> pss;
typedef vector<vi> vvi;
typedef vector<pii> vpii;
typedef vector<pll> vpll;
typedef vector<vll> vvl;
typedef vector<vs> vvs;

#define endl "\n"
#define pb push_back
#define coen cout << endl

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define cap(t) transform(t.begin(), t.end(), t.begin(), ::toupper); // t is a string
#define low(t) transform(t.begin(), t.end(), t.begin(), ::tolower);

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define ff first
#define ss second

#define w(t)  \
    ll t;    \
    cin >> t; \
    while (t--)

#define maxe(x) *max_element(all(x))
#define mine(x) *min_element(all(x))

#define string_split(s, delimiter)                           \
    size_t last = 0;                                         \
    size_t next = 0;                                         \
    while ((next = s.find(delimiter, last)) != string::npos) \
    {                                                        \
        cout << s.substr(last, next - last) << endl;         \
        last = next + 1;                                     \
    }                                                        \
    cout << s.substr(last) << endl;

#define fill2D(arr, M, N, s) std::fill_n(&arr[0][0], M *N, s) // M,N = dimensions, s = value to be filled

template <class T>
void print_v(vector<T> &v)
{
    for (auto x : v)
        cout << x << " ";
    coen;
}

class node {
public: 
    int data;
    node* next;

    node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(node* &head, int val) {

    node* new_node = new node(val);

    if (head == NULL) {
        head = new_node;
        return;
    }
    node* temp = head;
    while(temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;

}
void insertAtFront(node* &head, int val)
{
    node* new_node = new node(val);
    new_node->next = head;
    head = new_node;
}

void insertAfter(node* &prev, int val) {
    if (prev == NULL) {
        cout << "previous node was a null node" << endl;

    }
    node* new_node = new node(val);
    new_node->next = prev->next;
    prev->next = new_node;
}

void display_ll(node* head) {
    node* temp = head;
    while(temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void deleteAtStart(node* &head) {
    if (head == NULL) {
        cout << "nothing to delete" << endl;
    }
    node* temp = head->next;
    head->next = NULL;
    delete head;
    head = temp;

}

void deleteAtTail(node* &head)
{
    node *temp = head;
    while(temp->next->next != NULL) {
        temp = temp->next;
    }

    node* el = temp->next;
    temp->next = NULL;
    delete el;

}

void deletePresent(node* &head, int val)
{
    node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == val) {
            node* el = temp->next;
            temp->next = el->next;
            el->next = NULL;
            delete el;
            return;
        }
        else    temp = temp->next;
    }
    cout << "Element not present" << endl;
}

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    node* head = NULL;
    insertAtTail(head, 4545);
    insertAtTail(head, 788);
    display_ll(head);
    insertAtFront(head, 5005);
    insertAtFront(head, 32);
    insertAtFront(head, 554);
    insertAtFront(head, 11);
    display_ll(head);
    node* temp = head;
    while(temp->data!=32) {
        temp = temp->next;
    }
    insertAfter(temp, 64);
    display_ll(head);
    deleteAtStart(head);
    deleteAtTail(head);

    display_ll(head);
    deletePresent(head, 64);
    display_ll(head);
    deletePresent(head, 70);
    display_ll(head);
    return 0;
}


