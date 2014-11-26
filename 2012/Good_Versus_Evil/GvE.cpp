#include <iostream>
using namespace std;

int main()
{
	int test_cases = 0;
	cin >> test_cases;
	int good = 0;
	int evil = 0;
	int count = 0;
	for(int t = 0; t < test_cases; t++)
	{
		good = 0;
		evil = 0;
		count = 0;
		//good
		for(int r = 0; r < 6; r++)
		{
			if(r == 0)
			{
				cin >> count;
				good+= count*1;
			}else if(r== 1)
			{
				cin >> count;
				good += count*2;
			}else if(r== 2)
			{
				cin >> count;
				good += count*3;
			}else if(r== 3)
			{
				cin >> count;
				good += count*3;
			}else if(r== 4)
			{	
				cin >> count;
				good += count*4;
			}else if(r== 5)
			{
				cin >> count;
				good += count*10;
			}
		}
		//evil
		for(int r = 0; r < 7; r++)
		{
			if(r == 0)
			{
				cin >> count;
				evil+= count*1;
			}else if(r== 1)
			{
				cin >> count;
				evil+= count*2;
			}else if(r== 2)
			{
				cin >> count;
				evil+= count*2;
			}else if(r== 3)
			{
				cin >> count;
				evil+= count*2;
			}else if(r== 4)
			{
				cin >> count;
				evil+= count*3;
			}else if(r== 5)
			{
				cin >> count;
				evil+= count*5;
			}else if(r== 6)
			{
				cin >> count;
				evil+= count*11;
			}
		}
		cout << "Battle " << t+1 << ": ";
		if(good > evil)
		{
			cout << "Good triumphs over Evil\n";
		}else if(evil > good)
		{
			cout << "Evil eradicates all trace of good\n";
		}else
		{
			cout << "Good and Evil are locked in an eternal struggle!\n";
		}
	}
	return 0;
}
