#include<iostream>
#include<vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;

	if (n >= m) {
		cout << "YES";
		return 0;
	}

	vector<short int> v(n);
	for (auto &elem : v) {
		int a;
		cin >> a;
		elem = a % m;
	}

	vector<bool> a(m);
	vector<bool> b(m);

	vector<bool> *working = &a;
	vector<bool> *dps = &b;

	(*dps)[v[0]] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < m; j++) {
			(*working)[j] = (v[i] == j) || (*dps)[j] || (*dps)[(j - v[i] + m) % m];
		}
		swap(working, dps);
	}

	cout << ((*dps)[0] ? "YES" : "NO");
}
