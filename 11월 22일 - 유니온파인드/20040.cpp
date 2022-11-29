/*
#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;

//Find 연산
int findParent(int node) {
    if (parent[node] < 0) { //값이 음수면 루트 정점이므로 리턴
        return node;
    }
    return parent[node] = findParent(parent[node]); //그래프 압축하며 정점 찾기
}

//Union 연산
void unionInput(int x, int y) {
    int xp = findParent(x); //부모 노드 찾기
    int yp = findParent(y); //부모 노드 찾기

    if (xp == yp) { //이미 같은 집합에 있는 경우
        return;
    }
    if (parent[xp] < parent[yp]) { //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else { //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
}

int liarParty(vector<int>& parties) {
    int cnt = 0; //거짓말을 할 수 있는 파티 수
    for (int i = 0; i < parties.size(); i++) {
        if (findParent(parties[i]) != findParent(0)) { //0과 같은 집합이 아니면 파티 수 증가
            cnt++;
        }
    }
    return cnt;
}

/**
 * [거짓말]
 *
 * 1. 각 사람들은 다양한 파티를 통해 연결됐다고 할 수 있음
 * 2. 연결된 사람들은 같은 집합에 속함
 * 3. 각 집합에 속한 사람들 중 한 명이라도 진실을 안다면 그 집합의 사람들이 속한 파티에는 거짓말을 할 수 없음
 * -> 유니온 파인드로 사람들을 집합으로 묶은 뒤, 파티마다 거짓말을 할 수 있는지 확인하기
 * -> 이때, 진실을 아는 사람들의 루트 정점을 0으로 설정해서 유니온 파인드를 통해 집합으로 묶고 시작
 * -> 0과 같은 집합이 아니어야 거짓말을 할 수 있음
 *
 * !주의! 파티 정보를 입력받으며 바로 거짓말 가능 여부를 판단할 수 없음 (예제 입력 4)
 *       각 파티에서 한 사람만 저장해둔 뒤, 마지막에 거짓말 가능 여부 한 번에 판단
 */


/*
int main() {
    int n, m; //사람의 수 n, 파티의 수 m

    //입력
    cin >> n >> m;
    parent.assign(n + 1, -1);

    int init, p; //이야기의 진실을 아는 사람의 수, 번호
    cin >> init;
    while (init--) { //진실을 아는 사람들
        cin >> p;
        unionInput(0, p); //진실을 아는 사람 번호 저장, root 0
    }

    int cnt, first_person, person; //각 파티마다 오는 사람의 수, 번호
    vector<int> parties;
    while (m--) { //파티 m개
        cin >> cnt >> first_person;

        //연산
        parties.push_back(first_person); //파티 정보로 각 파티의 첫번째 사람만 저장
        while (--cnt) { //첫번째 사람을 제외한 나머지 사람 번호 입력받음
            cin >> person;
            unionInput(first_person, person); //첫번째 사람과 노드 연결
        }
    }

    //연산 & 출력
    cout << liarParty(parties);
    return 0;
}
*/


#include <iostream>
#include <vector>
using namespace std;

vector<int> parent; 

//Find 연산
int find(int x){
    if (parent[x] < 0) { //값이 음수면 루트 정점이므로 리턴
        return x;
    }
    return parent[x] = find(parent[x]); //그래프 압축하며 정점 찾기
}

//Union 연산
bool unionInput(int x, int y){
    int xp = find(x); //부모 노드 찾기
    int yp = find(y); //부모 노드 찾기

    if (xp == yp){ //같은 트리에 속하는 경우 -> 사이클이다
        return false;
    }
    
    if (parent[xp] < parent[yp]){ //새로운 루트 xp
        parent[xp] += parent[yp];
        parent[yp] = xp;
    }
    else{ //새로운 루트 yp
        parent[yp] += parent[xp];
        parent[xp] = yp;
    }
    return true;
}


int main() {
    int n, m, x, y; //게임에서 사용하는 점 개수 n, 진행된 차례의 수 m

    //입력
    cin >> n >> m;
    parent.assign(n, -1); //크기 n인 백터 생성해 -1로 초기화
    for (int i = 0; i < m; i++) {
        cin >> x >> y; //i번째 차례에 해당 플레이어가 선택한 두 점의 번호

        //연산 & 출력
        if (!unionInput(x, y)) { //사이클 생성
            cout << i + 1; //i가 0부터 시작이므로 1 더함
            return 0; //프로그램 종료
        }
    }
    cout << 0; //사이클 생성x
    return 0;
}