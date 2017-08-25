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
		//f[i]表示i - len-1需要的最小切割数，f[len]辅助设为-1。
		f[i] = len - i - 1;
	}
	//dp[i][j]代表i-j是回文
	vector<vector<bool>> dp(len,vector<bool>(len,false));
	for (int i = len - 1; i >= 0; --i)
	{
		for (int j = i; j < len; ++j)
		{
			//下面语句成立说明i-j是回文串
			if (s[i] == s[j] && (j-2<=i || dp[i + 1][j - 1]))
			{
				dp[i][j] = true;
				//如果i - j是回文串，i - (len-1)需要的切割数
				//为(j+1) - (len-1)的切割数+1。取最小值
				f[i] = min(f[i],f[j+1]+1);
			}
		}
	}
	//0 - （len-1）的切割数就是字符串的最小切割数
	return f[0];
	
}

int main()
{
	cout <<minCut("dsdsdfsdfdfsad")<< endl;
	return 0;
}