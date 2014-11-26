#include <iostream>
#include <string>
#include <deque>
#include <cstdlib>
using namespace std;
struct point;
struct point
{
	point(){}
	point(int x_i, int y_i) : x(x_i), y(y_i) {} 
	point(int x_i, int y_i, int g_i) : x(x_i), y(y_i), G(g_i){}
	int x;
	int y;
	int G;
	int H;
	int F;
	struct point *parent;
	char end_facing;
	void print()
	{
		cout << "Point: (" << x << ", " << y << ")";
		/*if(parent)
		{
			cout << ", Parent = (" << parent->x << ", " << parent->y << ")";
		}*/
		cout << endl;
	}
	void calc_F()
	{
		F = G+H;
	}
	int distance(struct point start)
	{
		return (abs(start.x-x) + abs(start.y-y));
	}
};

string color_print(int ci);

void final_shortest_path(struct point target, int time, char facing_in);

void output_shortest_path(struct point target, char **grid, int m, int n);

void A_star(char **grid, struct point start, struct point target, int m, int n);

int A_star_final(struct point start, int spaces_to_move, char **grid, int m, int n, int time);

bool contains(deque<struct point> check, int x, int y);

int main()
{
	int m, n;
	string line;
	int time = 0;
	int colors[5] = {0, 1, 2, 3, 4}; //0 = green, 1 = white, 2 = blue, 3 = red, 4 = black
	cin >> m;
	cin >> n;
	char **grid = new char*[m];
	int start_x;
	int start_y;
	int goal_x;
	int goal_y;
	for(int i = 0; i < m; i++)
	{
		grid[i] = new char[n];
	}
	cin.ignore(100, '\n');
	for(int i = 0; i < m; i++)
	{
		line.clear();
		getline(cin, line);
		for(int j = 0; j < line.length(); j++)
		{
			grid[i][j] = line[j];
			if(line[j] == 'S')
			{
				start_x = i;
				start_y = j;
			}
			if(line[j] == 'T')
			{
				goal_x = i;
				goal_y = j;
			}
		}
	}
	//Check input is right(print our grid)
	for(int i = 0; i < m; i++)
	{
		for(int j = 0; grid[i][j] != '\0'; j++)
		{
			cout<< grid[i][j];
		}
		cout << endl;
	}

	//Main Part(after input)
	struct point starter(start_x, start_y);
	struct point ender(goal_x, goal_y);

	A_star(grid, starter, ender, m, n);	

	return 0;
}


