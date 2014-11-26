#include <iostream>
using namespace std;
struct point
{
	int x;
	int y;
};

void partition(struct point *tree_ary, int start, int end);
int Part(struct point *tree_ary, int start, int end);

int main()
{
	int N, W, H;
	cin >> N;
	cin >> W;
	cin >> H;

	while(!((N==0)&&(W==0)&&(H==0)))
	{
		struct point *trees = new struct point[N];
		for(int i =0; i < N; i++)
		{	
			cin >> trees[i].x;
			cin >> trees[i].y;
		}
		partition(trees, 0, N-1);
		cout << "output: \n";
		for(int i =0; i < (N/2); i++)
		{	
			cout << trees[i].x;
			cout << " ";
			cout << trees[i].y;
			cout << endl;
		}
		cout << endl;
		delete trees;
		cin >> N;
		cin >> W;
		cin >> H;
	}		
			
	return 0;
}

void partition(struct point *tree_ary, int start, int end)
{
	if(end-start > 1)
	{
		int q = Part(tree_ary, start, end);
		partition(tree_ary, start, q-1);
		partition(tree_ary, q+1, end); 
	}
}

int Part(struct point *tree_ary, int start, int end)
{
	int sum = tree_ary[end].x + tree_ary[end].y;
	int i = start-1;
	for(int k = 0; k < end-1; k++)
	{
		if((tree_ary[k].x+tree_ary[k].y) < sum)
		{
			i++;
			struct point temp;
			temp.x = tree_ary[i].x;
			temp.y = tree_ary[i].y;
			tree_ary[i].x = tree_ary[k].x;
			tree_ary[i].y = tree_ary[k].y;
			tree_ary[k].x =temp.x;
			tree_ary[k].y = temp.y;
		}	
	}
	struct point temp;
	temp.x = tree_ary[i+1].x;
	temp.y = tree_ary[i+1].y;
	tree_ary[i+1].x = tree_ary[end].x;
	tree_ary[i+1].y = tree_ary[end].y;
	tree_ary[end].x = temp.x;
	tree_ary[end].y = temp.y;
	return i+1;
}
