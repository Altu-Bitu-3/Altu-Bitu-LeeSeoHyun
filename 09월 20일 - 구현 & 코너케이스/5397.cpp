#include <iostream>
#include <stack>

using namespace std;

void truePW(string s) {
	stack<char> stleft, stright;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '-') {
			if (!stleft.empty()) {
				stleft.pop();
			}
		}
		else if (s[i] == '<') {
			if (!stleft.empty()) {
				stright.push(stleft.top());
				stleft.pop();
			}
		}
		else if (s[i] == '>') {
			if (!stright.empty()) {
				stleft.push(stright.top());
				stright.pop();
			}
		}
		else {
			stleft.push(s[i]);
		}
	}

	while (!stleft.empty()) {
		stright.push(stleft.top());
		stleft.pop();
	}
	while (!stright.empty()) {
		cout << stright.top();
		stright.pop();
	}
	cout << '\n';
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;

	while (n--) {
		cin >> s;
		truePW(s);
	}
}
// 커서 양 옆을 구별한다는 발상은 떠올랐는데 "쌓는" 구현방법을 모르겠어서 다음의 블로그를 참고 (적층은..스택..!)
// https://chancoding.tistory.com/49
// 아래는 처음에 string 사용해 풀었던 것 => 시간 초과
/*#include <iostream>
#include <string>

using namespace std;

int checkFunc(char c) {
	switch (c) {
	case '<':
		return 1;
	case '>':
		return 2;
	case '-':
		return -1;
	default:
		return 0;
	}
}

string truePW(string s) {
	string pw="";
	int cursor = 0;
	for (int i = 0; i < s.length(); i++) {
		int check = checkFunc(s[i]);
		string s1;
		s1 += s[i];
		if (check == -1 && cursor > 0) {
			pw.erase(cursor - 1, 1);
			cursor--;
		}
		else if (check == 1 && cursor > 0) {
			cursor--;
		}
		else if (check == 2 && cursor + 1 < pw.length()) {
			cursor++;
		}
		else if (check == 0) {
			pw.insert(cursor, s1);
			cursor++;
		}
		else
			continue;
	}
	return pw;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string s;
	cin >> n;
	while(n--){
		cin >> s;
		cout << truePW(s) << '\n';
	}
}*/