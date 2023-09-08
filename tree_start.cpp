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

vector<vector<int>> levelorder(Node* root) {
    vector<vector<int>> ans;
    if (root == NULL)   return ans;
    queue<Node *> q;
    q.push(root);
    while(!q.empty()) {
        vector<int> s;
        int siz = q.size();
        for(int i = 0; i < siz; i++) {
            Node *el = q.front();
            q.pop();
            s.push_back(el->data);

            if (el->left != NULL)
                q.push(el->left);
            if (el->right != NULL)
                q.push(el->right);
        }
        ans.push_back(s);
    }
    return ans;
}

vi iter_preorder(Node* root) {
    vi ans;
    if (root == NULL)   return ans;
    stack<Node*> s;
    s.push(root);
    while(!s.empty()) {
        root = s.top();
        s.pop();
        ans.push_back(root->data);
        if (root->right != NULL)    
            s.push(root->right);
        if (root->left != NULL)
            s.push(root->left);
    }
    return ans;
}

vi iter_inorder(Node* root) {
    vi ans;
    if (root == NULL) return ans;
    stack<Node* > s;

    while(true) {
        if (root != NULL) {
            s.push(root);
            root = root->left;
        }
        else {
            if (s.empty())  break;
            root = s.top();
            s.pop();
            ans.push_back(root->data);
            root = root->right;
        }
    }
    return ans;
}

vi iter_postorder(Node *root)
{
    vi ans;
    if (root == NULL)
        return ans;
    stack<Node *> s;
    Node* curr = root;
    while((!s.empty()) || (curr != NULL)) {
        if (curr != NULL) {
            s.push(curr);
            curr = curr->left;
        }
        else {
            Node* temp = s.top()->right;
            if (temp == NULL) {
                temp = s.top();
                s.pop();
                ans.push_back(temp->data);
                while (!s.empty() && temp == s.top()->right)
                {
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->data);
                }
            }
            else {
                curr = temp;
            }


        }
    }
    return ans;

    
}

vi iter_post_2stack(Node* root) {
    vi ans;
    if (root == NULL)   return ans;
    stack<Node*> s1, s2;
    s1.push(root);
    while(!s1.empty()) {
        root = s1.top();
        s1.pop();
        s2.push(root);
        if (root->left != NULL) s1.push(root->left);
        if (root->right != NULL) s1.push(root->right);
    }

    while(!s2.empty()) {
        ans.push_back(s2.top()->data);
        s2.pop();
    }
    return ans;

}

vi pre, in, post;
void all_traversals(Node* root) {
    if (root == NULL)   return;

    stack<pair<Node*, int>> s;
    s.push({root, 1});
    while(!s.empty()) {
        auto p = s.top();
        s.pop();
        if (p.ss == 1) {
            pre.push_back(p.ff->data);
            p.ss += 1;
            s.push(p);
            if (p.ff->left != NULL) 
                s.push({p.ff->left, 1});
        }
        else if (p.ss == 2)
        {
            in.push_back(p.ff->data);
            p.ss += 1;
            s.push(p);
            if (p.ff->right != NULL)
                s.push({p.ff->right, 1});
        }
        else if (p.ss == 3)
        {
            post.push_back(p.ff->data);
        }
    }
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
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(6);
    root->right->right = new Node(7);


    // preorder(root);
    cout << endl;
    // inorder(root);
    cout << endl;
    // postorder(root);
    cout << endl;

    // vector<vector<int>> ans = levelorder(root);
    // for(auto x: ans) {
    //     for(auto y:x) {
    //         cout << y << " ";
    //     }
    //     cout << endl;
    // }


    // vector<int> something = iter_postorder(root);
    // print_v(something);

    // vector<int> something1 = iter_post_2stack(root);
    // print_v(something1);

    all_traversals(root);
    print_v(pre);
    print_v(in);
    print_v(post);

    return 0;
}
