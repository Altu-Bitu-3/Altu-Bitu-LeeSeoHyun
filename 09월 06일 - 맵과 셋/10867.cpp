//���ͷ� Ǭ �ڵ�
/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int a;
		bool overlap = false;
		cin >> a;
		if (i == 0) {
			arr.push_back(a);
			continue;
		}
		for (int j = 0; j < arr.size(); j++) {
			if (a == arr[j]) {
				overlap = true;
				break;
			}
		}
		if (overlap == false) {
			arr.push_back(a);
		}
	}
	sort(arr.begin(), arr.end());
	for (int i = 0; i < arr.size(); i++) {
		cout << arr[i] << " ";
	}
}*/

//������ Ǭ �ڵ� (�ξ� ����)
#include<iostream>
#include<set>
using namespace std;

int main() {
	int n, input;
	set<int> s;
	cin >> n;
	while (n--) {
		cin >> input;
		s.insert(input);
	}
	//set<int>::iterator iter;
	//auto Ű����� �ʱ�ȭ ���� ���� ������ Ÿ���� �ڵ����� ������
	/*
	for(auto iter = s.begin(); iter!= s.end(); iter++)
	cout << *iter << ' ';
	*/
	for (auto iter : s) {
		cout << iter << ' ';
	}
	return 0;
}