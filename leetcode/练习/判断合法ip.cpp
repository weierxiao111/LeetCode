#if 0
#include <iostream>
#include <string>
using namespace std;

bool check_num(string& num)
{
	int len = num.size();
	if (len < 1 || len > 3)
		return false;

	//��������Ϊ 001��002 ..�Ƿ�
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
	//�Ϸ�ip�ĳ�����7-15֮��
	if (len < 7 || len > 15)
		return false;
	//num��¼��ǰ��
	string num;
	//count��¼.�ĸ���
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
	//�ж����һ��num �� count
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