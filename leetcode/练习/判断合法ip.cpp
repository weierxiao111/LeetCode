#if 0
#include <iostream>
#include <string>
using namespace std;

bool check_num(string& num)
{
	int len = num.size();
	if (len < 1 || len > 3)
		return false;

	//出现数字为 001，002 ..非法
	if (num[0] == '0' && len > 1)
		return false;
	int sum = 0;
	for (int i = 0; i < len; ++i)
	{
		sum =  sum*10 + (num[i] - '0');
	}
	if (sum > 255)
		return false;
	return true;
}

bool check_ip(const string& ip)
{
	int len = ip.size();
	//合法ip的长度在7-15之间
	if (len < 7 || len > 15)
		return false;
	//num记录当前数
	string num;
	//count记录.的个数
	int count = 0;
	for (int i = 0; i < len; ++i)
	{
	    if (ip[i] == '.' && check_num(num) && count <= 3)
		{
			num = "";
			count++;
		}
		else if (ip[i] <= '9' && ip[i] >= '0')
		{
			num += ip[i];
		}
		else
			return false;
	}
	//判断最后一个num 和 count
	if ( !check_num(num) || count != 3)
		return false;
	return true;
}

int main()
{
	string ip;
	while (cin >> ip)
	{
		if (check_ip(ip))
			cout << ip.c_str() << " YES" << endl;
		else
			cout << ip.c_str() << " NO" << endl;
	}
	return 0;
}

#endif