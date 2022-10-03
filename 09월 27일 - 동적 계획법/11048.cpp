#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int arr[1001][1001];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			arr[i][j] += max(max(arr[i - 1][j], arr[i][j - 1]), arr[i - 1][j - 1]);
		}
	}
	cout << arr[n][m];
	return 0;
}
//1 ≤ N, M ≤ 1,000이므로 arr[1001][1001]을 만들면 된다
//참고한 블로그: https://ip99202.github.io/posts/%EB%B0%B1%EC%A4%80-11048-%EC%9D%B4%EB%8F%99%ED%95%98%EA%B8%B0-c++/