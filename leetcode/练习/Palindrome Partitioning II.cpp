#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int minCut(string s)
{
	int len = s.size();
	vector<int> f(len+1);
	for (int i = 0; i <= len; ++i)
	{
		//f[i]��ʾi - len-1��Ҫ����С�и�����f[len]������Ϊ-1��
		f[i] = len - i - 1;
	}
	//dp[i][j]����i-j�ǻ���
	vector<vector<bool>> dp(len,vector<bool>(len,false));
	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = i; j < len; ++j)
		{
			//����������˵��i-j�ǻ��Ĵ�
			if (s[i] == s[j] && (j-2<=i || dp[i + 1][j - 1]))
			{
				dp[i][j] = true;
				//���i - j�ǻ��Ĵ���i - (len-1)��Ҫ���и���
				//Ϊ(j+1) - (len-1)���и���+1��ȡ��Сֵ
				f[i] = min(f[i],f[j+1]+1);
			}
		}
	}
	//0 - ��len-1�����и��������ַ�������С�и���
	return f[0];
	
}

int main()
{
	cout <<minCut("dsdsdfsdfdfsad")<< endl;
	return 0;
}