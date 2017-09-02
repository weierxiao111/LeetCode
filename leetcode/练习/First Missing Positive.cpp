#if 0
#include <iostream>
using namespace std;
#include <vector>

//寻找第一个缺少的正整数，从1开始 O（N）
int firstMissingPositive(int A[], int n) 
{
	vector<int> v(n+1, 0);
	for (int i = 0; i<n; ++i)
	{
		if (A[i] <= n && A[i] >= 0)
			v[A[i]] ++;
	}
	for (int i = 1; i <= n; ++i)
	{
		if (v[i] == 0)
			return i;
	}
	return n + 1;
}
#endif
//int main()
//{
//	return 0;
//}