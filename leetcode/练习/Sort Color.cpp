#if 0
#include <iostream>
using namespace std;


void sortColors(int A[], int n) {
	int start = 0;
	int end = n - 1;
	for (int i = 0; i <= end;)
	{
		//i��startͬʱ��ʼ�����A[i]����2�ᱻ��������ߣ����Կ���ͬʱ++
		//���˿�ʼ������ʱ��start��λ�ò�������2��0��
		if (A[i] == 0)
			swap(A[i++], A[start++]);
		else if (A[i] == 2)
			swap(A[i], A[end--]);
		//��end����������������������ģ����Բ���++��
		else
			++i;
	}
}
#endif