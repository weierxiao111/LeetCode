#if 0
#include <iostream>
#include <string>
using namespace std;

string noepeatsub(const string& str)
{
	int hash[10];

	//start���Ӵ��Ŀ�ʼ��end�ǽ�β
	int start = 0;
	int end = 0;
	int max = 0;
	//��������λ��
	int maxstart = 0;
	//��hash���������ظ��Ӵ������ֳ��ֵ��±꣬û�г��ֹ�Ϊ-1
	for (int i = 0; i < 10; ++i)
		hash[i] = -1;
	for (int j = 0; j < str.size(); ++j)
	{
		int index = str[j] - '0';
		//���ֵ���Ӵ���û�г��ֹ�,������֮ǰ��������
		if (hash[index] == -1 || hash[index] < start)
		{
			end = j;
			if (end - start + 1 > max)
			{
				max = end - start + 1;
				maxstart = start;
			}
		}
		else//���ֹ�,������ʼλ��
		{
			start = hash[index] + 1;
		}
		hash[index] = j;
	}
	return str.substr(maxstart,max);
}

int main()
{
	char* str = "1201335435";
	cout <<noepeatsub(str)<< endl;
	return 0;
}
#endif