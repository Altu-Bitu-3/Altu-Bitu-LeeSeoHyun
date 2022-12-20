#include <iostream>
#include <vector>

using namespace std;

//도둑이 자동 방범장치에 붙잡히지 않도록 연속된 M개의 집에서 돈을 훔치는 방법의 가짓수 구하는 함수
int steal(int n, int m, int k, vector<int>& house) {
    //윈도우 초기화
    int money = 0;
    for (int i = 0; i < m; i++) { //우선 인덱스 0~m-1 집의 값을 입력받아서 초기화한다
        money += house[i];
    }
    int ans = money < k; //훔쳐야 하는 집 초기화

    if (n == m) { //훔칠 수 있는 경우 딱 1개인 경우
        return ans;
    }
    for (int i = m; i < n + m - 1; i++) { //원형 배열이므로 모든 경우의 수를 딱 1번씩 확인하기 위해 n번 돈다
        money -= house[i - m]; //i-m을 하기 위해서 위에서 i가 m부터 출발한다
        money += house[i % n]; //모듈러 연산으로 i가 n 이상인 경우를 처리해준다
        if (money < k) {
            ans++; //훔칠 수 있는 방법의 수가 1개 늘어남
        }
    }
    return ans; //훔칠 수 있는 방법의 수 정답 반환
}

/**
 * [도둑]
 *
 * 1. 연속해서 훔쳐야 할 집이 m으로 고정됐기 때문에 슬라이딩 윈도우
 * 2. 직선이 아니라 원 형태의 배열! 모듈러 연산을 통해 윈도우의 양 끝 위치 조절하기
 * !주의! 마을에 있는 집의 개수와 도둑이 훔칠 집의 개수가 같을 때(n==m) 도둑이 훔칠 수 있는 경우의 수 1개!
 *    => 예를 들어, n = m = 3, k = 4, house = [1, 1, 1] 일 때, 실제 방법의 수는 1번, 2번, 3번 집을 택하는 경우밖에 없지만
 *       예외 처리를 안해줄 경우, 원형으로 돌며 3을 출력하게 됨!
 */

int main() {
    //테스트 케이스의 갯수 t, 각각의 케이스의 첫째 줄 마을에 있는 집의 개수 n
    //도둑이 돈을 훔칠 연속된 집의 개수 m, 자동 방범 장치가 작동하는 최소 돈의 양 k
    int t, n, m, k;
    cin >> t;
    while (t--) { //한 케이스 시작
        //입력
        cin >> n >> m >> k;
        vector<int> house(n, 0); //n개의 집에서 각각 보관중인 돈의 양
        for (int i = 0; i < n; i++) { //시계방향 순서대로 각각의 집의 돈의 양 입력받기
            cin >> house[i];
        }

        //연산 & 출력
        cout << steal(n, m, k, house) << '\n';
    }
    return 0;
}