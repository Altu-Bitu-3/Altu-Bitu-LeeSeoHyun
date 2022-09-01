/*2750
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int arr[1000] = {};
	cin>>N;
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		cout << arr[i] << endl;
	}
	return 0;
}
*/

/*2751
#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++){
		cin >> arr[i];
	}
	sort(arr, arr + N);
	for (int i = 0; i < N; i++){
		cout << arr[i] << "\n";
	}
	delete[] arr;
	return 0;
}
*/
//10825
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
	int N;
	cin >> N;
	string (*arr)[4] = new string[N][4];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[N][j];
		}
	}
	sort(arr, arr + N, comp);
	for (int i = 0; i < N; i++) {
		cout << arr_name << "\n";
	}
	delete[] arr;
	return 0;
}