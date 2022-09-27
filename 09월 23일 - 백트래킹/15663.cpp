#include <iostream>
#include <algorithm>

using namespace std;

int n, m, arr[8], seq[8];
bool check[8];

void backtracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << seq[i] << ' ';
		}
		cout << '\n';
		return;
	}

	int bfnum = 0;
	for (int i = 0; i < n; i++) {
		if (!check[i] && arr[i] != bfnum) {
			seq[cnt] = arr[i];
			bfnum = seq[cnt];
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	backtracking(0);
}

/*
* 참고한 블로그 : https://m.blog.naver.com/js568/221857286945
* (1) 아래의 코드는 중복되는 수열을 여러번 재출력하게 되어서 해결법 검색
*	위 블로그에서 사용한 해결법: for문 밖에 seq[cnt]저장하는 변수 만들어 if 조건에서 arr[i]와 비교
*
for (int i = 0; i < n; i++) {
		if (!check[i]) {
			if (arr[i] != seq[cnt - 1]) {
				seq[cnt] = arr[i];
				check[i] = true;
				backtracking(cnt + 1);
				check[i] = false;
			}
		}
}
*/