void A_star(char **grid, struct point start, struct point end, int m, int n)
{
	start.end_facing = 'N'; //start facing north
	struct point start_point = start;
	struct point *cur_point_ptr = new struct point(start.x, start.y, start.G);
	cur_point_ptr->H = start.H;
	cur_point_ptr->F = start.F;
	cur_point_ptr->end_facing = start.end_facing;
	cur_point_ptr->parent = NULL;
	deque<struct point>open_list;
	deque<struct point>closed_list;
	int G_val = 0;
	int upward_H_val, downward_H_val, right_H_val, left_H_val;
	cout << "Start: "; 
	start.parent = NULL;
	start.print();
	closed_list.push_back(start);
	char facing = 'N'; //0 for North, 1 for East, 2 for West, 3 for South
	while(true)
	{
		if(facing == 'N')
		{
			upward_H_val = 0;
			downward_H_val = 2;
			right_H_val = left_H_val = 1;
		}else if(facing == 'E')
		{
			upward_H_val = downward_H_val = 1;
			left_H_val = 2;
			right_H_val = 0;
		}else if(facing == 'W')
		{
			upward_H_val = downward_H_val = 1;
			left_H_val = 0;
			right_H_val = 2;
		}else if(facing == 'S')
		{
			upward_H_val = 2;
			downward_H_val = 0;
			right_H_val = left_H_val = 1;
		}
	
		//add considered points
		if((cur_point_ptr->y < n-1) && grid[cur_point_ptr->x][cur_point_ptr->y+1] != '#' && !contains(closed_list, cur_point_ptr->x, cur_point_ptr->y+1))
		{
			struct point up(cur_point_ptr->x, cur_point_ptr->y+1, G_val+1);
			up.H = up.distance(end) + upward_H_val;
			up.parent = cur_point_ptr;
			up.end_facing = 'E';
			up.calc_F();
			if(!contains(open_list,cur_point_ptr->x, cur_point_ptr->y+1))
				open_list.push_back(up);
		}
		if((start.y > 0) && grid[cur_point_ptr->x][cur_point_ptr->y-1] != '#' && !contains(closed_list, cur_point_ptr->x, cur_point_ptr->y-1))
		{
			struct point down(cur_point_ptr->x, cur_point_ptr->y-1, G_val+1);
			down.H = down.distance(end) + downward_H_val;
			down.parent = cur_point_ptr;
			down.end_facing = 'W';
			down.calc_F();
			if(!contains(open_list, cur_point_ptr->x, cur_point_ptr->y-1))
				open_list.push_back(down);
		}
		if((cur_point_ptr->x > 0) && grid[cur_point_ptr->x-1][cur_point_ptr->y] != '#' && !contains(closed_list, cur_point_ptr->x-1, cur_point_ptr->y))
		{
			struct point left(cur_point_ptr->x-1, cur_point_ptr->y, G_val+1);
			left.H = left.distance(end) + left_H_val;
			left.parent = cur_point_ptr;
			left.end_facing = 'N';
			left.calc_F();
			if(!contains(open_list, cur_point_ptr->x-1, cur_point_ptr->y))
				open_list.push_back(left);
		}
		if((cur_point_ptr->x < m-1) && grid[cur_point_ptr->x+1][cur_point_ptr->y] != '#' && !contains(closed_list, cur_point_ptr->x+1, cur_point_ptr->y))
		{
			struct point right(cur_point_ptr->x+1, cur_point_ptr->y, G_val+1);
			right.H = right.distance(end) + right_H_val;
			right.parent = cur_point_ptr;
			right.end_facing = 'S';
			right.calc_F();
			if(!contains(open_list, cur_point_ptr->x+1, cur_point_ptr->y))
				open_list.push_back(right);
		}
		if(open_list.empty())
		{
			cout << "No Path Possible\n";
			return;
		}else
		{
			G_val++;
		}
		int min_F = 1000000;
		int min_F_index = -1;
		for(int i = 0; i < open_list.size(); i++)
		{
			if(open_list.at(i).F < min_F)
			{
				min_F = open_list.at(i).F;
				min_F_index = i;
			}
		}
		struct point *chosen = new struct point(open_list.at(min_F_index).x, open_list.at(min_F_index).y, open_list.at(min_F_index).G);
		chosen->H = open_list.at(min_F_index).H;
		chosen->F = open_list.at(min_F_index).F;
		chosen->end_facing = open_list.at(min_F_index).end_facing;
		chosen->parent = open_list.at(min_F_index).parent;
		closed_list.push_back(*chosen);
		open_list.erase(open_list.begin() + min_F_index);
		cur_point_ptr = chosen;
		cur_point_ptr->print();
		
		facing = cur_point_ptr->end_facing;
		if(contains(closed_list, end.x, end.y))
		{
			cout << "done\n";
			closed_list.at(1).print();
			cout << "called shortest path func\n";
			output_shortest_path(closed_list.back(), grid, m, n);
			return;
		}
	}
}

bool contains(deque<struct point> check, int x, int y)
{
	for(int i = 0; i < check.size(); i++)
	{
		if(check.at(i).x == x && check.at(i).y == y)
			return true;
	}
	return false;
}

