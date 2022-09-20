#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
	for (int i = min(a, b); i > 0; i--) {
		if (a % i == 0 && b % i == 0) {
			return i;
		}
	}
	return 1;
}

int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		vector<int> v;
		int n;
		long long sum = 0; //sum 크기 주의
		cin >> n;
		if (n == 1) { //n==1일때 고려해야
			int num;
			cin >> num;
			cout << num << '\n';
			continue;
		}

		for (int i = 0; i < n; i++) {
			int num;
			cin >> num;
			v.push_back(num);
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				sum += gcd(v[i], v[j]);
			}
		}

		cout << sum << '\n';
	}
}