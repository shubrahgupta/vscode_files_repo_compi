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



int lower_bound(vi &arr, int to_find) {
    int lo = 0, hi = arr.size()-1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (arr[mid] >= to_find)
        {
            hi = mid;
        }
        else
        {
            lo = mid+1;
        }
    }
    if (arr[lo] >= to_find)
    {
        return lo;
    }
    else if (arr[hi] >= to_find)
    {
        return hi;
    }
    else
    {
        return -1;
    }
}

int upper_bound(vi &arr, int to_find)
{
    int lo = 0, hi = arr.size() - 1;
    while (hi - lo > 1)
    {
        int mid = (hi + lo) / 2;
        if (arr[mid] > to_find)
        {
            hi = mid;
        }
        else
        {
            lo = mid + 1;
        }
    }
    if (arr[lo] > to_find)
    {
        return lo;
    }
    else if (arr[hi] > to_find)
    {
        return hi;
    }
    else
    {
        return -1;
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
    int n, to_find, x;
    cin >> n;
    
    int lo = 0, hi = n-1;
    vi arr;
    f(i,0,n) {
        cin >> x;
        arr.pb(x);
    }
    cin >> to_find;

    int lb = lower_bound(arr,to_find);
    int ub = upper_bound(arr, to_find);

    // cout << lb << " " <<  (lb != -1 ? arr[lb89] : -1) << endl;
    // cout << ub << " " << (ub != -1 ? arr[ub] : -1) << endl;
    cout << lb << endl;
    cout << ub << endl;
    return 0;
}
