#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_SCORE = 10; // ��� �ִ� ����
vector<int> answer = { -1 };
int max_diff = 0;

/* ���̾��� answer���� ���� ������ ������ ������ ���� ��ȯ*/
bool compare(vector<int>& ryan) {
    for (int i = MAX_SCORE; i >= 0; i--) {
        if (answer[i] > ryan[i]) {
            return false;
        }
        if (answer[i] < ryan[i]) {
            return true;
        }
    }
}
/* ���̾�� ����ġ�� ���� �� ��ȯ */
int getDiff(vector<int>& ryan, vector<int>& appeach) {
    int appeach_score = 0;
    int ryan_score = 0;
    for (int i = 0; i < MAX_SCORE; i++) {
        // ����ġ�� ���̾��� ��� 0���� �� ��� �ƹ��� ������ �������� ����
        if (appeach[i] == 0 && ryan[i] == 0) {
            continue;
        }
        // ����ġ�� ���̾𺸴� ���ų� �� ���� �� ���: ����ġ ����
        if (appeach[i] >= ryan[i]) {
            appeach_score += MAX_SCORE - i;
        }
        // ���̾��� ����ġ���� �� ���� �� ���: ����ġ ���� 
        else {
            ryan_score += MAX_SCORE - i;
        }
    }
    return ryan_score - appeach_score;
}

void backtracking(int cnt, int extra_arrows, vector<int>& ryan, vector<int>& appeach) {
    if (extra_arrows == 0 || cnt == MAX_SCORE + 1) {
        ryan[MAX_SCORE] = extra_arrows; // ���� ȭ���� 0�� ������ ����
        int diff = getDiff(ryan, appeach);

        if (diff > 0) {
            // 1. ���� ���� ���� ���� ū ���: max_diff ������Ʈ
            if (diff > max_diff) {
                max_diff = diff;
                answer = ryan;
            }
            // 2. ���� ���� ���� maxDiff�� ���� ���: ���� ������ ������ �� ũ�� max_diff ������Ʈ
            else if (diff == max_diff && compare(ryan)) {
                answer = ryan;
            }
        }
        ryan[MAX_SCORE] = 0; // 0�� ���� ������� �ʱ�ȭ
        return;
    }
    // cnt��° ������ �������� ��� (appeach[cnt]+1��ŭ ��� ���)
    if (extra_arrows > appeach[cnt]) {
        ryan[cnt] = appeach[cnt] + 1;
        backtracking(cnt + 1, extra_arrows - ryan[cnt], ryan, appeach);
        ryan[cnt] = 0;
    }
    // cnt��° ������ �������� �ʴ� ��� (0���� ��� ���)
    backtracking(cnt + 1, extra_arrows, ryan, appeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(MAX_SCORE + 1, 0);
    backtracking(0, n, ryan, info);
    return answer;
}

/**
 * �츮�� ��ǥ�� ���̾��� �ִ� �������� ����ġ�� �̱�� ��! ����ġ�� 6�� ���ῡ 2�� ���� �� ���̾��� 1���� ������ �ǹ� ����
 *  => ������ ��� ���: ���̾��� ����ġ���� 1���� �� ������ ���
 *     ������ ���� ���ϴ� ���: 0���� ��� ���
 *
 * 1. ���̾��� ������ ��� ����� ���� ��Ʈ��ŷ���� Ž��
 *    (����Ž������ ����� ���� ���� ��� �ð��ʰ� �߻��ϹǷ� �� ���ǿ� ���� Ž��)
 *
 * 2. ���� ȭ���� 0�� �ǰų� Ž���ϰ� �ִ� ������ ������ ����(0��)�� ��� ���� �� ���
 *    - �� �� 0���� ���: �ƹ��� ������ ���� ����
 *    - ����ġ�� ���̾𺸴� ���ų� �����ϰ� ���� ���: ����ġ ����
 *    - ���̾��� ����ġ���� ���� ���� ���: ���̾� ����
 *
 * 3. ���� �������� 0������ ū ��� -> �ִ�������(max_diff) ������Ʈ���� Ȯ��
 *    - ���� ������ > �ִ� ������: max_diff�� answer ������Ʈ
 *    - ���� ������ == �ִ� ������: ���� answer���� ���� ������ ������ ū ��쿡�� ������Ʈ
 */
int main() {
    int n = 5; vector<int> info = { 2, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 };
    // int n = 1; vector<int> info = {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    // int n = 9; vector<int> info = {0, 0, 1, 2, 0, 1, 1, 1, 1, 1, 1};
    // int n = 10; vector<int> info = {0, 0, 0, 0, 0, 0, 0, 0, 3, 4, 3};
    vector<int> result = solution(n, info);
    for (int i = 0; i <= MAX_SCORE; i++) {
        cout << result[i] << " ";
    }
    return 0;
}