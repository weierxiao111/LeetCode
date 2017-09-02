#if 0
#include <iostream>
using namespace std;
#include <assert.h>
#include <algorithm>
//Ѱ�������ȳ��������鹲ͬ����λ�� O��log(2n)��
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

		//Ԫ�ظ���Ϊ����offset = 1,���� = 0
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

//������������Ϊm��n�����������ܹ���ǰK������
//��Ҫ�������������λ���ѣ�������ʽ�ı�
int findthek_code(int *arr1, int start1, int end1, int *arr2, int start2, int end2)
{
	int mid1, mid2;
	while (start1 < end1)
	{
		mid1 = start1 + ((end1 - start1) >> 1);
		mid2 = start2 + ((end2 - start2) >> 1);

		//Ԫ�ظ���Ϊ����offset = 1,���� = 0
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
	//��arr1�ǽ϶̵�����
	if (m > n)
		return findthek(arr2, n, arr1, m, k);
	//�϶�����ĳ��ȴ���k,ÿ������ȡǰk�����õ�����λ�����ǽ�
	if (m >= k)
		return findthek_code(arr1,0,k-1,arr2, 0 ,k-2);
	//�ϳ�����ĳ���С��k����֤arr1��ǰk-n-1,arr2��ǰk-m-1��Ԫ�ز������ǡ�
	//Ȼ��������������λ��
	if (n < k)
	{
		if (arr1[k - n - 1] >= arr2[n - 1])
			return arr1[k - n - 1];
		if (arr2[k - m - 1] >= arr2[m - 1])
			return arr2[k - m - 1];
		return findthek_code(arr1, k - n , m - 1, arr2, k - m, n - 1);
	}
	//k����m��n֮��ʱ���϶�����arr1ȫ��Ԫ�ض��п����ǵ�K�����ϳ�����
	//ǰk-m-1��Ԫ�� �� ���n-k��Ԫ����Ч
	else
	{
		//arr2��Ч���ֱ�arr1��һ����������������arr2[k-m-1]һ���ǵ�K��
		//�жϺ��ʹ�������鳤��һ����������λ��
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