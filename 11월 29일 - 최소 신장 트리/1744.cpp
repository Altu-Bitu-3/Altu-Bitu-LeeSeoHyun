
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int tieNumber(vector<int>& arr) { //���� ���� �Լ�
    int total = 0; //���� ����
    int size = arr.size(); //������ ũ�� ����
    for (int i = 0; i < size - 1; i += 2) { //�� ���Һ��� �ΰ��� ��� �����ش�
        total += arr[i] * arr[i + 1];
    }
    //������ ���ڰ� Ȧ�������� ���� �ϳ� ���� �ȴٸ� ���տ� �����ش�
    if (size % 2) {
        total += arr[size - 1];
    }
    return total;
}

/**
 * [�� ����]
 *
 * 1. ����� �������, ������ �������� ���ؾ� ū ���� ���� �� �ִ�.
 * 2. ������ ū �ͳ��� ���ؾ� �� ū ���� ���� �� �ִ�.
 *     ex) 1, 2, 3, 4 => 4 * 1 + 3 * 2 = 10
 *                    => 4 * 3 + 2 * 1 = 14
 * 3. 1�� ���ϴ� �ͺ��� ���ؾ� ū ���� ���� �� �ִ�. (x * 1 = x < x + 1)
 */
int main() {
    int n, x, cnt1 = 0; //������ ũ�� n, ������ �� �� x, 1�� ���� ���� cnt1

    //�Է�
    cin >> n;
    vector<int> arr_pos, arr_neg;
    while (n--) {
        cin >> x; //������ �� �� �Է¹���
        if (x > 1) { //x�� 1���� ū ������
            arr_pos.push_back(x); //��� ���Ϳ� �� ����
        }
        else if (x < 1) {
            arr_neg.push_back(x); //Ȧ�� ���Ϳ� �� ����
        }
        else {
            cnt1++; //1�� ��� ī��Ʈ
        }
    }

    //������ ū ������ ���� (����� ��������, ����~0�� ��������)
    sort(arr_pos.begin(), arr_pos.end(), greater<>());
    sort(arr_neg.begin(), arr_neg.end());

    //���� & ���
    cout << cnt1 + tieNumber(arr_pos) + tieNumber(arr_neg);
    return 0;
}