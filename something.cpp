#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
	priority_queue<int> maxh;
	priority_queue<int, vector<int>, greater<int>> minh;

	// Function to insert heap.
	void insertHeap(int &x)
	{
		if (maxh.empty()) {
			maxh.push(x);
		}
		else if (minh.empty()) {
			minh.push(x);
		}
		else {

			if (x <= maxh.top())
			{
				maxh.push(x);
			}
			else
			{
				minh.push(x);
			}
		}
	}

	// Function to balance heaps.
	void balanceHeaps()
	{
		while (abs(maxh.size() - minh.size()) > 1)
		{
			if (maxh.size() > minh.size())
			{
				minh.push(maxh.top());
				maxh.pop();
			}
			else
			{
				maxh.push(minh.top());
				minh.pop();
			}
		}
	}

	// Function to return Median.
	double getMedian()
	{
		balanceHeaps();
		if ((maxh.size() + minh.size()) % 2 == 0)
		{
			return ((double)(maxh.top() + minh.top())) / 2;
		}
		else
		{
			return (maxh.size() > minh.size()) ? maxh.top() : minh.top();
		}
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
	int n, x;
	int t;
	cin >> t;
	while (t--)
	{
		Solution ob;
		cin >> n;
		for (int i = 1; i <= n; ++i)
		{
			cin >> x;
			ob.insertHeap(x);
			cout << floor(ob.getMedian()) << endl;
		}
	}
	return 0;
}