#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define endl "\n"
#define pb push_back
#define coen cout << endl

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define cap(t) transform(t.begin(), t.end(), t.begin(), ::toupper); // t is a string
#define low(t) transform(t.begin(), t.end(), t.begin(), ::tolower);
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
        cout << x << endl;
}

vector<vector<ll>> f;
void generate(vll subset, ll i, vll og) {

    if (i == og.size()) {
        f.push_back(subset);
        return;
    }

    generate(subset,i+1,og);

    subset.push_back(og[i]);
    generate(subset, i+1, og);

    subset.pop_back();
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

    int n;
    ll x;
    cin >> n;
    vll og, empty;
    f(i, 0, n) {
        cin >> x;
        og.push_back(x);
    }
    generate(empty, 0, og);
    for (auto vector: f) {
        for (auto element: vector) {
            cout << element << " ";
        }
        coen;
        
    }
    
    
    return 0;
}
