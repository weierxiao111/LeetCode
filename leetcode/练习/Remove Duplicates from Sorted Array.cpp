#if 0
#include <iostream>
using namespace std;
#include <algorithm>

int removeDuplicates(int A[], int n) {
	if (n < 1)
		return 0;
	int last = A[0];
	int i = 1;
	int j = 1;
	for (; i < n; ++i)
	{
		if (A[i] != last)
		{
			last = A[j] = A[i];
			j++;
		}
	}
	return j;
}


int removeDuplicates2(int *nums, int n) {
	if (n < 2)
		return n;
	int i = 2;
	int j = 2;
	for (; i < n; ++i)
	{
		if (A[i] != A[j - 2])
		{
			A[j++] = A[i];
		}
	}
	return j;
}
}

int main()
{
	int  arr[] = { 1,1,1,2,2, 3};
	cout << removeDuplicates2(arr,6)<<endl;
	return 0;
}
#endif