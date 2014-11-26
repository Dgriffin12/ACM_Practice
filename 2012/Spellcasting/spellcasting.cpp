#include <iostream>
using namespace std;

struct element
{
	int energy; //cost to summon
	int power_output; //mana per second
	int parent; //0 if no parent
};

int get_lowest_summon_cost(struct element *element_ary);

int main()
{
	int N, E, P;
	cin >> N; //number of elements
	cin >> E; //starting energy
	cin >> P; //power required
	int current_power = 0;
	int seconds = 0;
	int power_rate = 0;
	while(!(N==0&&P==0&&E==0))
	{
		current_power = E;
		seconds = 0;
		power_rate = 0;
		struct element *elements = new struct element[N];		
		for(int i = 0; i < N; i++)
		{
			cin >> elements[i].energy;
			cin >> elements[i].power_output;
			power_rate += elements[i].power_output;
			cin >> elements[i].parent;
		}
		while(current_power < P)
		{
			current_power += power_rate;
			int time_to_goal = -1;
			int new_time_to_goal = -1;
			time_to_goal = (P-current_power) / power_rate;
			seconds++;
		}
		cout << seconds << endl;
		delete elements;
		cin >> N;
		cin >> E;
		cin >> P;
	}
	return 0;
}

int get_lowest_summon_cost(struct element *element_ary)
{
	

}
