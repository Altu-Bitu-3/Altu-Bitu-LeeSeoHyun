#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SCORE = 10; // 양궁 최대 점수
vector<int> answer = { -1 }; //정답 저장할 결과 벡터
int max_diff = 0; //최대 점수 차 저장할 변수

/* 라이언이 answer보다 낮은 점수의 비중이 높은지 여부 반환*/
bool compare(vector<int>& ryan) {
    for (int i = MAX_SCORE; i >= 0; i--) {
        if (answer[i] > ryan[i]) { //answer가 낮은 점수의 비중이 더 높을 경우 false 반환
            return false;
        }
        if (answer[i] < ryan[i]) {//ryan가 낮은 점수의 비중이 더 높을 경우 true 반환
            return true;
        }
    }
}
/* 라이언과 어피치의 점수 차 반환 */
int getDiff(vector<int>& ryan, vector<int>& appeach) {
    int appeach_score = 0; //어피치 점수
    int ryan_score = 0; //라이언 점수
    for (int i = 0; i < MAX_SCORE; i++) {
        // 어피치와 라이언이 모두 0점을 쏠 경우 아무도 점수를 가져가지 않음
        if (appeach[i] == 0 && ryan[i] == 0) {
            continue;
        }
        // 어피치가 라이언보다 같거나 더 많이 쏜 경우: 어피치 득점
        if (appeach[i] >= ryan[i]) {
            appeach_score += MAX_SCORE - i;
        }
        // 라이언이 어피치보다 더 많이 쏜 경우: 어피치 득점 
        else {
            ryan_score += MAX_SCORE - i;
        }
    }
    return ryan_score - appeach_score; //라이언과 어피치의 점수 차 반환
}

void backtracking(int cnt, int extra_arrows, vector<int>& ryan, vector<int>& appeach) { //백트래킹으로 라이언이 최대 점수 차로 승 + 낮은 점수를 많이 맞추는 경우 탐색
    if (extra_arrows == 0 || cnt == MAX_SCORE + 1) { //남은 화살이 0이 되거나 탐색하고 있는 과녁이 마지막 과녁
        ryan[MAX_SCORE] = extra_arrows; // 남은 화살은 0점 개수로 포함
        int diff = getDiff(ryan, appeach); //점수 차 계산

        if (diff > 0) { //동점 아닌 경우
            // 1. 현재 점수 차가 가장 큰 경우: max_diff 업데이트
            if (diff > max_diff) {
                max_diff = diff;
                answer = ryan; //정답을 이 경우로 업데이트
            }
            // 2. 현재 점수 차가 maxDiff과 같은 경우: 낮은 점수의 비중이 더 크면 max_diff 업데이트
            else if (diff == max_diff && compare(ryan)) {
                answer = ryan; //정답을 이 경우로 업데이트
            }
        }
        ryan[MAX_SCORE] = 0; // 0점 개수 원래대로 초기화
        return;
    }
    // cnt번째 점수를 가져가는 경우 (appeach[cnt]+1만큼 쏘는 경우)
    if (extra_arrows > appeach[cnt]) { //남은 화살 갯수가 cnt번째 점수를 맞춘 어피치 화살 갯수보다 많으면 그 갯수보다 딱 하나 더 쏜다
        ryan[cnt] = appeach[cnt] + 1; //화살 소모
        backtracking(cnt + 1, extra_arrows - ryan[cnt], ryan, appeach); //백트래킹
        ryan[cnt] = 0; //화살 복구
    }
    // cnt번째 점수를 가져가지 않는 경우 (0점을 쏘는 경우)
    backtracking(cnt + 1, extra_arrows, ryan, appeach);
}

vector<int> solution(int n, vector<int> info) { //해답 반환할 함수
    vector<int> ryan(MAX_SCORE + 1, 0); //라이언 화살 쏘는 케이스 저장할 벡터
    backtracking(0, n, ryan, info); //백트래킹으로 라이언이 화살 쏘는 경우 탐색
    return answer; //결과 벡터 리턴
}

/**
 * 우리의 목표는 라이언이 최대 점수차로 어피치를 이기는 것! 어피치가 6점 과녁에 2발 쐈을 때 라이언이 1발을 맞히면 의미 없음
 *  => 점수를 얻는 경우: 라이언이 어피치보다 1발을 더 맞히는 경우
 *     점수를 얻지 못하는 경우: 0발을 쏘는 경우
 *
 * 1. 라이언이 점수를 얻는 경우의 수를 백트래킹으로 탐색
 *    (완전탐색으로 경우의 수를 구할 경우 시간초과 발생하므로 위 조건에 따라 탐색)
 *
 * 2. 남은 화살이 0이 되거나 탐색하고 있는 과녁이 마지막 과녁(0점)인 경우 점수 차 계산
 *    - 둘 다 0점인 경우: 아무도 점수를 얻지 않음
 *    - 어피치가 라이언보다 많거나 동일하게 맞힌 경우: 어피치 득점
 *    - 라이언이 어피치보다 많이 맞힌 경우: 라이언 득점
 *
 * 3. 얻은 점수차가 0점보다 큰 경우 -> 최대점수차(max_diff) 업데이트할지 확인
 *    - 현재 점수차 > 최대 점수차: max_diff와 answer 업데이트
 *    - 현재 점수차 == 최대 점수차: 현재 answer보다 낮은 점수의 배점이 큰 경우에만 업데이트
 */
int main() {
    int n = 5; vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 }; //테스트 케이스
    // int n = 1; vector<int> info = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // int n = 9; vector<int> info = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    // int n = 10; vector<int> info = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3};
    vector<int> result = solution(n, info);
    for (int i = 0; i <= MAX_SCORE; i++) {
        cout << result[i] << " "; //정답 출력
    }
    return 0;
}