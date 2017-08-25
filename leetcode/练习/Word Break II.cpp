#include <iostream>
using namespace std;
#include <unordered_set>
#include <algorithm>

void getpath(string& s, vector<string> &result, vector< vector<bool>>& dp, vector<string> &path,
	int len, int cur);
/*�ж��ִ��Ƿ��ַ���ɷ�*/
vector<string> wordBreak(string s, unordered_set<string> &dict)
{
	vector<bool> f(s.size() + 1, false);
	//������sizeԪ����+1������
	f[0] = true;
	//f[i]��ʾ[0-i]�ɷ񱻷ִ�
	int len = s.size();
	vector<vector<bool> > dp(len + 1, vector<bool>(len + 1,false));
	for (int i = 1; i <= len; ++i) //�ж�f[i]
	{
		for (int j = i - 1; j >= 0; --j) //f[i] = f[j] && (i-j)���Ӵ�
		{
			if (f[j] && (dict.find(s.substr(j, i - j)) != dict.end()))
			{
				f[i] = true;
				dp[i][j] = true;
				//[j,i]�ɻ���
			}
		}
	}
	vector<string>  path;
	vector<string> result;

	getpath(s, result,dp, path, len, len);
   	return result;
}

void getpath(string& s,vector<string>& result, vector< vector<bool>>& dp, vector<string> &path,
	int len, int cur)
{
	if (cur == 0)
	{
		string ret;
		for (auto it = path.crbegin(); it != path.crend(); ++it)
		{
			ret += *it;
			ret += " ";
		}
		ret.erase(ret.end()-1);
		//ɾ����β����Ŀո��
		result.push_back(ret);
		cout<<ret.c_str()<<endl;
	}

	for (int i = 0; i <= len; ++i)
	{
		if (dp[cur][i])
		{
			path.push_back(s.substr(i,cur-i));
			getpath(s, result,dp, path, len, i);
			path.pop_back();
		}
	}
}

//int main()
//{
//	string str = "catsanddog";
//	unordered_set<string> s;
//	s.insert("cats");
//	s.insert("cat");
//	s.insert("dog");
//	s.insert("sand");
//	s.insert("and");
//	wordBreak(str, s);
//	return 0;
//}


