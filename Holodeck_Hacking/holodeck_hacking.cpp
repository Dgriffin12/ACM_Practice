#include <iostream>
#include <string>
#include <sstream>
using namespace std;

long int reverse(long int orig);

int main()
{
	int test = 0;
	long int input = 0;
	int num_of_vals = 0;
	cin >> test;
	for(int t = 0; t < test; t++)
	{
		num_of_vals = 0;
		cin >> input;
		for(long int i = 0; i < input; i++)
		{
			if(input == (i+reverse(i)))
				num_of_vals++;
		}
		cout << num_of_vals << endl;
	}
	return 0;
}

long int reverse(long int orig)
{
	string original;
	stringstream ss;
	ss << orig;
	original = ss.str();
	string return_str = "";
	for(int i = 0; i < original.length(); i++)
	{
		return_str += original[original.length()-1-i];
	}
	stringstream rs;
	rs << return_str;
	long int result = 0;
	rs >> result;
	return result;
}