void output_shortest_path(struct point target, char **grid, int m, int n)
{
	struct point *p_ptr = target.parent;
	deque<struct point> path;
	path.push_front(target);
	cout << "----------------------------\n";
	int t = 0;
	while(p_ptr)
	{
		path.push_front(*p_ptr);
		p_ptr->print();
		p_ptr = p_ptr->parent;
	}
	cout << "Shortest_Path:\n";
	char facing = 'N';
	string color;
	int time = 0;
	int color_incrementer = 0;
	for(int i = 1; i < path.size(); i++)
	{
		int turns = 0;
		if(facing == 'N' && path.at(i).end_facing == 'S' || facing == 'E' && path.at(i).end_facing == 'W' || facing == 'W' && path.at(i).end_facing == 'E' || facing == 'S' && path.at(i).end_facing == 'N')
		{
			turns = 2;
		}else if((facing == 'N' || facing == 'S') && (path.at(i).end_facing == 'E' || path.at(i).end_facing == 'W') || (facing == 'E' || facing == 'W') && (path.at(i).end_facing == 'N' || path.at(i).end_facing == 'S'))
		{
			turns = 1;
		}
		path.at(i).print();
		cout << "Facing " << facing << " , turning " << path.at(i).end_facing << endl;
		facing = path.at(i).end_facing;
		time += 1 + turns;
		cout << "Time after actions = " << time << endl;
		color_incrementer+=1+turns;
		color = color_print(color_incrementer);
		cout << color << endl;
		if(color_incrementer > 4)
			color_incrementer = 0;
		
	}
	cout << "TIME AFTER FIRST A* = " << time << endl;
	int spaces_to_move = 0;
	if(color == "white")
	{
		spaces_to_move = 2;
	}else if(color == "blue")
	{
		spaces_to_move = 4;
	}else if(color == "red")
	{
		spaces_to_move = 1;
	}else if(color == "black")
	{
		spaces_to_move = 3;
	}

	if(spaces_to_move == 0)
	{
		cout << "Final Time: " << time << endl;
	}else
	{
		//need to calculate a shortest path (spaces_to_move) spaces away from the target.
		//then move those spaces to add time to get the wheel to green.
		//turning is the tricky part.
		A_star_final(target, spaces_to_move, grid, m, n, time);
	}
}

string color_print(int ci)
{
	string color = "";
	if(ci == 0)
	{
		color = "green";
	}else if(ci == 1)
	{
		color = "white";
	}else if(ci == 2)
	{
		color = "blue";
	}else if(ci == 3)
	{
		color = "red";
	}else if(ci == 4)
	{
		color = "black";
	}
	return color;
}

