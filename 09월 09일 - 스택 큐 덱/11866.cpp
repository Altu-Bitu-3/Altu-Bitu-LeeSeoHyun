//���� ���� Ǯ���� �ڵ�
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

//�߰����� ���� ���� �ڵ忡 �ּ� �� ��
#include <iostream> //c++ ����� ���
#include <vector> //vector ���
#include <queue> //queue ���

using namespace std; //std ���̺귯�� ���
/*
 * ť�� ó���� ���� �����Ͽ� ���� ����
 * ť�� �ƹ��͵� �������� ���� ������ N ��° ���Ҹ� ť���� ����
*/

vector<int> josephusProb(int n, int k) //�������� ���͸� �����ϱ� ����, ���������� �Լ� ����. n, k�� ����.
{
    queue<int> q; //ť ����
    vector<int> result; //����� ������ ���� ����
    for (int i = 1; i <= n; i++) { //ť�� 1���� n������ ���Ҹ� �ִ´�
        q.push(i);
    }
    int cnt = 0; //ī��Ʈ ���� �����Ͽ� 0���� �ʱ�ȭ
    while (!q.empty()) { //while�� �ݺ�, ť�� ��� �Ǹ� Ż��
        int x = q.front(); //ť�� ù��° ���Ҹ� ������ �ǵ�, ��쿡 ���� ���߿� �ٽ� �����ϱ� ���� ���� x�� ����
        q.pop(); //ť�� ù��° ���Ҹ� ����. q.front()�� ���ŵ�
        cnt++; //q.pop() Ƚ�� ī��Ʈ
        if (cnt == k) { //k��° pop�ϴ� ���Ҷ��
            result.push_back(x); //result ���Ϳ� x�� ����
            cnt = 0; //cnt�� 0���� �ʱ�ȭ, q.pop() Ƚ�� ī��Ʈ �ٽ� ���� (���� �ݺ� ���� 1)
            continue; //q.push(x) ���� �������ν� ť�� ���� ���� ����
        }
        q.push(x); //k��° pop �ϴ� ���Ұ� �ƴ� ��츸 �����, pop�� ���� �ٽ� �ڿ� push
    }
    return result; //������ ����ִ� result ���� ����
}

int main() //main �Լ�
{
    int n, k; //��� �� N�� �Է¹ޱ� ���� ���� n, K������ ���� ���� k ����
    vector<int> v; //������ �Է¹ް� ����� ������ ���� v ����
    // �Է�
    cin >> n >> k; //n, k�� �Է¹ޱ�
    // ����
    v = josephusProb(n, k); //������ ������ ������ �Լ� josephusProb(n, k)�� ���� ���� �� �ֱ�
    // ���
    cout << "<"; //���� ��ȣ ���
    for (int i = 0; i < n - 1; i++) { //for�� n�� �ݺ��ؼ�
        cout << v[i] << ", "; //v[i]�� ���
    }
    cout << v[n - 1] << ">"; //���� ��ȣ ���
}