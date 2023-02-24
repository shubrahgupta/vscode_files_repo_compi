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

int maxProfit(vector<int>& prices) {
    // int profit = 0;
    if (prices.size() == 1) {
        return 0;
    }
    vector<int> profits;
    for(int i = 0; i < prices.size()-1; i++) {
        int buy_price = prices[i];
        int max_profit = 0;
        int profit = 0;
        for(int j = i+1; j < prices.size(); j++) {
            int sell_price = prices[j];
            profit = sell_price - buy_price;
            if (profit > max_profit) {
                max_profit = profit;
            }
        }
        profits.push_back(max_profit);
    }
    if (*max_element(profits.begin(), profits.end()) > 0) {
        return *max_element(profits.begin(), profits.end());
    }
    else {
        return 0;
    }
}


int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,x;
    vi a;
    cin >> n;
    f(i,0,n) {
        cin >> x;
        a.pb(x);
    }
    cout << maxProfit(a) << endl;
    return 0;
}
