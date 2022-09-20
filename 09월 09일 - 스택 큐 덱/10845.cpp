//10845 ť (����)

/*#include <iostream>
#include <vector>

using namespace std;
const int SIZE = 1e4 + 1; //1: ������ ���Ұ� ������� �ʴ� ���� �ε���. 0�� �ε���.

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0;

bool full() {
	return (rear_pointer + 1) % SIZE == front_pointer;
}

void push(int x) {
	rear_pointer = (rear_pointer + 1) % SIZE; //0�� �ε��� �� ���, ���������� ��ġ
	queue_vec[rear_pointer] = x;
}

void pop() {
	front_pointer = (front_pointer + 1) % SIZE;
} //���ʿ��� �����ǹǷ�

int size() {
	int tmp = rear_pointer - front_pointer;
	if (tmp < 0) {
		tmp += SIZE;
	}
	return tmp;
}

bool empty() {
	return rear_pointer == front_pointer;
}

int front() {
	return queue_vec[(front_pointer + 1)] % SIZE;
	//front_pointer �ε����� ������ �ε����� ���´�
}

int back() {
	return queue_vec[rear_pointer];
	//rear_pointer �ε���
}

int main() {
	int n, x;
	string cmd;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			if (!full()) {
				push(x);
			}
			continue;
		}
		if (cmd == "pop") {
			if (empty()) {
				cout << "-1\n";
			}
			else {
				cout << front() << '\n';
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
		if (cmd == "front") {
			if (empty()) {
				cout << "-1\n";
			}
			else {
				cout << front() << '\n';
			}
			continue;
		}
		if (cmd == "back") {
			if (empty()) {
				cout << "-1\n";
			}
			else {
				cout << back() << '\n';
			}
		}
	}
	return 0;
}*/

//10845 ť (<queue> ���)

#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int SIZE = 1e4 + 1; //1: ������ ���Ұ� ������� �ʴ� ���� �ε���. 0�� �ε���.

vector<int> queue_vec(SIZE);
int front_pointer = 0, rear_pointer = 0;

int main() {
	int n, x;
	string cmd;
	queue<int> q;
	cin >> n;
	while (n--) {
		cin >> cmd;
		if (cmd == "push") {
			cin >> x;
			q.push(x);
			continue;
		}
		if (cmd == "pop") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << '\n';
				q.pop();
			}
			continue;
		}
		if (cmd == "size") {
			cout << q.size() << '\n';
			continue;
		}
		if (cmd == "empty") {
			cout << q.empty() << '\n';
			continue;
		}
		if (cmd == "front") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.front() << '\n';
			}
			continue;
		}
		if (cmd == "back") {
			if (q.empty()) {
				cout << "-1\n";
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}
	return 0;
}