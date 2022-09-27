//15811
#include <iostream>
#include <algorithm>

using namespace std;

struct mask {
	int num;	// 알파벳과 대응될 숫자를 한번에 num으로 나타냈고
	int size;	// 복면산 계산식에서의 자릿수를 넣을 변수를 size라 함
};

mask m[10];		// 복면산에 사용되는 숫자가 0~9므로 사용되는 알파벳 10개여서 배열 크기 10으로 선언.
int newest = 0; // 사용된 알파벳 개수를 확인. 1~10까지 체크.

void func(string s, int sign) {	// 문자열과 계산 부호 위한 변수 
	for (int i = s.length() - 1; i >= 0; i--) { // 1의 자리 수부터 순회
		bool check = false;
		for (int j = 0; j < newest; j++) {
			if (m[j].num == s[i]) { // m[j].num에 s[i]와 같은 숫자(알파벳 아스키코드)가 있다면
				check = true;
				m[j].size += sign;	// sign을 더함. sign = (s에서 s[i]의 자릿수)*(계산부호)
				break;
			}
		}
		if (!check) {
			newest++;
			if (newest > 10) { // 복면산에 사용되는 알파벳은 10개여야 하므로 그 이상일 경우
				cout << "NO";
				exit(0);
			}
			m[newest - 1].num = s[i]; // m[newest-1].num에 s[i] 넣어줌
			m[newest - 1].size = sign; // m[newest-1].size에  (s에서 s[i]의 자릿수)*(계산부호) 넣어줌
		}
		sign *= 10;
	}
}

bool check[10];

void backtracking(int cnt) {
	if (cnt == newest) {
		int result = 0;
		for (int i = 0; i < newest; i++) {
			result += m[i].size * m[i].num;
		}
		if (result == 0) {
			cout << "YES" << '\n';
			exit(0);
		}
		return;
	}

	for (int i = 0; i < 10; i++) {
		if (!check[i]) {
			m[cnt].num = i;
			check[i] = true;
			backtracking(cnt + 1);
			check[i] = false;
		}
	}
}

int main() {
	string s; // "첫번째s+두번째s-마지막s=0"일때 복면산.
	for (int i = 0; i < 2; i++) {
		cin >> s;
		func(s, 1); // 문자열과 더하기 계산 위한 1
	}

	cin >> s;
	func(s, -1); // 문자열과 빼기 계산 위한 -1

	backtracking(0); // 백트래킹
	cout << "NO";
	return 0;
}

/* 참고한 것들
* (1) 15811번에서 '배열'을 사용한다는 힌트 얻음. 근데 코드 이해를 못했기 때문에 코드 작성에 있어서는 참고한 바 없음
* https://4z7l.github.io/2021/02/05/algorithms-boj-15811.html
* (2) 백트래킹 라이브코딩 - N과 M(1)에서 백트래킹 함수 구조 참고
*/