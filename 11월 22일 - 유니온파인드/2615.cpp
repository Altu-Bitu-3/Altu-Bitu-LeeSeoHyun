#include <iostream>
using namespace std;

int arr[21][21];
int x, y;
int bfRowCol() {
	int black_cnt_row = 0, white_cnt_row = 0;
	int black_cnt_col = 0, white_cnt_col = 0;
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			if (arr[i][j] != arr[i][j - 1]) {
				if (black_cnt_row == 5) {
					y = i;
					x = j - 1 - 4;
					return 1;
				}
				else if (white_cnt_row == 5) {
					y = i;
					x = j - 1 - 4;
					return 2;
				}
			}
			if (arr[i][j] == 1) {
				black_cnt_row++;
				white_cnt_row = 0;
			}
			else if (arr[i][j] == 2) {
				white_cnt_row++;
				black_cnt_row = 0;
			}
			else {
				white_cnt_row = 0;
				black_cnt_row = 0;
			}


			if (arr[j][i] != arr[j-1][i]) {
				if (black_cnt_col == 5) {
					y = j - 1 - 4;
					x = i;
					return 1;
				}
				else if (white_cnt_col == 5) {
					y = j - 1 - 4;
					x = i;
					return 2;
				}
			}
			if (arr[j][i] == 1) {
				black_cnt_col++;
				white_cnt_col = 0;
			}
			else if (arr[j][i] == 2) {
				white_cnt_col++;
				black_cnt_col = 0;
			}
			else {
				white_cnt_col = 0;
				black_cnt_col = 0;
			}
		}
	}
	return -1;
}

int bfDiagonal1() {
	int black_cnt_left = 0, white_cnt_left = 0;
	int black_cnt_right = 0, white_cnt_right = 0;
	for (int i = 1; i <= 20; i++) {
		int row = 1;
		for (int j = i; j >= 1; j--) {
			if (arr[row][j] != arr[row - 1][j + 1]) {
				if (black_cnt_left == 5) {
					y = row - 1 - 4;
					x = j + 1 + 4;
					return 1;
				}
				else if (white_cnt_left == 5) {
					y = row - 1 - 4;
					x = j + 1 + 4;
					return 2;
				}
			}
			if (arr[row][j] == 1) {
				black_cnt_left++;
				white_cnt_left = 0;
			}
			else if (arr[row][j] == 2) {
				white_cnt_left++;
				black_cnt_left = 0;
			}
			else {
				white_cnt_left = 0;
				black_cnt_left = 0;
			}

			if (arr[row][20 - j] != arr[row - 1][19 - j]) {
				if (black_cnt_right == 5) {
					y = row - 1 - 4;
					x = 19 - j - 4;
					return 1;
				}
				else if (white_cnt_right == 5) {
					y = row - 1 - 4;
					x = 19 - j - 4;
					return 2;
				}
			}
			if (arr[row][20 - j] == 1) {
				black_cnt_right++;
				white_cnt_right = 0;
			}
			else if (arr[row][20 - j] == 2) {
				white_cnt_right++;
				black_cnt_right = 0;
			}
			else {
				white_cnt_right = 0;
				black_cnt_right = 0;
			}
			row++;
		}
	}
	return -1;
}
int bfDiagonal2() {
	int black_cnt_left = 0, white_cnt_left = 0;
	int black_cnt_right = 0, white_cnt_right = 0;
	for (int i = 19; i >= 0; i--) {
		int row = 19;
		for (int j = 20 - i; j >= 0; j--) {
			if (arr[row][j] != arr[row + 1][j + 1]) {
				if (black_cnt_left == 5) {
					y = row + 1;
					x = j + 1;
					return 1;
				}
				else if (white_cnt_left == 5) {
					y = row + 1;
					x = j + 1;
					return 2;
				}
			}
			if (arr[row][j] == 1) {
				black_cnt_left++;
				white_cnt_left = 0;
			}
			else if (arr[row][j] == 2) {
				white_cnt_left++;
				black_cnt_left = 0;
			}
			else {
				white_cnt_left = 0;
				black_cnt_left = 0;
			}

			if (arr[row][20 - j] != arr[row + 1][19 - j]) {
				if (black_cnt_right == 5) {
					y = row + 1;
					x = 19 - j;
					return 1;
				}
				else if (white_cnt_right == 5) {
					y = row + 1;
					x = 19 - j;
					return 2;
				}
			}
			if (arr[row][20 - j] == 1) {
				black_cnt_right++;
				white_cnt_right = 0;
			}
			else if (arr[row][20 - j] == 2) {
				white_cnt_right++;
				black_cnt_right = 0;
			}
			else {
				white_cnt_right = 0;
				black_cnt_right = 0;
			}
			row--;
		}
	}
	return -1;
}

int main() {
	int result = 0;
	for (int i = 1; i <= 19; i++) {
		for (int j = 1; j <= 19; j++) {
			cin >> arr[i][j];
		}
	}

	result = bfRowCol();
	if (result != -1) {
		cout << result << '\n' << y << ' ' << x;
	}
	else {
		result = bfDiagonal1();
		if (result != -1) {
			cout << result << '\n' << y << ' ' << x;
		}
		else {
			result = bfDiagonal2();
			if (result != -1) {
				cout << result << '\n' << y << ' ' << x;
			}
			else {
				cout << 0;
			}
		}
	}
	return 0;
}