//10828 스택 (원리)

/*#include<iostream>
#include<vector>

using namespace std;
const int SIZE = 1e4;
vector<int> stack_vec(SIZE); //와이?
int top_pointer = -1;

bool full() {
	return top_pointer == (SIZE - 1);
}

void push(int x) {
	stack_vec[++top_pointer] = x;
}

void pop() {
	top_pointer--;
}

int size() {
	return top_pointer + 1;
}

bool empty() {
	return top_pointer == -1;
}

int top() {
	return stack_vec[top_pointer];
}

int main() {
	int n, x;
	string cmd;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			if(!full())
				push(x);
			continue;
		}
		if (cmd == "pop") {
			if(empty()){
				cout << "-1\n";
			} else {
				cout << top() << '\n';
				pop();
			}
			continue;
		}
		if (cmd == "size") {
			cout << size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << empty() << '\n';
			continue;
		}
		if (cmd == "top") {
			if (empty()) {
				cout << "-1\n";
			}else {
				cout << top() << '\n';
			}
		}
	}
	return 0;
}*/

//10828 스택 (<stack> 사용)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int SIZE = 1e4;
vector<int> stack_vec(SIZE); //와이?
int top_pointer = -1;

int main() {
	int n, x;
	string cmd;
	stack<int> st;

	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			st.push(x);
			continue;
		}
		if (cmd == "pop") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << '\n';
				st.pop();
			}
			continue;
		}
		if (cmd == "size") {
			cout << st.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << st.empty() << '\n';
			continue;
		}
		if (cmd == "top") {
			if (st.empty()) {
				cout << "-1\n";
			}
			else {
				cout << st.top() << '\n';
			}
		}
	}
	//스택의 순회: 위부터 차례대로 출력
	/*while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
	return 0;*/
}