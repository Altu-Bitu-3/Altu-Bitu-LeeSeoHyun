﻿//14425번
//시간복잡도 O(1)인 (정렬 안 되는 해시 맵) unordered_set 라이브러리를 이용

#include <unordered_set>
#include <iostream>
#include <set>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, m;
	unordered_set<string> str;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		str.insert(s);
	}
	int cnt = 0;
	while (m--) {
		string s;
		cin >> s;
		if (str.find(s) != str.end())
			++cnt;
	}
	cout << cnt;
	return 0;
}