// 시간초과
#include <iostream>
#include <deque>

using namespace std;

deque<int> dd;
deque<int> sy;

int game(int m) {
	deque<int> ddgd;
	deque<int> sygd;
	int cnt = m;

	while (m) {
		ddgd.push_back(dd.back());
		dd.pop_back();

		if (dd.empty()) {
			return -1;
		}

		if ((!ddgd.empty() && ddgd.back() == 5) || (!sygd.empty() && sygd.back() == 5)) {
			while (!sygd.empty()) {
				dd.push_front(sygd.front());
				sygd.pop_front();
			}
			while (!ddgd.empty()) {
				dd.push_front(ddgd.front());
				ddgd.pop_front();
			}
		}
		else if ((!ddgd.empty() && !sygd.empty()) && ddgd.back() + sygd.back() == 5) {
			while (!ddgd.empty()) {
				sy.push_front(ddgd.front());
				ddgd.pop_front();
			}
			while (!sygd.empty()) {
				sy.push_front(sygd.front());
				sygd.pop_front();
			}
		}
		m--;

		sygd.push_back(sy.back());
		sy.pop_back();

		if (sy.empty()) {
			return 1;
		}

		if ((!ddgd.empty() && ddgd.back() == 5) || (!sygd.empty() && sygd.back() == 5)) {
			while (!sygd.empty()) {
				dd.push_front(sygd.front());
				sygd.pop_front();
			}
			while (!ddgd.empty()) {
				dd.push_front(ddgd.front());
				ddgd.pop_front();
			}
		}
		else if ((!ddgd.empty() && !sygd.empty()) && ddgd.back() + sygd.back() == 5) {
			while (!ddgd.empty()) {
				sy.push_front(ddgd.front());
				ddgd.pop_front();
			}
			while (!sygd.empty()) {
				sy.push_front(sygd.front());
				sygd.pop_front();
			}
		}
		m--;
	}
	if (dd.size() == sy.size())
		return 0;
	else if (dd.size() > sy.size())
		return 1;
	else
		return -1;
}

int main() {
	int n, m;
	int score = 0;
	cin >> n >> m;
	while (n--) {
		int a, b;
		cin >> a >> b;
		dd.push_back(a);
		sy.push_back(b);
	}
	score = game(m);
	if (score > 0)
		cout << "do";
	else if (score == 0)
		cout << "dosu";
	else
		cout << "su";
}
*/