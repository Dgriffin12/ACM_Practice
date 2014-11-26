#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
struct cube
{
	int side;
	int painted;
};
int main()
{
	string line;
	int cur_line = 0;
	int start_x, start_y, cur_x, cur_y, goal_x, goal_y;	
	char **grid = new char*[20];
	for(int i = 0; i < 20; i++)
	{
		grid[i] = new char[20];
	}
	do
	{
		line.clear();
		getline(cin, line);
		if(line.length() == 1 || line.length() == 0)
		{
			struct cube c;
			c.side = 1;
			c.painted = 0;
			cur_line = 0;
			cout << "Grid = \n";
			for(int j = 0; grid[j][0] != '\0'; j++)
			{
				for(int k = 0; grid[j][k] != '\0'; k++)
				{
					cout << grid[j][k];
				}
				cout << endl;
			}
		}
		for(int i = 0; i < line.length(); i++)
		{
			grid[cur_line][i] = line[i];
			if(line[i] == 'C')
			{
				start_x = cur_line;
				start_y = i;
			}else if(line[i] == 'G')
			{
				goal_x = cur_line;
				goal_y = i;
			}
		}
		cur_line++;
		
	}while(line[0] != '\n' || line[0] != EOF);
	return 0;
}
