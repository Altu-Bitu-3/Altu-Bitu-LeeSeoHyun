#include <iostream>
using namespace std;

int n;
int num[11] = {};
int oper[4];

int calmin = 10e9 + 1;
int calmax = -10e9 - 1;

int calOperator(int result, int num, int i) {
	if (i == 0) {
		return result + num;
	}
	else if (i == 1) {
		return result - num;
	}
	else if (i == 2) {
		return result * num;
	}
	else {
		return result / num;
	}
}

void calCompare(int result, int count) {
	if (count == n - 1) {
		calmin = min(calmin, result);
		calmax = max(calmax, result);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (oper[i] == 0) continue;
		oper[i]--;
		calCompare(calOperator(result, num[count + 1], i), count + 1);
		oper[i]++;
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	calCompare(num[0], 0);
	cout << calmax << '\n' << calmin << '\n';
}