int A_star_final(struct point start, int spaces_to_move, char **grid, int m, int n, int time)
{
	cout << "Starting A* Final function\n";
	struct point *cur_point_ptr = new struct point(start.x, start.y, start.G);
	cur_point_ptr->H = start.H;
	cur_point_ptr->F = start.F;
	cur_point_ptr->end_facing = start.end_facing;
	cur_point_ptr->parent = NULL;
	deque<struct point>open_list;
	deque<struct point>closed_list;
	int G_val = 0;
	int upward_H_val, downward_H_val, right_H_val, left_H_val;
	char facing = start.end_facing;
	for(int i = 0; i < spaces_to_move; i++)
	{
		if(facing == 'N')
		{
			upward_H_val = 0;
			downward_H_val = 2;
			right_H_val = left_H_val = 1;
		}else if(facing == 'E')
		{
			upward_H_val = downward_H_val = 1;
			left_H_val = 2;
			right_H_val = 0;
		}else if(facing == 'W')
		{
			upward_H_val = downward_H_val = 1;
			left_H_val = 0;
			right_H_val = 2;
		}else if(facing == 'S')
		{
			upward_H_val = 2;
			downward_H_val = 0;
			right_H_val = left_H_val = 1;
		}
		if((cur_point_ptr->y < n-1) && grid[cur_point_ptr->x][cur_point_ptr->y+1] != '#' && !contains(closed_list, cur_point_ptr->x, cur_point_ptr->y+1))
		{
			struct point up(cur_point_ptr->x, cur_point_ptr->y+1, G_val+1);
			up.H = upward_H_val;
			up.parent = cur_point_ptr;
			up.end_facing = 'E';
			up.calc_F();
			if(!contains(open_list,cur_point_ptr->x, cur_point_ptr->y+1))
				open_list.push_back(up);
		}
		if((start.y > 0) && grid[cur_point_ptr->x][cur_point_ptr->y-1] != '#' && !contains(closed_list, cur_point_ptr->x, cur_point_ptr->y-1))
		{
			struct point down(cur_point_ptr->x, cur_point_ptr->y-1, G_val+1);
			down.H = downward_H_val;
			down.parent = cur_point_ptr;
			down.end_facing = 'W';
			down.calc_F();
			if(!contains(open_list, cur_point_ptr->x, cur_point_ptr->y-1))
				open_list.push_back(down);
		}
		if((cur_point_ptr->x > 0) && grid[cur_point_ptr->x-1][cur_point_ptr->y] != '#' && !contains(closed_list, cur_point_ptr->x-1, cur_point_ptr->y))
		{
			struct point left(cur_point_ptr->x-1, cur_point_ptr->y, G_val+1);
			left.H = left_H_val;
			left.parent = cur_point_ptr;
			left.end_facing = 'N';
			left.calc_F();
			if(!contains(open_list, cur_point_ptr->x-1, cur_point_ptr->y))
				open_list.push_back(left);
		}
		if((cur_point_ptr->x < m-1) && grid[cur_point_ptr->x+1][cur_point_ptr->y] != '#' && !contains(closed_list, cur_point_ptr->x+1, cur_point_ptr->y))
		{
			struct point right(cur_point_ptr->x+1, cur_point_ptr->y, G_val+1);
			right.H = right_H_val;
			right.parent = cur_point_ptr;
			right.end_facing = 'S';
			right.calc_F();
			if(!contains(open_list, cur_point_ptr->x+1, cur_point_ptr->y))
				open_list.push_back(right);
		}
		
		G_val++;

		int min_F = 1000000;
		int min_F_index = -1;
		for(int i = 0; i < open_list.size(); i++)
		{
			if(open_list.at(i).F < min_F)
			{
				min_F = open_list.at(i).F;
				min_F_index = i;
			}
		}
		struct point *chosen = new struct point(open_list.at(min_F_index).x, open_list.at(min_F_index).y, open_list.at(min_F_index).G);
		chosen->H = open_list.at(min_F_index).H;
		chosen->F = open_list.at(min_F_index).F;
		chosen->end_facing = open_list.at(min_F_index).end_facing;
		chosen->parent = open_list.at(min_F_index).parent;
		closed_list.push_back(*chosen);
		open_list.erase(open_list.begin() + min_F_index);
		cur_point_ptr = chosen;
		//cur_point_ptr->print();
		
		facing = cur_point_ptr->end_facing;
	}
	final_shortest_path(*cur_point_ptr, time, start.end_facing);
}

void final_shortest_path(struct point target, int time, char facing_in)
{
	struct point *p_ptr = target.parent;
	deque<struct point> path;
	path.push_front(target);
	cout << "Facing_in = " << facing_in << endl;
	cout << "----------------------------\n";
	int t = 0;
	while(p_ptr)
	{
		path.push_front(*p_ptr);
		p_ptr->print();
		p_ptr = p_ptr->parent;
	}
	cout << "Final Shortest_Path:\n";
	char facing = facing_in;
	string color;
	int time_gain = 0;
	int color_incrementer = 0;
	for(int i = 1; i < path.size(); i++)
	{
		int turns = 0;
		if(facing == 'N' && path.at(i).end_facing == 'S' || facing == 'E' && path.at(i).end_facing == 'W' || facing == 'W' && path.at(i).end_facing == 'E' || facing == 'S' && path.at(i).end_facing == 'N')
		{
			turns = 2;
		}else if((facing == 'N' || facing == 'S') && (path.at(i).end_facing == 'E' || path.at(i).end_facing == 'W') || (facing == 'E' || facing == 'W') && (path.at(i).end_facing == 'N' || path.at(i).end_facing == 'S'))
		{
			turns = 1;
		}
		path.at(i).print();
		cout << "Facing " << facing << " , turning " << path.at(i).end_facing << endl;
		facing = path.at(i).end_facing;
		time_gain += 1 + turns;		
	}
	time += 2*time_gain + 2; //time gained from moving 'spaces_to_move' spaces away from target, and the time to turn around(2 turns), then the time back.
	cout << "FINAL TIME = " << time << endl;
}

