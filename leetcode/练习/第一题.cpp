#if 0

#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int fun(int n)
{
	int count = 1;
	int ret = 1;
	n--;
	while (n)
	{
		int temp = count;
		while (n && temp)
		{
			--n;
			ret++;
			temp--;
		}
		if (n)
		{
			ret--;
			count++;
			n--;
		}
	}
	return ret;
}

//int main()
//{
//	int n;
//	while (cin >> n)
//	{
//		cout <<fun(n)<<endl;
//	}
//	return 0;
//}

#endif