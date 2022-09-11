#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n, min = 0;
	cin >> n;
	int* arr_a = new int[n];
	int* arr_b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr_a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> arr_b[i];
	}
	sort(arr_a, arr_a + n);
	sort(arr_b, arr_b + n);
	for (int i = 0; i < n; i++) {
		min += arr_a[i] * arr_b[n - 1 - i];
	}
	cout << min;
	delete[] arr_a;
	delete[] arr_b;
	return 0;
}