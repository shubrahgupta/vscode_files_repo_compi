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
        last = next + 1;                                      \
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

vpii l;

int tilingRectangle(int n, int m, bool flag) {
    if (n == m) {
        return 1;
    }
    else if ((n == 0) || (m == 0)) {
        return 0;
    }
    
    if (flag == true) {
        int g = min(n,m);
        while(g!=0) {
            int d = 1 + tilingRectangle(max(n, m) - g, min(n, m), false) +
                   tilingRectangle(max(n, m), min(n, m) - g, false) -
                   tilingRectangle(max(n, m) - g, min(n, m) - g, false);
            l.pb({g,d});
            g--;
        }
        
    }
    else {
        int g = min(n, m);
        int d = 1 + tilingRectangle(max(n, m) - g, min(n, m), false) +
                    tilingRectangle(max(n, m), 
                    min(n, m) - g, false) -
                    tilingRectangle(max(n, m) - g, min(n, m) - g, false);
        
        
    }

        
    
    // int g = (n * m);
    // g = g / (min(n, m) * min(n, m));
    // return (g + tilingRectangle(min(n, m), max(n, m) - g * min(n, m)));
        
}


int main() {

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m;
    cin >> n >> m;
    // vpii l;
    // for (int i = min(m, n); i >= 1; i--)
    // {
    //     
    //     l.pb({i,x});
    // }
    int x = tilingRectangle(n, m, true);
    for(int k = 0; k < l.size(); k ++) {
        cout << l[k].ff << " " << l[k].ss << endl;
    }

    return 0;
    }
