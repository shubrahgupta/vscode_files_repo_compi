#include <bits/stdc++.h>
using namespace std;

void print_array(vector<vector<int>> arr) {
	for (int i = 0; i < arr.size(); i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
}

void do_something(vector<vector<int>> arr, int n) {
	arr[n-1][n-1] = 1;

	for (int i = 0; i < n-1; i++) {
		arr[n-1][i] = n-i;
		arr[n-1][2*n-2-i] = n-i;
		arr[i][n-1] = n-i;
		arr[2*n-2-i][n-1] = n-i;

	}
	for(int i = 0; i < 2*n-1; i++) {
		for (int j = 0 ; j < 2*n-1; j++) {
			if((i != n-1) && (j != n-1)) {
				arr[i][j] = arr[n-1][j];
			}
		}
	}

	// print_array(arr);
	for(int i = 1;i < n; i++) {
		for(int j = 0; j < 2*n - 1; j++) {
			if(arr[n-1-i][j] <= i) {
				arr[n-1-i][j] = i+1;
				arr[n-1+i][j] = i+1;

			}
		}
	}
	print_array(arr);
}

// void func

int main() {
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<vector<int>> arr(2*n-1, vector<int> (2*n-1, 0));
		do_something(arr,n);
		
	}

}