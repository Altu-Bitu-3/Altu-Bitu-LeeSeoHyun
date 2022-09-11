#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	long long int max = 0;
	cin >> n;
	int* arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	for (int i = 0; i < n; i++) {
		arr[i] = arr[i] - (n - 1 - i);
		if (arr[i] > 0)
			max += arr[i];
	}
	cout << max;
	delete[] arr;
	return 0;
}