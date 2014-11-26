#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
	int test_num = 0;
	cin >> test_num;
	int planets = 0;
	for(int t = 0; t < test_num; t++)
	{
		planets = 0;
		cin >> planets;
		long int *locations = new long int[planets];
		for(int p = 0; p < planets; p++)
		{
			cin >> locations[p];
		}
		cout << "Distances: ";
		for(int i = 0; i < planets-1; i++)
		{
			cout << locations[i] << ", ";
		}
		cout << locations[planets-1] << endl;
		int max_distance = 0;
		int max_distance_index_1 = 0;
		int max_distance_index_2 = 0;
		for(int p = 0; p < planets; p++)
		{
			for(int d = 0; d < planets; d++)
			{
				int distance = abs(locations[p]-locations[d]);
				if(distance > max_distance)
				{
					max_distance = distance;
					max_distance_index_1 = d;
					max_distance_index_2 = p;
				}
			}
		}
		cout << "Max distance indices = " << max_distance_index_1 << ", " << max_distance_index_2 << endl;
		int next_max_distance = 0;
		for(int p = 0; p < planets; p++)
		{
			cout << "Planet " << p << " Distances: ";
			for(int d = 0; d < planets; d++)
			{
				int distance = abs(locations[p] - locations[d]);
				if(abs(locations[d] - locations[max_distance_index_1]) + abs(locations[p] - locations[max_distance_index_2])< distance)
				{ //if distance the wormhole decreases the distance between them.
					distance = abs(locations[d] - locations[max_distance_index_1]) + abs(locations[p] - locations[max_distance_index_2]);
				}
				if(abs(locations[d] - locations[max_distance_index_2]) + abs(locations[p] - locations[max_distance_index_1]) < distance)
				{
					distance = abs(locations[d] - locations[max_distance_index_2]) + abs(locations[p] - locations[max_distance_index_1]);
				}
				
				if(((d == max_distance_index_1) || (d == max_distance_index_2)) && ((p == max_distance_index_2) || (p == max_distance_index_1)))
				{
					distance = 0;
				}
				cout << distance << ", ";
				if(distance > next_max_distance)
				{
					next_max_distance = distance;
				}
			}
			cout << endl;
		}
		cout << "max distance after wormhole = " << next_max_distance << endl;
		
	}
	return 0;
}
