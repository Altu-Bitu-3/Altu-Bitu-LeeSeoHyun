/*#include <iostream>
#include <queue>

using namespace std;

int main() {
	int n, m;
	priority_queue<int> gift;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		gift.push(a);
	}
	for (int j = 0; j < m; j++) {
		int a;
		cin >> a;
		if (a > gift.top()) {
			cout << 0;
			return 0;
		}
		else {
			gift.push(gift.top() - a);
			gift.pop();
		}
	}
	cout << 1;
}
*/

/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, x;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	while (n--) {
		cin >> x;
		if (x == 0) {
			if (pq.empty()) {
				cout << "0\n";
			}
			else {
				cout << pq.top() << '\n';
				pq.pop();
			}
		}
		else {
			pq.push(x);
		}
	}
	return 0;
}
*/

/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	for (int i = n; i < n * n; i++) {
		int x;
		cin >> x;
		if (x > pq.top()) {
			pq.pop();
			pq.push(x);
		}
	}
	cout << pq.top() << '\n';
	return 0;
}
*/

/*
#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, h, t, i;
	cin >> n >> h >> t;
	priority_queue<int> pq;
	for (i = 0; i < n; i++) {
		int x;
		cin >> x;
		pq.push(x);
	}
	for (i = 0; i < t;) {
		if (pq.top() < h || pq.top() == 1) {
			break;
		}
		int a = pq.top();
		pq.pop();
		pq.push(a/2);
		i++;
	}
	if (h > pq.top()) {
		cout << "YES" << '\n' << i;
	}
	else {
		cout << "NO" << '\n' << pq.top();
	}
	return 0;
}
*/


/*
#include <iostream>
#include <vector>

using namespace std;

int countCoin(int n, int k, vector<int>& coin) {
	int count = 0;
	int idx = n - 1;
	while (k) {
		count += k / coin[idx];
		k %= coin[idx];
		idx--;
	}
	return count;
}

int main()
{
	int n, k;
	cin >> n >> k;
	vector<int> coin(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> coin[i];
	}
	cout << countCoin(n, k, coin);
	return 0;

}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int, int> ci;

int getMaxCount(int n, vector<ci> &meetings) {
	int count = 0;
	int prev_end = 0;
	for (int i = 0; i < n; i++) {
		int end = meetings[i].first;
		int start = meetings[i].second;
		if (start >= prev_end) {
			count++;
			prev_end = end;
		}
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	vector<ci> meetings(n, { 0, 0 });

	for (int i = 0; i < n; i++) {
		cin >> meetings[i].second >> meetings[i].first;
	}
	sort(meetings.begin(), meetings.end());
	cout << getMaxCount(n, meetings);
	return 0;
}