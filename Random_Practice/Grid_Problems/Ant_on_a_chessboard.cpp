#include <iostream>
#include <deque>
using namespace std;

struct point
{
	int x;
	int y;
};

void breadth_first_search(struct point loc, int start_time, int end_time);

int main()
{
	int time = 0;
	int cur_time = 1;
	cin >> time;
	bool **grid = new bool*[100];
	for(int i = 0; i < 100; i++)
	{
		grid[i] = new bool[100];
	}
	
	struct point start;
	start.x = 1;
	start.y = 1;
	breadth_first_search(start, 0, time);
}


void breadth_first_search(struct point loc, int start_time, int end_time)
{
	deque<struct point> queue;
	queue.push_back(loc);
	while(!queue.empty())
	{
		struct point t = queue.at(0);
		queue.pop_front();
		
		if(start_time == end_time)
		{
			cout << t.x << " " << t.y << endl;
			break;
		}
		if(t.x > 0 && t.y < 50)
		{
			cout << "visiting " << t.x << " " << t.y << endl;
			start_time++;
			struct point up;
			up.x = t.x;
			up.y = t.y+1;
			queue.push_back(up);
			struct point diag_right_up;
			diag_right_up.x = t.x+1;
			diag_right_up.y = t.y+1;
			queue.push_back(diag_right_up);
			struct point right;
			right.x = t.x+1;
			right.y = t.y;
			queue.push_back(right);
			struct point diag_right_down;
			diag_right_down.x = t.x+1;
			diag_right_down.y = t.y-1;
			queue.push_back(diag_right_down);
			struct point down;
			down.x = t.x;
			down.y = t.y-1;
			queue.push_back(down);
			struct point diag_left_down;
			diag_left_down.x = t.x-1;
			diag_left_down.y = t.y-1;
			queue.push_back(diag_left_down);
			struct point left;
			left.x = t.x-1;
			left.y = t.y;
			queue.push_back(left);
			struct point diag_left_up;
			diag_left_up.x = t.x-1;
			diag_left_up.y = t.y+1;
			queue.push_back(diag_left_up);
		}		
	}
		
}
