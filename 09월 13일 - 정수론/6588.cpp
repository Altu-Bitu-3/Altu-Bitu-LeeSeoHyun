#include <iostream>
using namespace  std;
const int SIZE = 1000000;

int main() {
    bool arr[SIZE + 1] = { 1, 1, }; //0, 1일때는 패스
    for (int i = 2; i * i < SIZE; i++)
    {
        if (arr[i]) {
            continue; //true(1)일때 continue된다
        }
        for (int j = i * i; j < SIZE; j += i)
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
        if (!n) {
            break;
        }

        left = 3; //짝수에 대해서 검증하므로 홀수+홀수의 합으로 나타나게 됨
        right = n - 3;

        while (left <= right)
        {
            if (!arr[left] && !arr[right]) { //둘 다 소수일때
                if ((left + right) == n) {
                    cout << n << " = " << left << " + " << right << '\n';
                    break;
                }
            }
            left += 2;
            right -= 2;
        }

        if (left > right) {
            cout << "Goldbach's conjecture is wrong.";
        }
    }
}