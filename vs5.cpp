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
vector<vector<vector<char>>> r;

void rec(vector<vector<char>> &t, int &i, int &j, bool &ret)
{
    if (i == 8 && j == 8) {
        r.pb(t);
        return;
        
    }
    else if(ret == true) {
        return;
    }
    
    if (j >= 8) {
        j = 0;
        i++;
        
    }



    if (t[i][j] == '.') {
        set<char> present;
        set<char> e;
        set<char> left;
        f(x,1,10) {
            e.insert(x);
        }


        f(p,0,9) {
            if (t[p][j] != '.'){
                present.insert(t[p][j]);
            }
            if (t[i][p] != '.'){
                present.insert(t[i][p]);
            }
        }

        f(x, 3 * (i / 3), 3 * ((i / 3) + 1))
        {
            f(y, 3 * (j / 3), 3 * ((j / 3) + 1)) {
                if (t[x][y] != '.')
                    present.insert(t[x][y]);
            }
        }
        for (auto x: e) {
            if (find(all(present),x) == present.end()) {
                left.insert(x);
            }
        }
        for(auto tt: left) {
            t[i][j] = tt;
            j = j+1;
            ret = false;
            cout << i << " " << j << " " << t[i][j] << endl;
            rec(t,i,j,ret);
            j--;
            t[i][j] = '.';
        }
    }
    else {
        f(k,0,9) {
            if ((t[i][j] == t[i][k]) || (t[i][j] == t[k][j])) {
                ret = true;
            }


        }
        f(x, 3 * (i / 3), 3 * ((i / 3) + 1))
        {
            f(y, 3 * (j / 3), 3 * ((j / 3) + 1))
            {
                if (t[i][j] == t[x][y]) {
                    ret = true;
                }
                
            }
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

    int n = 9;
    char s;
    vector<vector<char>> su;
    f(i,0,9) {
        vector<char> t;
        f(j,0,9) {
            cin >> s;
            t.pb(s);
        }
        su.pb(t);
        
    }
    int i = 0, j = 0;
    bool ret = false;
    rec(su,i,j, ret);



    // for(auto f: r) {
    //     for(auto t:f) {
    //         for(auto h:t)
    //             cout << h << " ";
    //     }
    //     coen;
    // }

    return 0;
}
