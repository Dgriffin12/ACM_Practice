#include <iostream>
#include <vector>
using namespace std;

struct warrior;
struct warrior
{
	char style;
	int superior;
	struct warrior* parent;
	vector<struct warrior*> subordinates;
};
bool first_condition(struct warrior warrior_1, struct warrior warrior_2);


int main()
{
	int cases = 0;
	int m = 0;
	int n = 0;
	char letter;
	for(int i = 0; i < cases; i++)
	{
		cin >> m;
		cin >> n;
		struct warrior clan_1[m];
		struct warrior clan_2[n];
		for(int j = 0; j < m; j++)
		{
			cin >> clan_1[j].style;
			cin >> clan_1[j].superior;
			clan_1[clan_1[j].superior].subordinates.push_back(&clan_1[j]);
			clan_1[j].parent = &clan_1[clan_1[j].superior];
		}
		for(int j = 0; j < n; j++)
		{
			cin >> clan_2[j].style;
			cin >> clan_2[j].superior;
			clan_2[clan_2[j].superior].subordinates.push_back(&clan_2[j]);
			clan_2[j].parent = &clan_2[clan_2[j].superior];			
		}

		if(clan_1[0].style != clan_2[0].style)
		{
			cout << 0 << endl;
		}else
		{
			

		}
		
		
	}
	return 0;
}

bool first_condition(struct warrior warrior_1, struct warrior warrior_2)
{
	if(warrior_1.style == warrior_2.style && warrior_1.subordinates.size() == warrior_2.subordinates.size())
	{
		return true;
	}else
	{
		return false;
	}

}
