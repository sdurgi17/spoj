#include <iostream>

using namespace std;

int main()
{
	cout << []() -> string {return "hi";}();

	return 0;
}
