#include<iostream>
#include<queue>
#include<vector>


using namespace std;

typedef pair<int, int> pii;
const int INF = 1e5 * 8 * 3;


vector<int> dijkstra(int start, int n, vector<vector<pii>>& graph) { //다익스트라 함수
	vector<int> dist(n + 1, INF);
	dist[start] = 0;
	//pq 선언
	priority_queue < pii, vector<pii>, greater<pii>> pq;
	pq.push(pii(0, start));

	//dijstra
	while (!pq.empty()) {
		int d = pq.top().first;  //현재 정점까지의 경로 길이
		int v = pq.top().second; //현재 탐색하려는 정점
		pq.pop();

		if (d > dist[v]) { //d가 dist[v]보다 클 경우 최소가 아님
			continue;
		}

		//탐색 & 거리 값 갱신
		for (int i = 0; i < graph[v].size(); i++) {
			int nxt_v = graph[v][i].first;
			int cost = graph[v][i].second;
			//거리가 작으면 갱신 후 pq에 삽입
			if (dist[nxt_v] > dist[v] + cost) {
				dist[nxt_v] = dist[v] + cost;
				pq.push(pii(dist[nxt_v], nxt_v));
			}
		}
	}
	return dist;
}

/*
필수적으로 지나야 하는 v1,v2 노드를 지나가는 방법
1) 1->v1->v2->n
2) 1->v2->v1->n
무방향 그래프이므로 1,v1,v2에 대해 다익스트라를 진행한 뒤 결과를 더해 그 중 min 값 선택
*/
int solve(int v1, int v2, int n, vector<vector<pii>>& graph) {
	vector<int> start = { 1,v1,v2 };
	vector<vector<int>> dist(3, vector<int>(n + 1, 0));

	//1,v1,v2에 대해 다익스트라 진행
	for (int i = 0; i < 3; i++) {
		dist[i] = dijkstra(start[i], n, graph);
	}

	int ans = min(dist[0][v1] + dist[1][v2] + dist[2][n], dist[0][v2] + dist[2][v1] + dist[1][n]);

	if (ans >= INF) {
		return -1;
	}
	return ans;
}

int main() {
	int  e, v1, v2, n;
	
	cin >> n >> e; //정점의 개수 n, 간선의 개수 e 입력받음
	vector<vector<pii>> graph(n + 1, vector<pii>(0));
	while (e--) { //e개의 간선에 대하여 정보 파악
		int a, b, c;
		cin >> a >> b >> c; //a번 정점과 b번 정점 사이 존재하는 양방향 길의 거리가 c.
		//입력받은 값 저장. 양방향 그래프이므로 a와 b 모두 저장 해주어야함
		graph[a].push_back(pii(b, c));
		graph[b].push_back(pii(a, c));
	}

	cin >> v1 >> v2; //반드시 거쳐야 하는 두 개의 서로 다른 정점 번호 입력받기
	cout << solve(v1, v2, n, graph); //함수 실행하여 최단 경로 길이 출력
}