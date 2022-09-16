#include <iostream>
#include<string>
using namespace std;

int getEndNumber(int n) {
	int num = 666 - 1;
	while (n > 0) {
		string s = to_string(++num);
		if (s.find("666") != s.npos) {
			n--;
		}
	}
	return num;
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	cout << getEndNumber(n);
	return 0;
}