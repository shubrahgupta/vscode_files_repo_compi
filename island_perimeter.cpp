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

const int N = 1e5 + 10;
vector<int> al[N];
bool visited[N];


void dfs(int i, int j, vector<vector<int>> &image, int &peri, bool &found, vector<vector<bool>> &visit, int &count)
{
    /*things to do after entering vertex*/

    int m = image.size();
    int n = image[0].size();
    if (i < 0 || j < 0)
        return;
    if (i >= m || j >= n)
        return;
    if (visit[i][j]) {
        return;
    }
    if (image[i][j] == 0 && found == true) return;
    if (image[i][j] == 1) {
        found = true;
        count += 1;
        peri += 4-2;
    }
    cout << "{" << i << " " << j << "} " << image[i][j] << " " << peri << endl;
    visit[i][j] = true;
    dfs(i - 1, j, image, peri, found, visit, count);
    dfs(i + 1, j, image, peri, found, visit, count);
    dfs(i, j - 1, image, peri, found, visit, count);
    dfs(i, j + 1, image, peri, found, visit, count);
}
// O(V+E)


int islandPerimeter(vector<vector<int>> &grid)
{
    vector<vector<bool>> visit(grid.size()+2, vector<bool>(grid[0].size()+2, false));
    int peri = 0, count = 0;
    bool found = false;
    dfs(0,0,grid,peri, found, visit, count);
    if (count == (grid.size() * grid[0].size()))  return count*2;
    else return peri + 2;
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
    // int n, m;
    // cin >> n >> m;
    // f(i, 0, m)
    // {
    //     int v1, v2;
    //     cin >> v1 >> v2;

    //     // am[v1][v2] = 1;
    //     // am[v2][v1] = 1;

    //     al[v1].pb(v2);
    //     al[v2].pb(v1);
    // }
    int row,column,x;
    vector<vector<int>> grid;
    vector<int> r;
    cin >> row >> column;
    f(i,0,row) {
        r.clear();
        f(j,0,column) {
            cin >> x;
            r.pb(x);
        }
        grid.pb(r);
    }
    cout << islandPerimeter(grid) << endl;

    return 0;
}
