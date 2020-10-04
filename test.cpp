#include <iostream>
using namespace std;

template <class T>
void sortFind(T *arr, const uint64_t &sizeArr, bool( *predicate)(const T &, const T &) = [](const T &arg1, const T &arg2) { return arg1 < arg2; })
{
	auto length = sizeArr / sizeof *arr;	//get length array
	auto i = length; 			//for auto
	auto j = length; 			//for auto

	T *item = arr; 				//for find
	T temp; 				//for swap

	for (i = 0; i < length - 1; ++i)
	{
		//find index max/min item
		for (j = i; j < length; ++j)
		{
			if (predicate(*item, arr[j]))
			{
				item = arr + j;
			}
		}
		
		//swap
		temp = *(arr + i);
		arr[i] = *item;
		*item = move(temp);
	}
}

int main()
{
	int arr[] { 5, 3, 8, 0, 6, 7 };
	
	cout << "in  >>  ";
	for (int i {}; i < 6; ++i) cout << arr[i] << ' ';
	cout << endl;

	sortFind(arr, sizeof arr);
	
	cout << "out <<  ";
	for (int i {}; i < 6; ++i) cout << arr[i] << ' ';
	cout << endl;

	return 0;
}