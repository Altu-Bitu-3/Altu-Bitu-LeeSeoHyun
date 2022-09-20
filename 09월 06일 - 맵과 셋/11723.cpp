#include <iostream>

using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	string cmd;
	bool arr[20] = {};
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "all") {
			for (int i = 0; i < 20; i++) {
				arr[i] = 1;
			}
		}
		else if (cmd == "empty") {
			for (int i = 0; i < 20; i++) {
				arr[i] = 0;
			}
		}
		else
			cin >> x;
		if (cmd == "add") {
			arr[x - 1] = 1;
		}
		if (cmd == "remove") {
			arr[x - 1] = 0;
		}
		if (cmd == "check") {
			cout << arr[x - 1] << "\n";
		}
		if (cmd == "toggle") {
			arr[x - 1] = 1 - arr[x - 1];
		}
	}
	return 0;
}