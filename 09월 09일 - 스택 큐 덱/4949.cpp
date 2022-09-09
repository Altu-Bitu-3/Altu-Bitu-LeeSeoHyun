//4949 스택 (<string>, <stack>, <map> 사용)
#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

bool isBalanced(string& s) {
	stack<char> st;
	map<char, char> m;
	m[')'] = '(';
	m[']'] = '[';
	for (int i = 0; i < s.length(); i++) {
		switch (s[i]) {
		case '(': case '[':
			st.push(s[i]);
			break;
		case ')': case ']':
			if (st.empty() || st.top() != m[s[i]]) { //스택 비었거나 괄호 종류 안맞음. 순서 바꾸면 에러남. empty 체크부터 하기.
				return false;
			}
			st.pop(); //괄호 종류 맞음
			break;
		}
	}
	return st.empty();
}
int main() {
	string s;
	//getline(cin, <문자열 이름>): 공백 포함 입력받기
	while (getline(cin, s)) {
		if (s == ".") {
			break;
		}
		if (isBalanced(s)) {
			cout << "yes\n";
		}
		else {
			cout << "no\n";
		}
	}
	return 0;
}