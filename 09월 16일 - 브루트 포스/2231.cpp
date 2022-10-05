#include <iostream>
using namespace std;

int findC(int n) {
	// ���� ���� ������ ����
	// 1���� n���� �������� ���غ��鼭, �������� n�� ���(=������)�� ã�´�.
	int sum;
	for (int i = 1; i < n; i++) {
		int temp = i; // �ݺ��� ������ i�� �������� �ʰ�, �ӽú��� ���
		sum = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) {
			return i;
		}
	}
	return 0; // �����ڰ� ���� ���
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << findC(n);
	return 0;
}