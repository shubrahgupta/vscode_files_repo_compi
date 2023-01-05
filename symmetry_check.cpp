#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define vi vector<int>
#define vll vector<long long>
#define endl "\n"

/* FUNCTIONS */
#define f(i,s,e) for(long long int i=s;i<e;i++)
#define cf(i,s,e) for(long long int i=s;i<=e;i++)
#define rf(i,e,s) for(long long int i=e-1;i>=s;i--)




bool x_symm_even(vector<vector<int>> a, int n) {
	f(i,0,n/2) {
		f(j,0,n) {
			if (a[n/2 - 1 - i][j] != a[n/2 + i][j]) {
				cout << i << " " << j << endl;
				cout << a[n/2 - 1 - i][j] << " " << a[n/2 + i][j] << endl;
				return 0;
			}
		}
	}
	return 1;

}

bool y_symm_even(vector<vector<int>> a, int n) {
	f(i,0,n) {
		f(j,0,n/2) {
			if (a[i][n/2 -1 - j] != a[i][n/2 + j]) {
				cout << i << " " << j << endl;
				cout << a[i][n/2 - 1 - j] << " " << a[i][n/2 + j] << endl;
				return 0;
			}
		}
	}
	return 1;

}


bool x_symm_odd(vector<vector<int>> a, int n) {
	f(i,0,n/2) {
		f(j,0,n) {
			if (a[n/2 - 1 - i][j] != a[n/2 + 1 + i][j]) {
				cout << i << " " << j << endl;
				cout << a[n/2 - 1 - i][j] << " " << a[n/2 + 1 + i][j] << endl;
				return 0;
			}
		}
	}
	return 1;

}

bool y_symm_odd(vector<vector<int>> a, int n) {
	f(i,0,n) {
		f(j,0,n/2) {
			if (a[i][n/2 - 1 - j] != a[i][n/2 + 1 + j]) {
				cout << i << " " << j << endl;
				cout << a[i][n/2 - 1 - j] << " " << a[i][n/2 + 1 + j] << endl;
				return 0;
			}
		}
	}
	return 1;

}

/*bool odd_check(vector<vector<int>> a, int n) {
	cf(i,1,n/2) {
		if ((a[n/2 - i][n/2] != a[n/2 + i][n/2]) || a[n/2][n/2 - i] != a[n/2][n/2 + i]) {
			cout << i << " " << endl;
			return 0;
		}
	}
	return 1;

}*/


int main() {
	
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;

		vector<vector<int>> a;
		for (int i = 0; i < n; i++) {
			string g;
			cin >> g;
			a.push_back(vector<int>());
			for (int j = 0; j < n; j++) {

				a[i].push_back(stoi(g.substr(j,1)));
			}
		}
		// for (int i = 0; i < n; i++) {
		// 	for (int j = 0; j < n; j++) {
		// 		cout << a[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// cout << endl;

		if (n % 2 == 0) {
			cout << "EVEN" << endl;
			bool x = x_symm_even(a,n);
			bool y = y_symm_even(a,n);
			if ((x == 1) && (y == 1)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		else {
			cout << "ODD" << endl;

			bool x = x_symm_odd(a,n);
			bool y = y_symm_odd(a,n);
			// bool z = odd_check(a,n);
			if ((x == 1) && (y == 1)) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
		}
		cout << endl;



	}
} 