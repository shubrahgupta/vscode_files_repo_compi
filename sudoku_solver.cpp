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

bool SudokuCheck(vector<vector<char>> &t, int row, int col, char c)
{
    
        
    f(i,0,9) {
        if (t[i][col] != '.' && t[i][col] == c) {
            return false;
        }
        if (t[row][i] != '.' && t[row][i] == c)
        {
            return false;
        }
    }


    f(i,(row/3) * 3,(row/3 + 1) * 3) {
        f(j, (col / 3) * 3, (col / 3 + 1) * 3) {
            if (t[i][j] == c) {
                return false;
            }
        }
    }
    return true;
}


bool solve(vector<vector<char>> &t)
{

    f(i,0,9) {
        f(j,0,9) {
            if (t[i][j] == '.') {
                for(char c='1'; c <= '9'; c++) {
                    if (SudokuCheck(t,i,j,c)) {
                        t[i][j] = c;
                        if (solve(t)) {
                            return true;
                        }
                        else {
                            t[i][j] = '.';
                        }


                    }
                }
                return false;
            
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    if (solve(board))
    {
        f(i,0,9) {
            f(j,0,9) {
                cout << board[i][j] << " ";
            }
            coen;
        }
    }
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
    solveSudoku(su);





    return 0;
}
