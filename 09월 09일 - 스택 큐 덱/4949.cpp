//4949 ���� (<string>, <stack>, <map> ���)
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
			if (st.empty() || st.top() != m[s[i]]) { //���� ����ų� ��ȣ ���� �ȸ���. ���� �ٲٸ� ������. empty üũ���� �ϱ�.
				return false;
			}
			st.pop(); //��ȣ ���� ����
			break;
		}
	}
	return st.empty();
}
int main() {
	string s;
	//getline(cin, <���ڿ� �̸�>): ���� ���� �Է¹ޱ�
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