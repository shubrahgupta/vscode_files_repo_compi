#include <bits/stdc++.h>

using namespace std;
#define ull unsigned long long int
#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define endl "\n"
#define pb push_back

#define f(i, s, e) for (long long int i = s; i < e; i++)
#define cf(i, s, e) for (long long int i = s; i <= e; i++)
#define rf(i, e, s) for (long long int i = e - 1; i >= s; i--)
#define cap(t) transform(t.b egin(), t.end(), t.begin(), ::toupper); // t is a string
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

int flip(int c) { return (c == 0) ? 1 : 0; }

int kthGrammar(int n, int k)
{
    
    if (k == 1)
    {
        cout << 0 << " " << n << " " << k << endl;
        return 0;
        
    }
    else if ((k == 2) && (n == 1))
    {
        cout << 1 << " " << n << " " << k << endl;
        return 1;
    }

    n--;

    int x = ceil(k/2);
    cout << "x: " << x << endl;
    if (x * 2 == k)
    {
        int z = flip(kthGrammar(n, ceil(double(k) / 2)));
        cout << z << " " << n << " " << ceil(k / 2) << endl;
        return z;
    }
    else
    {
        int z = kthGrammar(n, ceil(double(k) / 2));
        cout << z << " " << n << " " << ceil(k / 2) << endl;
        return z;
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
    int n,k;
    cin >> n >> k;

    int x = kthGrammar(n,k);
    cout << "final" << endl;
    cout << x << " " << n << " " << k << endl;
    // int e = 5;
    // cout << ceil(e/2) << endl;
    // cout << flip(1) << flip(0) << endl;
    return 0;
}
