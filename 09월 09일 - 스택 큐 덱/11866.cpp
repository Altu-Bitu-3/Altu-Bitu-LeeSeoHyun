//내가 먼저 풀었던 코드
/*
#include <iostream>
#include <deque>

using namespace std;
int n;
deque<int> dq(n);

void rotate(int k) {
	for (int i = 1; i < k; i++) {
		dq.push_back(dq.front());
		dq.pop_front();
	}
	cout << dq.front();
	dq.pop_front();
}

int main() {
	int k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		dq.push_back(i);
	}
	cout << '<';
	while (n--) {
		rotate(k);
		if (dq.size() != 0) {
			cout << ", ";
		}
	}
	cout << '>';
}*/

//추가제출 위해 샘플 코드에 주석 단 것
#include <iostream> //c++ 입출력 헤더
#include <vector> //vector 헤더
#include <queue> //queue 헤더

using namespace std; //std 라이브러리 사용
/*
 * 큐의 처음과 끝을 연결하여 원을 구현
 * 큐에 아무것도 남아있지 않을 때까지 N 번째 원소를 큐에서 제거
*/

vector<int> josephusProb(int n, int k) //정답으로 벡터를 리턴하기 위해, 벡터형으로 함수 선언. n, k값 복사.
{
    queue<int> q; //큐 선언
    vector<int> result; //결과를 저장할 벡터 선언
    for (int i = 1; i <= n; i++) { //큐에 1부터 n까지의 원소를 넣는다
        q.push(i);
    }
    int cnt = 0; //카운트 변수 선언하여 0으로 초기화
    while (!q.empty()) { //while문 반복, 큐가 비게 되면 탈출
        int x = q.front(); //큐의 첫번째 원소를 제거할 건데, 경우에 따라 나중에 다시 삽입하기 위해 변수 x에 저장
        q.pop(); //큐의 첫번째 원소를 제거. q.front()가 제거됨
        cnt++; //q.pop() 횟수 카운트
        if (cnt == k) { //k번째 pop하는 원소라면
            result.push_back(x); //result 벡터에 x를 삽입
            cnt = 0; //cnt를 0으로 초기화, q.pop() 횟수 카운트 다시 시작 (다음 반복 때가 1)
            continue; //q.push(x) 하지 않음으로써 큐의 원소 갯수 감소
        }
        q.push(x); //k번째 pop 하는 원소가 아닐 경우만 실행됨, pop한 원소 다시 뒤에 push
    }
    return result; //정답이 들어있는 result 벡터 리턴
}

int main() //main 함수
{
    int n, k; //사람 수 N을 입력받기 위한 변수 n, K번쨰를 위한 변수 k 선언
    vector<int> v; //정답을 입력받고 출력할 벡터형 변수 v 선언
    // 입력
    cin >> n >> k; //n, k에 입력받기
    // 연산
    v = josephusProb(n, k); //벡터형 변수에 벡터형 함수 josephusProb(n, k)를 통해 얻은 값 넣기
    // 출력
    cout << "<"; //꺽쇠 기호 출력
    for (int i = 0; i < n - 1; i++) { //for문 n번 반복해서
        cout << v[i] << ", "; //v[i]값 출력
    }
    cout << v[n - 1] << ">"; //꺽쇠 기호 출력
}