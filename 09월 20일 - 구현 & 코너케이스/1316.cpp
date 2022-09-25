#include <iostream>

using namespace std;

int main()
{
	int n, cnt = 0;
	cin >> n;
	while (n--) {
		bool arr[26] = {};
		int result = 0;
		string s;
		cin >> s;
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || s[i] != s[i - 1]) {
				if (arr[s[i] - 97] == 0) {
					arr[s[i] - 97] = 1;
				}
				else {
					result = 1;
					break;
				}
			}
		}
		if (result == 0) {
			cnt++;
		}
	}
	cout << cnt;
}