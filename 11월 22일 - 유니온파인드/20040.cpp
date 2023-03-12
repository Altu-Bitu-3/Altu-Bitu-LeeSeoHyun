/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find ����
int findParent(int node) {
    if (parent[node] < 0) { //���� ������ ��Ʈ �����̹Ƿ� ����
        return node;
    }
    return parent[node] = findParent(parent[node]); //�׷��� �����ϸ� ���� ã��
}

//Union ����
void unionInput(int x, int y) {
    int xp = findParent(x); //�θ� ��� ã��
    int yp = findParent(y); //�θ� ��� ã��

    if (xp == yp) { //�̹� ���� ���տ� �ִ� ���
        return;
    }
    if (parent[xp] < parent[yp]) { //���ο� ��Ʈ xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { //���ο� ��Ʈ yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int liarParty(vector<int>& parties) {
    int cnt = 0; //�������� �� �� �ִ� ��Ƽ ��
    for (int i = 0; i < parties.size(); i++) {
        if (findParent(parties[i]) != findParent(0)) { //0�� ���� ������ �ƴϸ� ��Ƽ �� ����
            cnt++;
        }
    }
    return cnt;
}

/**
 * [������]
 *
 * 1. �� ������� �پ��� ��Ƽ�� ���� ����ƴٰ� �� �� ����
 * 2. ����� ������� ���� ���տ� ����
 * 3. �� ���տ� ���� ����� �� �� ���̶� ������ �ȴٸ� �� ������ ������� ���� ��Ƽ���� �������� �� �� ����
 * -> ���Ͽ� ���ε�� ������� �������� ���� ��, ��Ƽ���� �������� �� �� �ִ��� Ȯ���ϱ�
 * -> �̶�, ������ �ƴ� ������� ��Ʈ ������ 0���� �����ؼ� ���Ͽ� ���ε带 ���� �������� ���� ����
 * -> 0�� ���� ������ �ƴϾ�� �������� �� �� ����
 *
 * !����! ��Ƽ ������ �Է¹����� �ٷ� ������ ���� ���θ� �Ǵ��� �� ���� (���� �Է� 4)
 *       �� ��Ƽ���� �� ����� �����ص� ��, �������� ������ ���� ���� �� ���� �Ǵ�
 */


/*
int main() {
    int n, m; //����� �� n, ��Ƽ�� �� m

    //�Է�
    cin >> n >> m;
    parent.assign(n + 1, -1);

    int init, p; //�̾߱��� ������ �ƴ� ����� ��, ��ȣ
    cin >> init;
    while (init--) { //������ �ƴ� �����
        cin >> p;
        unionInput(0, p); //������ �ƴ� ��� ��ȣ ����, root 0
    }

    int cnt, first_person, person; //�� ��Ƽ���� ���� ����� ��, ��ȣ
    vector<int> parties;
    while (m--) { //��Ƽ m��
        cin >> cnt >> first_person;

        //����
        parties.push_back(first_person); //��Ƽ ������ �� ��Ƽ�� ù��° ����� ����
        while (--cnt) { //ù��° ����� ������ ������ ��� ��ȣ �Է¹���
            cin >> person;
            unionInput(first_person, person); //ù��° ����� ��� ����
        }
    }

    //���� & ���
    cout << liarParty(parties);
    return 0;
}
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> parent; 

//Find ����
int find(int x){
    if (parent[x] < 0) { //���� ������ ��Ʈ �����̹Ƿ� ����
        return x;
    }
    return parent[x] = find(parent[x]); //�׷��� �����ϸ� ���� ã��
}

//Union ����
bool unionInput(int x, int y){
    int xp = find(x); //�θ� ��� ã��
    int yp = find(y); //�θ� ��� ã��

    if (xp == yp){ //���� Ʈ���� ���ϴ� ��� -> ����Ŭ�̴�
        return false;
    }
    
    if (parent[xp] < parent[yp]){ //���ο� ��Ʈ xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{ //���ο� ��Ʈ yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}


int main() {
    int n, m, x, y; //���ӿ��� ����ϴ� �� ���� n, ����� ������ �� m

    //�Է�
    cin >> n >> m;
    parent.assign(n, -1); //ũ�� n�� ���� ������ -1�� �ʱ�ȭ
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //i��° ���ʿ� �ش� �÷��̾ ������ �� ���� ��ȣ

        //���� & ���
        if (!unionInput(x, y)) { //����Ŭ ����
            cout << i + 1; //i�� 0���� �����̹Ƿ� 1 ����
            return 0; //���α׷� ����
        }
    }
    cout << 0; //����Ŭ ����x
    return 0;
}