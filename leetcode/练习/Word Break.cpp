#include <iostream>
using namespace std;
#include <unordered_set>

/*判断字串是否被字符典可分*/
bool wordBreak(string s, unordered_set<string> &dict)
{
	if (dict.size() == 0 || s.size() == 0)
		return false;
	vector<bool> f(s.size()+1, false);
	//长度有size元素有+1个隔板
	f[0] = true;
	//f[i]表示[0-i]可否被分词
	for (int i = 1; i <=s.size(); ++i) //判断f[i]
	{
		for (int j = i - 1; j >= 0; --j) //f[i] = f[j] && (i-j)是子串
		{
			cout<<s.substr(j, i-j).c_str()<<endl;
			if (f[j] && (dict.find(s.substr(j, i-j)) != dict.end()))
			{
				f[i] = true;
				break;
			}
		}
	}

	return f[s.size()];
}

//int main()
//{
//	string str = "leetcode";
//	unordered_set<string> s;
//	s.insert("leet");
//	s.insert("code");
//	cout << wordBreak(str,s) << endl;
//	return 0;
//}


