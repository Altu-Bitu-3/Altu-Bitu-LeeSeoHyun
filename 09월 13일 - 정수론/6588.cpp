#include <iostream>
using namespace  std;

int main() {
    bool arr[1000001] = { 1, 1, }; //0, 1�϶��� �н�

    for (int i = 2; i * i < 1000000; i++)
    {
        if (arr[i]) continue; //true(1)�϶� continue�ȴ�
        for (int j = i * i; j < 1000000; j += i)
        {
            arr[j] = true;
        }
    }

    cin.tie(NULL);
    ios_base::sync_with_stdio(0);
    int n, left, right;

    while (1)
    {
        cin >> n;
        if (!n)
            break;

        left = 3; //¦���� ���ؼ� �����ϹǷ� Ȧ��+Ȧ���� ������ ��Ÿ���� ��
        right = n - 3;

        bool check = false;
        while (left <= right)
        {
            if (!arr[left] && !arr[right]) { //�� �� �Ҽ��϶�
                if ((left + right) == n) {
                    cout << n << " = " << left << " + " << right << '\n';
                    check = true;
                    break;
                }
            }
            left += 2;
            right -= 2;
        }

        if (!check)
            cout << "Goldbach's conjecture is wrong.";
    }
}