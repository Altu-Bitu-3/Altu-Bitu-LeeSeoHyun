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
		pq.push(a / 2);
		i++; //따로 빼 주지 않고 for문에 i++ 적고 break되는 괄호 안에 i--을 할 경우 i=0에서 바로 탈출했을 때 -1이 출력된다
	}
	if (h > pq.top()) {
		cout << "YES" << '\n' << i;
	}
	else {
		cout << "NO" << '\n' << pq.top();
	}
	return 0;
}