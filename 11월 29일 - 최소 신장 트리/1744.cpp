
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tieNumber(vector<int>& arr) { //수를 묶는 함수
    int total = 0; //총합 변수
    int size = arr.size(); //벡터의 크기 변수
    for (int i = 0; i < size - 1; i += 2) { //앞 원소부터 두개씩 묶어서 곱해준다
        total += arr[i] * arr[i + 1];
    }
    //수열의 숫자가 홀수개여서 수가 하나 남게 된다면 총합에 더해준다
    if (size % 2) {
        total += arr[size - 1];
    }
    return total;
}

/**
 * [수 묶기]
 *
 * 1. 양수는 양수끼리, 음수는 음수끼리 곱해야 큰 수를 만들 수 있다.
 * 2. 절댓값이 큰 것끼리 곱해야 더 큰 수를 만들 수 있다.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1은 곱하는 것보다 더해야 큰 수를 만들 수 있다. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; //수열의 크기 n, 수열의 각 수 x, 1의 갯수 세는 cnt1

    //입력
    cin >> n;
    vector<int> arr_pos, arr_neg;
    while (n--) {
        cin >> x; //수열의 각 수 입력받음
        if (x > 1) { //x가 1보다 큰 양수라면
            arr_pos.push_back(x); //양수 벡터에 수 저장
        }
        else if (x < 1) {
            arr_neg.push_back(x); //홀수 벡터에 수 저장
        }
        else {
            cnt1++; //1인 경우 카운트
        }
    }

    //절댓값이 큰 순으로 정렬 (양수는 내림차순, 음수~0은 오름차순)
    sort(arr_pos.begin(), arr_pos.end(), greater<>());
    sort(arr_neg.begin(), arr_neg.end());

    //연산 & 출력
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg);
    return 0;
}