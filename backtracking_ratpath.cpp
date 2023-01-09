#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long int
#define ll long long int
typedef long long LL;
#define vi vector<int>
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
    int t;    \
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

#define fill2D(arr, M, N, s) std::fill_n(&arr[0][0], M*N, s) // M,N = dimensions, s = value to be filled

template <class T>
void print_v(vector<T> &v)
{
    for (auto x : v)
        cout << x << " ";
    coen;
}

vs l;


void rec(vvi &m, string &s, int n, int &x, int &y, vvi &visited) {
    
    
    if ((m[n - 1][n - 1] == 0) || (m[0][0] == 0))
    {
        l.pb("-1");
        
        return;
    }

    else if ((x == n-1) && (y == n-1)) 
    {
        l.pb(s);
        visited[x][y] = 0;
        return;
    }

    


    bool D = false, L = false, R = false, U = false;

    visited[x][y] = 1;
    int tt = 0;

    if ((x+1 <= n-1) && (m[x+1][y] == 1) && (visited[x+1][y] == 0) && !D) {
        x = x+1;
        s.pb('D');
        D = true;
        visited[x][y] = 1;
        rec(m,s,n,x,y,visited);


        s.pop_back();
        visited[x][y] = 0;
        x = x - 1;
        tt++;
        
        
    }
    D = true;
    if ((y - 1 >= 0) && (m[x][y - 1] == 1) && (visited[x][y - 1] == 0) && !L)
    {
        y = y - 1;
        s.pb('L');
        L = true;
        visited[x][y] = 1;
        rec(m, s, n, x, y, visited);

        s.pop_back();
        visited[x][y] = 0;
        y++;
        tt++;
        
    }

    L = true;
    if ((y + 1 <= n-1) && (m[x][y + 1] == 1) && (visited[x][y + 1] == 0) && !R)
    {
        y = y + 1;
        s.pb('R');
        R = true;
        visited[x][y] = 1;
        rec(m, s, n, x, y, visited);


        s.pop_back();
        visited[x][y] = 0;
        y--;
        tt++;

        
    }
    R = true;
    if ((x - 1 >= 0) && (m[x - 1][y] == 1) && (visited[x - 1][y] == 0) && !U)
    {
        x--;
        s.pb('U');
        U = true;
        visited[x][y] = 1;
        rec(m, s, n, x, y, visited);

        s.pop_back();
        visited[x][y] = 0;
        x++;
        tt++;
    }
    U = true;

}





int main()
{

#ifndef ONLINE_JUDGE
    freopen("notep1.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n;
    vvi x;
    f(i, 0, n)
    {
        vi y;
        f(j, 0, n)
        {
            cin >> p;
            y.pb(p);
        }
        x.pb(y);
    }



    string s;
    
    vvi visited (n,vi(n,0));
    int i = 0, j = 0;
    rec(x, s, n, i, j, visited);
    coen;
    for (auto q : l)
    {
        cout << q << endl;
    }
    if (l.size() == 0) 
    {cout << -1;}

    return 0;
}
