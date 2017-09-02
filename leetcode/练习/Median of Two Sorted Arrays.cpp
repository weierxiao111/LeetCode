#if 0
#include <iostream>
using namespace std;
#include <assert.h>
#include <algorithm>
//寻找两个等长排序数组共同的中位数 O（log(2n)）
int findmid(int *arr1, int *arr2, int sz)
{
	assert(arr1 && arr2);
	int start1 = 0, start2 = 0;
	int end1 = sz - 1, end2 = sz - 1;
	int mid1, mid2;
	while (start1 < end1)
	{
		mid1 = start1 + ((end1 - start1) >> 1);
		mid2 = start2 + ((end2 - start2) >> 1);

		//元素个数为奇数offset = 1,否则 = 0
		int offset = ((end1- start1+1) & 0x1) ^ 1;
		if (arr1[mid1] > arr2[mid2])
		{
			end1 = mid1 ;
			start2 = mid2 + offset;
		}
		else if (arr1[mid1] < arr2[mid2])
		{
			end2 = mid2 ;
			start1 = mid1 + offset;
		}
		else
			return arr1[mid1];
 	 }
	return  min(arr1[start1], arr2[start2]);
}

//查找两个长度为m和n的排序数组总共的前K个数字
//需要借助上面的求中位数把，传参形式改变
int findthek_code(int *arr1, int start1, int end1, int *arr2, int start2, int end2)
{
	int mid1, mid2;
	while (start1 < end1)
	{
		mid1 = start1 + ((end1 - start1) >> 1);
		mid2 = start2 + ((end2 - start2) >> 1);

		//元素个数为奇数offset = 1,否则 = 0
		int offset = ((end1 - start1 + 1) & 0x1) ^ 1;
		if (arr1[mid1] > arr2[mid2])
		{
			end1 = mid1;
			start2 = mid2 + offset;
		}
		else if (arr1[mid1] < arr2[mid2])
		{
			end2 = mid2;
			start1 = mid1 + offset;
		}
		else
			return arr1[mid1];
	}
	return  min(arr1[start1], arr2[start2]);
}

int findthek(int *arr1, int m, int *arr2, int n, int k)
{
	assert(arr1 && arr2);
	assert(k>0 && k<m+n);
	//让arr1是较短的数组
	if (m > n)
		return findthek(arr2, n, arr1, m, k);
	//较短数组的长度大于k,每个数组取前k个，得到的中位数就是解
	if (m >= k)
		return findthek_code(arr1,0,k-1,arr2, 0 ,k-2);
	//较长数组的长度小于k，易证arr1的前k-n-1,arr2的前k-m-1个元素不可能是。
	//然后两个数组求中位数
	if (n < k)
	{
		if (arr1[k - n - 1] >= arr2[n - 1])
			return arr1[k - n - 1];
		if (arr2[k - m - 1] >= arr2[m - 1])
			return arr2[k - m - 1];
		return findthek_code(arr1, k - n , m - 1, arr2, k - m, n - 1);
	}
	//k介于m和n之间时，较短数组arr1全部元素都有可能是第K个。较长数组
	//前k-m-1个元素 和 最后n-k个元素无效
	else
	{
		//arr2有效数字比arr1多一个，以下条件成立arr2[k-m-1]一定是第K个
		//判断后可使两个数组长度一样，再找中位数
		if (arr2[k - m - 1] >= arr1[m - 1])
			return arr2[k - m - 1];
		return findthek_code(arr1, 0, m - 1, arr2, k - m, k);
	}
}

int main()
{
	int arr1[] = {0,1,2,5,7,8};
	int arr2[] = {2,3};
	int sz1 = sizeof(arr1) / sizeof(arr1[0]);
	int sz2 = sizeof(arr2) / sizeof(arr2[0]);

	cout << findthek(arr1,sz1,arr2,sz2,7)<< endl;
	return 0;
}
#endif