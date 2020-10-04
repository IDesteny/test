#include <iostream>
using namespace std;

int &&foo(int &&a)
{
	return move(a);
}

int main()
{
	cout << foo(5) << "change" << endl;
	return 0;
}