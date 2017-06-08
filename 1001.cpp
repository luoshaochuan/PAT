#include<iostream>
#include<stack>

using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int c = a + b;
	if (c == 0)
	{
		cout << c;
		return 0;
	}
	if (c < 0)
	{
		cout << '-';
		c = -c;
	}
	stack<char> s;
	int count = 0;
	while (c)
	{
		int d = c % 10;
		if (count == 3 && c!=0)
		{
			s.push(',');
			count = 0;
		}
		c = c / 10;
		char ch = '0' + d;
		s.push(ch);
		++count;
	}
	
	while (!s.empty())
	{
		char ch = s.top();
		s.pop();
		cout << ch;
	}
	return 0;
}