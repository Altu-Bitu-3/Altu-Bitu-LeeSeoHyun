#include <iostream>
#include <map>
#include <vector>
using namespace std;

//�߿��� �� ���� ����� ���ϴ� �Լ�
int jumpCar(int n, vector<string>& out_car, map<string, int>& m) {
	int ans = 0; //��� ���� �߿�?
	for (int i = 0; i < n; i++) { //���� �� ������� �˻��Ѵ�
		for (int j = i + 1; j < n; j++) { //�� ���� ������ �ε����� ������ �۾Ҵٸ�
			if (m[out_car[i]] > m[out_car[j]]) { //(���� ���� �����ٸ� �߿�)
				ans++;
				break; //�߿��� �� �� ������ �˸� ��
			}
		}
	}
	return ans;
}

int main() {
	int n;
	string car;
	map<string, int> m; //value�� ó���� ���� ����
	cin >> n;
	vector<string> out_car(n, " ");
	for (int i = 1; i <= n; i++) {
		cin >> car;
		m[car] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> out_car[i]; //[i]�� �� ���� �����̹Ƿ� �̸��� �ʿ���
	}
	cout << jumpCar(n, out_car, m);
	return 0;
}