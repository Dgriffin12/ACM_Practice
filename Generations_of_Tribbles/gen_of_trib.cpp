#include <iostream>
using namespace std;

int main()
{
	int test_cases = 0;
	cin >> test_cases;
	int g = 0;
	long long pre_calc_ary[67];
	pre_calc_ary[0] = 1;
	pre_calc_ary[1] = 1;
	pre_calc_ary[2] = 2;
	pre_calc_ary[3] = 4;
	for(int i = 4; i < 68; i++)
	{
		pre_calc_ary[i] = (pre_calc_ary[i-1] + pre_calc_ary[i-2] + pre_calc_ary[i-3] + pre_calc_ary[i-4]);
	}
	for(int t = 0; t < test_cases; t++)
	{
		cin >> g;
		cout << pre_calc_ary[g] << endl;
	}
	return 0;
}


