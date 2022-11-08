#include <iostream>
#include <deque>
#include <vector>

using namespace std;
typedef vector<vector<int>> matrix; //정수형 2차원 벡터의 자료형을 새롭게 matrix라고 정의

int countTrees(int n, vector<deque<int>>& trees) { //땅에서 나무의 갯수를 세는 함수
	int answer = 0; //나무의 갯수를 나타내는 변수 answer 선언 및 초기화
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			answer += trees[i * 10 + j].size(); //answer에 trees 벡터 내부 각각의 queue의 크기(나무 갯수)를 차례로 더함 (n*n번 실행)
		}
	}
	return answer; //나무의 갯수를 반환
}

void reproduceTree(int n, int x, int y, vector<deque<int>>& trees) //나무의 번식을 동작하는 함수
{
	for (int i = x - 1; i <= x + 1; i++) //나무는 인접한 8개의 칸에 번식
	{
		for (int j = y - 1; j <= y + 1; j++)
		{
			if ((i == x) && (j == y)) { //나무는 자신의 칸에는 번식하지 않음
				continue;
			}
			if (i >= 0 && j >= 0 && i < n && j < n) //벡터 크기 범위 벗어나는 것을 방지
			{
				trees[i * 10 + j].push_front(1); //나이가 1인 나무를 생성
			}
		}
	}
}
void solution(int n, vector<deque<int>>& trees, matrix& food, matrix& a, vector<pair<int, int>>& breeding_tree) //양분 함수
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int leftover = 0; //죽은 나무가 생성할 양분 양을 담을 leftover 함수 선언 및 초기화
			deque<int> dq;
			for (auto age : trees[i * 10 + j]) //각각의 나무에 대하여 반복문 본문을 진행한다. 나무의 나이가 담긴 age 변수 생성.
			{	//봄.
				if (food[i][j] < age) { //양분을 먹을 수 없다
					leftover += age / 2; //여름. 죽은 나무가 양분으로 변한다. 죽은 나무의 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
					continue; //가을, 겨울 진행되지 않음
				}
				food[i][j] -= age; //봄. 양분을 먹을 수 있어 나이만큼의 양분이 줄어든다
				dq.push_back(age + 1); //봄. 나이를 1 증가시킨다 (여름 진행x)
				if ((age + 1) % 5 == 0)//가을. 번식 가능한 나무를 찾기
				{
					breeding_tree.push_back({ i, j });
				}
			}
			trees[i * 10 + j] = dq; //해당칸의 나무들 현황 업데이트
			food[i][j] += (a[i][j] + leftover); //겨울. 땅에 S2D2가 추가하는 양분과 여름에 생성되었던 양분(leftover)을 추가한다.
		}
	}
}
/**16235 나무 재테크
 * [문제 설명] - 단순 구현 문제
 * 봄: 하나의 칸마다 나이가 어린 나무부터 자신의 나이만큼 양분을 먹고, 나이가 1 증가함
 *    각 칸에 양분이 부족해 자신의 나이만큼 양분을 못 먹는 나무는 즉시 죽음
 * 여름: 봄에 죽은 나무가 양분으로 변함. 죽은 나무마다 나이를 2로 나눈 값이 양분으로 추가 (소수점 버림)
 * 가을: 나이가 5의 배수인 나무가 번식. 인접한 8개 칸에 나이가 1인 나무가 생김
 * 겨울: 로봇(S2D2)이 땅을 돌아다니면서 A[r][c]만큼 각 칸에 양분 추가
 *
 * K년이 지난 후 상도의 땅에 살아있는 나무의 개수
 *
 * [문제 풀이]
 * A : 로봇(S2D2)가 겨울에 주는 양분의 양
 * food : 땅의 양분
 * breeding_tree: 나이가 5의 배수인 트리 (번식할 트리)
 * tree: 땅에 심은 나무 나이, 행, 열 정보
 * -> deque 컨테이너를 활용해 번식한 나무를 앞에 넣어주면 입력 후에만 정렬해서 사용 가능
 *
 * 문제의 설명대로 계절별 연산을 진행
 */
int main()
{
	int n, m, k; //땅의 폭 n, 나무 수 m, 햇수 k
	//입력
	cin >> n >> m >> k;
	matrix a(n, vector<int>(n, 0)); //각 칸에 매 겨울 줄 양분 양이 담길 matrix
	matrix food(n, vector<int>(n, 5)); //땅 한 칸의 양분 양이 담길 matrix. 처음에 양분은 모든 칸에 5만큼 들어있다
	vector<deque<int>> trees(n * 10 + n);

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j]; //n*n 크기 땅의 각 칸에 매 겨울 추가될 양분 양을 입력받는다
		}
	}
	for (int i = 0, x, y, z; i < m; i++) //심은 m개의 나무들 정보 입력받기
	{
		cin >> x >> y >> z;
		x--; y--; //편의상 행과 열을 0부터 시작하는 것으로 생각하므로 x, y 1씩 뺀다
		trees[x * 10 + y].push_front(z); //나무 나이 z 대입
	}
	while (k--) { //k년이 흐름
		vector<pair<int, int>> breeding_tree;
		solution(n, trees, food, a, breeding_tree); //번식대상인 나무를 파악
		for (auto [i, j] : breeding_tree)
		{
			reproduceTree(n, i, j, trees); //번식을 하는 나무에 대하여 나무 번식 함수 실행
		}
	}
	cout << countTrees(n, trees); //나무 갯수 세기
	return 0;
}