#include <iostream>
using namespace std;

int &&foo(int &&a)
{
	return move(a);
}

int main()
{
	cout << foo(5) << endl;
	return 0;
}