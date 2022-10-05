#include <iostream>
using namespace std;

int findC(int n) {
	// 가장 작은 생성자 리턴
	// 1부터 n까지 분해합을 구해보면서, 분해합이 n인 경우(=생성자)를 찾는다.
	int sum;
	for (int i = 1; i < n; i++) {
		int temp = i; // 반복문 내에서 i를 변경하지 않고, 임시변수 사용
		sum = i;
		while (temp > 0) {
			sum += temp % 10;
			temp /= 10;
		}
		if (sum == n) {
			return i;
		}
	}
	return 0; // 생성자가 없는 경우
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << findC(n);
	return 0;
}