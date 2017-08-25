#include <iostream>
using namespace std;
#include <vector>

int fun(vector<int> v, int n)
{
	if (n <= 0)
		return true;
	int i = 1;
	for (; i < n; ++i)
	{
		if (v[i] < v[i - 1])
			break;
	}
	int temp = v[i - 1];

	for (; i < n; ++i)
	{
		if (v[i]>v[i - 1])
			break;
	}
	if (v[i - 1] < temp)
		return false;
	for (; i < n; ++i)
	{
		if (v[i] < v[i - 1])
			return false;
	}
	return true;
}

//int main()
//{
//	int n;
//	cin >> n;
//	vector<int> v(n, 0);
//	for(int i = 0; i < n; ++i)
//		cin >> v[i];
//	bool ret = fun(v, n);
//	if (ret)
//		cout << "yes" << endl;
//	else
//		cout << "no" << endl;
//	return 0;
//}