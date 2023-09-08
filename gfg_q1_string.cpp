#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

// User function template for C++

class Solution
{
public:
    int lps(string s)
    {
        // Your code goes here
        string x = s;
        reverse(x.begin(), x.end());
        string pre = "";
        string suff = "";
        int len = 0;
        int i = 1;
        int n = s.length();
        while (i <= n - 1)
        {
            pre = s.substr(0, i);

            suff = x.substr(0, i);

            reverse(suff.begin(), suff.end());
            cout << pre << " " << suff << endl;
            if (pre == suff)
            {
                len = pre.length();

                i++;
            }
            else
            {
                i++;
            }
        }
        return len;
    }
};

//{ Driver Code Starts.

int main()
{

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}