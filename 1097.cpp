/*
Given a singly linked list L with integer keys, you are supposed to remove the nodes with duplicated absolute values of the keys.That is, for each value K, only the first node of which the value or absolute value of its key equals K will be kept.At the mean time, all the removed nodes must be kept in a separate list.For example, given L being 21¡ú - 15¡ú - 15¡ú - 7¡ú15, you must output 21¡ú - 15¡ú - 7, and the removed list - 15¡ú15.

Input Specification :

Each input file contains one test case.For each case, the first line contains the address of the first node, and a positive N(<= 105) which is the total number of nodes.The address of a node is a 5 - digit nonnegative integer, and NULL is represented by - 1.

Then N lines follow, each describes a node in the format :

Address Key Next

where Address is the position of the node, Key is an integer of which absolute value is no more than 104, and Next is the position of the next node.

Output Specification :

For each case, output the resulting linked list first, then the removed list.Each node occupies a line, and is printed in the same format as in the input.

Sample Input :
00100 5
99999 - 7 87654
23854 - 15 00000
87654 15 - 1
00000 - 15 99999
00100 21 23854
Sample Output :
00100 21 23854
23854 - 15 99999
99999 - 7 - 1
00000 - 15 87654
87654 15 - 1
*/

#include<iostream>
#include<vector>
#include<map>
using namespace std;

struct Node
{
	int address;
	int value;
	int next;
	Node()
	{

	}
	Node(int addr, int v, int nxt)
	{
		address = addr;
		value = v;
		next = nxt;
	}
};

struct Node link_array[100000];
map<int, bool> link_map;
vector<Node> rs_list;
vector<Node> rm_list;

int main()
{
	int start, num;
	cin >> start >> num;
	for (int i = 0; i < num; ++i)
	{
		int addr, v, nxt;
		cin >> addr >> v >> nxt;
		Node node(addr, v, nxt);
		link_array[addr] = node;
	}
	int next = start;
	while (next != -1)
	{
		int value = abs(link_array[next].value);
		if (link_map.count(value))
		{
			rm_list.push_back(link_array[next]);
		}
		else
		{
			link_map[value] = true;
			rs_list.push_back(link_array[next]);
		}
		next = link_array[next].next;
	}
	if (!rs_list.empty())
	{
		for (int i = 0; i < rs_list.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", rs_list[i].address, rs_list[i].value, rs_list[i + 1].address);
		}
		printf("%05d %d %d\n", rs_list.back().address, rs_list.back().value, -1);
	}
	if (!rm_list.empty())
	{
		for (int i = 0; i < rm_list.size() - 1; ++i)
		{
			printf("%05d %d %05d\n", rm_list[i].address, rm_list[i].value, rm_list[i + 1].address);
		}
		printf("%05d %d %d\n", rm_list.back().address, rm_list.back().value, -1);
	}
	return 0;
}