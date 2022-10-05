#include <iostream> //입출력을 위한 헤더
#include <vector> //자료구조 vector 사용 위한 헤더
#include <algorithm> //max()함수 사용 위한 헤더

using namespace std; //표준 라이브러리 사용

// 시간 복잡도 O(n^2)
int solution(int n, vector<int>& arr) { //정답을 출력할 함수
    vector<int> dp(n, 1); //길이가 n인 벡터 선언, 1로 초기화
    int ans = 1; //부분 수열의 길이를 저장할 변수 ans 선언히여 1로 초기화

    for (int i = 1; i < n; i++) { //n-1번 반복
        for (int j = 0; j < i; j++) { //arr[i]에 대하여 그보다 인덱스가 작은 arr[j]들을 비교하기 위해 이중for문
            if (arr[i] > arr[j]) { //증가하는 관계라면
                dp[i] = max(dp[i], dp[j] + 1); //이전에 구했었던 i까지의 부분 수열 길이 dp[i]와 j까지의 부분 수열 길이에 1을 더한 dp[j]+1중 큰 값을 dp[i]에 대입
            }
        }
        ans = max(ans, dp[i]); //최장 길이 갱신
    }
    return ans; //ans를 값으로 반환
}

int main() { //입출력 메인 함수
    int n; //수열 크기 n

    //입력
    cin >> n; //n 입력받기
    vector<int> arr(n, 0); //전체 수열의 값이 들어갈 벡터 arr 선언하여 n개 원소 생성, 0으로 초기화

    for (int i = 0; i < n; i++) { //n번 반복하는 동안
        cin >> arr[i]; //arr에 수열 원소 하나씩 넣어줌
    }

    //연산 & 출력
    cout << solution(n, arr); //정답 함수 실행 후 반환된 리턴값 출력

}