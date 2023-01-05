#include <bits/stdc++.h>
using namespace std;

template <class T>
void print_v(vector<T> &v)
{
    for (auto x : v)
        cout << x << endl;
}

vector<int> twoSum(vector<int> &nums, int target)
{
    vector<int> ss;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((nums[i] + nums[j]) == target)
            {
                ss.push_back(i);
                ss.push_back(j);
                return ss;
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<int> dd = {3, 2, 4};
    int target = 6;
    vector<int> ans = twoSum(dd,target);
    print_v(ans);
    return 0;
}