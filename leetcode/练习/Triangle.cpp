#if 0
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>
int minimumTotal(vector<vector<int> > &triangle)
{
	int ret = 0;
	for (int i = triangle.size()-2; i>= 0 ; --i)
	{
		for (int j = 0; j < triangle[i].size() - 1; ++j)
		{
			triangle[i][j] = min(triangle[i + 1][j], triangle[i + 1][j + 1]);
		}
	}
	return triangle[0][0];
}

//int main()
//{
//	return 0;
//}
#endif 