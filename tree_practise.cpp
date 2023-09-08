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
typedef pair<int, pair<int, int>> ppi;
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
    ll t;     \
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

struct Node {
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }

};

void preorder(Node* root) {
    if (root == NULL) return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
    

}

void inorder(Node *root)
{
    if (root == NULL)
        return;


    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void postorder(Node *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    
    postorder(root->right);
    cout << root->data << " ";
    
}

vvi levelOrder(Node* root) {
    vvi ans;
    if (root == NULL) {
        return ans;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()) {
        int n = q.size();
        vi s;
        for(int i = 0; i < n; i++) {
            Node* x = q.front();
            q.pop();
            if (x->left != NULL) q.push(x->left);
            if (x->right != NULL) q.push(x->right);
            s.pb(x->data);
            
        }
        ans.pb(s);
    }
    return ans;
}


void iterative_preorder(Node* root) {
    if (root == NULL) return;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        Node* x = s.top();
        s.pop();
        cout << x->data << " ";
        if (x->right != NULL) s.push(x->right);
        if (x->left != NULL) s.push(x->left);

    }
}

vector<int> iterative_inorder(Node *root)
{
    Node *curr = root;
    stack<Node *> s;
    vector<int> ans;
    while (true)
    {
        if (curr != NULL)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            if (s.empty())
                break;
            curr = s.top();
            s.pop();
            ans.push_back(curr->data);
            curr = curr->right;
        }
    }

    return ans;
}

void twostack_iter_postorder(Node* root) {
    stack<Node*> s1,s2;
    s1.push(root);
    while(!s1.empty()) {
        Node* x = s1.top();
        s1.pop();
        s2.push(x);
        if (x->left != NULL) {
            s1.push(x->left);
        }
        if (x->right != NULL)
        {
            s1.push(x->right);
        }
    }
    while(!s2.empty()) {
        Node* x = s2.top();
        s2.pop();
        cout << x->data << " ";
    }
    coen;
}
//best method to implement postorder by 1 stack
vi iterative_postorder(Node *root)
{
    vi ans;
    if (root == NULL)
        return ans;
    stack<Node *> s;
    s.push(root);
    while (!s.empty())
    {
        Node *x = s.top();
        s.pop();
        ans.pb(x->data);
        if (x->left != NULL)
            s.push(x->left);
        if (x->right != NULL)
            s.push(x->right);
    }
    reverse(all(ans));
    return ans;
}

int maxDepth(Node* root) {
    int height = 0;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int n = q.size();
        // vi s;
        for(int i = 0; i < n; i++) {
            Node* x = q.front();
            q.pop();
            // s.pb(x->data);
            if (x->left != NULL) q.push(x->left);
            if (x->right != NULL)
                q.push(x->right);
        }
        height++;
    }
    return height;
}

int maxDepth_rec(Node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + max(maxDepth_rec(root->left), maxDepth_rec(root->right));
}

int isBalanced(Node* root) {
    if (root == NULL)
    {
        return 0;
    }

    int lh = isBalanced(root->left);
    int rh = isBalanced(root->right);
    if (lh == -1 || rh == -1) {
        return -1;
    }

    if (abs(lh-rh) > 1) return -1;
    return 1+max(lh,rh);

}




bool isIdentical(Node* root, Node* root1) {
    if (root == NULL || root1 == NULL){
        return (root == root1);
    }
    return (root->data == root1->data) && 
        isIdentical(root->left, root1->left) && 
        isIdentical(root->right, root1->right);
    
    
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
    struct Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(6);
    root->left->right->right = new Node(7);

    struct Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(6);
    root1->left->right->right = new Node(7);
    // root->right->left = new Node(8);

    // vvi level = levelOrder(root);
    // for(auto i: level) {
    //     for(auto j:i) {
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }
    // vi s = iterative_inorder(root);
    // print_v(s);

    // postorder(root);
    // coen;
    // twostack_iter_postorder(root);
    // coen;
    // vi ans = iterative_postorder(root);
    // print_v(ans);
    // cout << maxDepth(root) << endl;
    // cout << maxDepth_rec(root) << endl;

    cout << isIdentical(root, root1) << endl;
    return 0;
}
