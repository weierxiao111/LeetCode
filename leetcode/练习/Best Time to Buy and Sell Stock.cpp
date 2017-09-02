#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

int maxProfit(vector<int> &prices)
{
	if (prices.size() <= 1)
		return 0;
	int ret = 0;
	int minpro = prices[0];
	for (int i = 1; i < prices.size(); ++i)
	{
		if (prices[i] - minpro > ret)
			ret = prices[i] - minpro;
		minpro = min(minpro, prices[i]);
	}
	return ret;
}

int maxProfit3(vector<int> &prices)
{
	int sz = prices.size();
	if (sz < 2)
		return 0;
	int ret = 0;
	vector<int> f(sz, 0);
	vector<int> g(sz, 0);
	int minpro = prices[0];
	for (int i = 1; i < sz; ++i)
	{
		f[i] =max( prices[i] - minpro,f[i-1]);
		minpro = min(minpro, prices[i]);
	}
	int maxpro = prices[sz - 1];
	for (int j = sz - 2; j >= 0; --j)
	{
		g[j] = max(maxpro - prices[j], g[j + 1]);
		maxpro = max(maxpro, prices[j]);
	}

	for (int k = 0; k < sz; ++k)
	{
		ret = max(ret, g[k]+f[k]);
	}
	return ret;
}
#endif
//int main()
//{
//	vector<int> v;
//	v.push_back(2);
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(0);
//	v.push_back(1);
//
//	cout << maxProfit3(v) << endl;
//	return 0;
//}