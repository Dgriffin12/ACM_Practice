#include <iostream>
using namespace std;
struct asteroid
{
	double x;
	double y;
	double r;
};
int main()
{
	int cases = 0;
	cin >> cases;
	int roids = 0;
	for(int t = 0; t < cases; t++)
	{
		roids = 0;
		cin >> roids;
		struct asteroid asteroids[roids];
		for(int a = 0; a < roids; a++)
		{
			cin >> asteroids[a].x;
			cin >> asteroids[a].y;
			cin >> asteroids[a].r;
		}
		
				
		
	}
	return 0;
}
