#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define vi vector<int>
#define vs vector<string>
#define vll vector<long long>
#define endl "\n"
#define pb push_back

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

const int N = 1e5 + 10;
int a[N];

vector<int> selectionSort(vector<int> p, int n) {
    int minIndex = 0;
    for (int i = 0; i < n; i++) {
        minIndex = i;
        for (int j = i+1; j < n; j++) {
            if (p[j] <= p[minIndex]) {
                minIndex = j;
            }
        }
        swap(p[i],p[minIndex]);
    }
    return p;
}

void merge(int l, int mid, int r)
{
    int l_sz = mid - l + 1;
    int r_sz = r - mid;
    int L[l_sz + 1], R[r_sz + 1];
    for (int i = 0; i < l_sz; i++)
    {
        L[i] = a[i + l];
    }
    for (int i = 0; i < r_sz; i++)
    {
        R[i] = a[mid + 1 + i];
    }
    L[l_sz] = R[r_sz] = INT_MAX;
    int l_i = 0, r_i = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[l_i] <= R[r_i])
        {
            a[i] = L[l_i];
            l_i++;
        }
        else if (L[l_i] > R[r_i])
        {
            a[i] = R[r_i];
            r_i++;
        }
    }
}
void mergeSort(int l, int r)
{
    if (l == r)
    {
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(l, mid);
    mergeSort(mid + 1, r);
    merge(l, mid, r);
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
    cin >> n;
    vector<int> a1, b;

    f(i, 0, n)
    {
        cin >> a[i];
        a1.pb(a[i]);
    }

    mergeSort(0, n - 1);

    cout << "Merge Sort" << endl;
    f(i, 0, n)
    {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Selection Sort" <<  endl;
    b = selectionSort(a1,n);
    f(i, 0, n)
    {
        cout << b[i] << " ";
    }
    cout << endl;

    return 0;
}
