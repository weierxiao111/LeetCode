#if 0
#include <iostream>
using namespace std;


void sortColors(int A[], int n) {
	int start = 0;
	int end = n - 1;
	for (int i = 0; i <= end;)
	{
		//i和start同时开始，如果A[i]等于2会被交换到后边，所以可以同时++
		//除了开始，其他时间start的位置不可能是2和0。
		if (A[i] == 0)
			swap(A[i++], A[start++]);
		else if (A[i] == 2)
			swap(A[i], A[end--]);
		//和end交换回来的数可能是任意的，所以不能++。
		else
			++i;
	}
}
#endif