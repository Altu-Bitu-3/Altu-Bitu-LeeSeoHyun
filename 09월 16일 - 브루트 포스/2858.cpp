#include <iostream>
using namespace std;

pair<int, int> func(int r, int siz) {
	int l, w;
	for (w = 3; w < siz / 2; w++) {
		if (siz % w == 0) {
			l = siz / w;
			if (r == (l + w - 2) * 2) {
				return { l, w };
				break;
			}
		}
	}
}
int main() {
	int r, b;
	pair<int, int> p;
	cin >> r >> b;
	p = func(r, r + b);
	cout << p.first << " " << p.second;
}