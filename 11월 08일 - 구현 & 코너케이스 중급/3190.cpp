/*
#include <iostream>
#include <vector>

using namespace std;
const int MOD = 1e6;

int cntPassword(int n, string& s) {
	vector<int> dp(n + 1, 0);
	if (s[0] == '0') {
		return 0;
	}
	s = ' ' + s;
	dp[0] = dp[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (s[i] == '0' && (s[i - 1] < '1' || s[i - 1] > '2')) {
			return 0;
		}
		if (s[i] != '0') { //한 글자 암호 해석 가능
			dp[i] += dp[i - 1];
		}
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i]<=6) {
			dp[i] += dp[i - 2];
		}
		dp[i] %= MOD;
	}
	return dp[n];
}

int main() {
	string s;
	cin >> s;
	cout << cntPassword(s.length(), s);
	return 0;
}
*/

#include <iostream>
#include <vector>
#include <deque>
#include <map>

using namespace std;
typedef pair<int, int> ci;

int playGame(int n, vector<vector<int>>& board, map<int, char>& cmd) {
	int dr[4] = { 0, -1, 0, 1 };
	int dc[4] = { 1, 0, -1, 0 };

	deque<ci> snake;
	snake.push_front({ 0, 0 });
	board[0][0] = 1;

	int t = 0, head_dir = 0;
	while (true) {
		t++;

		int nr = snake.front().first + dr[head_dir];
		int nc = snake.front().second + dc[head_dir];

		if (nr < 0 || nr >= n || nc < 0 || nc >= n || board[nr][nc] == 1) {
			break;
		}
		if (board[nr][nc]!=2) {
			board[snake.back().first][snake.back().second] = 0;
			snake.pop_back();
		}
		snake.push_front({ nr, nc });
		board[nr][nc] = 1;

		if (cmd[t] == 'L') {
			head_dir = (head_dir + 1) % 4;
		} else if (cmd[t] == 'D') {
			head_dir = (head_dir + 3) % 4;
		}
	}
	return t;
}

int main() {
	int n, k, row, col, l, x;
	char c;
	cin >> n >> k;
	vector<vector<int>> board(n, vector<int>(n));
	for (int i = 0; i < k; i++) {
		cin >> row >> col;
		board[row - 1][col - 1] = 2;
	}
	cin >> l;
	map<int, char> cmd;
	for (int i = 0; i < l; i++) {
		cin >> x >> c;
		cmd[x] = c;
	}

	cout << playGame(n, board, cmd);
	return 0;
}