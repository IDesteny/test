#include <iostream>
using namespace std;

template <class T>
void sortFind(T *arr, const uint64_t &sizeArr)
{
	auto length = sizeArr / sizeof *arr;
	
	auto indexMaxItem = length, //for auto
			i = length,
			j = length;

	for (i = 0; i < length - 1; ++i)
	{
		
	}
}

int main()
{
	int arr[] { 5, 3, 8, 3, 6, 2 };
	
	for (int i {}; i < 6; ++i) cout << arr[i] << ' ';
	cout << endl;

	sortFind(arr, sizeof arr);
	
	for (int i {}; i < 6; ++i) cout << arr[i] << ' ';
	cout << endl;

	return 0;
}