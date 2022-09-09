#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n;
	queue<int> q;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size() != 1) {
		//����! �ش� ������ �ּ� �Ѱ��� ī�尡 ������ �ٸ� �������� pop ����� �� empty üũ�� �� ��� �Ѵ�
		q.pop(); // ���� �� ī�� ������
		q.push(q.front()); // ���� �ִ� ī�� �� �Ʒ���
		q.pop(); //�Ű����Ƿ� ī�� ����
	}
	cout << q.front() << '\n';
	return 0;
}