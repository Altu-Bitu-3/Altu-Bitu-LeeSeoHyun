#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	ios::ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	string input;
	map<string, int> pocket_name; //이름이 key, 번호가 value
	map<int, string> pocket_num;  //번호가 key, 이름이 value

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> input;
		pocket_name[input] = i;
		pocket_num[i] = input;
	}
	while (m--) {
		cin >> input;
		if (isdigit(input[0])) { //숫자 입력이라면
			int number = stoi(input);
			cout << pocket_num[number] << '\n';
		}
		else {
			cout << pocket_name[input] << '\n';
		}
	}
	return 0;
}