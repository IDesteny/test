#include <iostream>
using namespace std;

const int &foo(const int &a)
{
	return a;
}

int main()
{
	cout << foo(5) << endl;
	return 0;
}