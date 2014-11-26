#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int input = 0;
	cin >> input;
	while(input != -1)
	{
		deque<int> good_factors;
		for(int i = 2; i < input; i++)
		{
			if(input % i == 0)
			{
				good_factors.push_back(i);
			}
		}
		good_factors.push_front(1);
		int sum = 0;
		for(int i = 0; i < good_factors.size(); i++)
		{
			sum += good_factors.at(i);
		}
		if(sum == input)
		{
			cout << input << " = " << good_factors.at(0);
			for(int i = 1; i < good_factors.size(); i++)
			{
				cout << " + " << good_factors.at(i);
			}
			cout << endl;
		}else
		{
			cout << input << " is NOT perfect." << endl;
		}
		cin >> input;
	}
	return 0;
}
