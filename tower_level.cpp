#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int level = 0;
	int divider = 1;
	int power = 1;
	int one_counter = 0;
	long int day = 0;
	
	while(cin >> day)
	{
		//cout << "input = " << day << endl;
		level = 0;
		
		for(int i =0; i <= day; i++)
		{		
			power = 1;
			while(pow(2, power) <= i)
			{
				power++;
			}
			power--;
			divider = (int)(pow(2, power));
			one_counter = 0;

			for(int j = 0; j < i; j++)
			{
				if(divider == 0)
					break;
				//cout << (i/divider)%2;
				one_counter += (i/divider)%2;
				divider = divider/2;
				
			}
			if(one_counter % 3 == 0 && one_counter != 0)
			{
					level++;
					one_counter = 0;
			}
			//cout << endl;
		}
		cout << "Day " << day << ": Level = " << level << endl;
	}
	

	return 0;
}
