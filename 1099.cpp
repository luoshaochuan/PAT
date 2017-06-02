/*
A Binary Search Tree (BST) is recursively defined as a binary tree which has the following properties:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than or equal to the node's key.
Both the left and right subtrees must also be binary search trees.
Given the structure of a binary tree and a sequence of distinct integer keys, there is only one way to fill these keys into the tree so that the resulting tree satisfies the definition of a BST. You are supposed to output the level order traversal sequence of that tree. The sample is illustrated by Figure 1 and 2.
Input Specification:

Each input file contains one test case. For each case, the first line gives a positive integer N (<=100) which is the total number of nodes in the tree. The next N lines each contains the left and the right children of a node in the format "left_index right_index", provided that the nodes are numbered from 0 to N-1, and 0 is always the root. If one child is missing, then -1 will represent the NULL child pointer. Finally N distinct integer keys are given in the last line.

Output Specification:

For each test case, print in one line the level order traversal sequence of that tree. All the numbers must be separated by a space, with no extra space at the end of the line.

Sample Input:
9
1 6
2 3
-1 -1
-1 4
5 -1
-1 -1
7 -1
-1 8
-1 -1
73 45 11 58 82 25 67 38 42
Sample Output:
58 25 82 11 38 67 45 73 42
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;

queue<int> q;

void in_order(int v,int *left,int *right)
{
	if (left[v] != -1)
		in_order(left[v], left, right);
	q.push(v);
	if (right[v] != -1)
		in_order(right[v],left, right);
}


int main()
{
	int node_num;
	cin >> node_num;
	int *left = new int[node_num];
	int *right = new int[node_num];
	int *value = new int[node_num];
	for (int i = 0; i < node_num; ++i)
	{
		int l, r;
		cin >> l >> r;
		left[i] = l;
		right[i] = r;
	}
	vector<int> vec;
	for (int i = 0; i < node_num; ++i)
	{
		int v;
		cin >> v;
		vec.push_back(v);
	}
	sort(vec.begin(), vec.end());

	/*对索引号进行中序遍历*/
	in_order(0, left, right);
	for (int i = 0; i < node_num;++i)
	{
		int index = q.front();
		q.pop();
		value[index] = vec[i];
	}

	/*按层序遍历输出结果*/
	vector<int> result;
	q.push(0);
	while (!q.empty())
	{
		int top = q.front();
		q.pop();
		if (left[top] != -1)
		{
			q.push(left[top]);
		}
		if (right[top] != -1)
		{
			q.push(right[top]);
		}
		result.push_back(value[top]);
	}
	for (int i = 0; i < result.size() - 1; ++i)
	{
		cout << result[i] << " ";
	}
	cout << result.back() << endl;
	delete left;
	delete right;
	delete value;
	return 0;
}