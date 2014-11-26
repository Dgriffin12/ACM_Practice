#include <iostream>
#include <sstream>
using namespace std;


int main()
{
	int test_cases = 0;
	int number_of_ships = 0;
	int distance_to_site = 0;
	int num_ships_that_make_it = 0;
	double v, f, c;
	cin >> test_cases;

	for(int i = 0; i < test_cases; i++)
	{
		num_ships_that_make_it = 0;
		cin >> number_of_ships;
		cin >> distance_to_site;

		int *v = new int[number_of_ships];
		int *f = new int[number_of_ships];
		int *c = new int[number_of_ships];

		for(int j = 0; j < number_of_ships; j++)
		{
			cin >> v[j];
			cin >> f[j];
			cin >> c[j];
			double hours = (double)distance_to_site / (double)v[j];

			if(hours*c[j] <= (double)f[j])
				 num_ships_that_make_it++;
		}
		cout << num_ships_that_make_it << endl;
		
	}
	return 0;
}
