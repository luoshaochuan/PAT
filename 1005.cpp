#include<iostream>
#include<string>

using namespace std;

string map[10] = { "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine" };

void print_sum(int sum)
{
	if (sum == 0)
		return;
	print_sum(sum / 10);
	cout << map[sum % 10] << " ";
}

int main()
{
	string input;
	cin >> input;
	int sum = 0;
	for (int i = 0; i<input.length(); ++i)
	{
		sum += (input[i] - '0');
	}
	if (sum)
	{
		print_sum(sum / 10);
		cout << map[sum % 10] << endl;;
	}
	else
	{
		cout << "zero" << endl;
	}
	return 0;
}