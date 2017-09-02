#if 0
//可以被分成的回文子串
#include <iostream>
using namespace std;
#include <vector>
#include <string>

void dfs(string s, vector<vector<string>>& result, vector<string> &res,
	int len, int start);

vector<vector<string>>  partion(string s)
{
	int len = s.size();
	vector<vector<string>> result;
	vector<string> res;
	dfs(s,result,res,len,0);
	return result;
}

void dfs(string s, vector<vector<string>>& result, vector<string> &res,
	int len, int start)
{
	if (start == len)
	{
		result.push_back(res);
	}
	for (int i = start; i < len; ++i)
	{
		int l = start;
		int r = i;
		while (r >= 0 && l<len && s[l] == s[r])
		{
			l++;
			r--;
		}
		if (r <= l)
		{
			res.push_back(s.substr(start,i-start+1));
			dfs(s,result,res,len,i+1);
			res.pop_back();
		}
	}
}

#endif
//int main()
//{
//	string s = "aab";
//	vector<vector<string>> res = partion(s);
//	for (int i = 0; i < res.size(); ++i)
//	{
//		for (int j = 0; j < res[i].size(); ++j)
//			cout << res[i][j].c_str() << " ";
//		cout << endl;
//	}
//	return 0;
//}