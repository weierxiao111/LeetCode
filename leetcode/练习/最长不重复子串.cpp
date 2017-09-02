#if 0
#include <iostream>
#include <string>
using namespace std;

string noepeatsub(const string& str)
{
	int hash[10];

	//start是子串的开始，end是结尾
	int start = 0;
	int end = 0;
	int max = 0;
	//用来返回位置
	int maxstart = 0;
	//用hash来保存无重复子串中数字出现的下标，没有出现过为-1
	for (int i = 0; i < 10; ++i)
		hash[i] = -1;
	for (int j = 0; j < str.size(); ++j)
	{
		int index = str[j] - '0';
		//这个值在子串中没有出现过,或者在之前的序列中
		if (hash[index] == -1 || hash[index] < start)
		{
			end = j;
			if (end - start + 1 > max)
			{
				max = end - start + 1;
				maxstart = start;
			}
		}
		else//出现过,更新起始位置
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