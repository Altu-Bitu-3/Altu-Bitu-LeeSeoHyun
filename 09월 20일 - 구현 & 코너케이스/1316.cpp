#include <iostream>

using namespace std;

bool isGroupword(string s) {
	bool arr[26] = {};
	for (int i = 0; i < s.length(); i++) {
		if (i == 0 || s[i] != s[i - 1]) {
			if (arr[s[i] - 'a']) {
				return 1;
			}
			arr[s[i] - 'a'] = true;
		}
	}
	return 0;
}

int main()
{
	int n, cnt = 0;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		if (!isGroupword(s)) {
			cnt++;
		}
	}
	cout << cnt;
}