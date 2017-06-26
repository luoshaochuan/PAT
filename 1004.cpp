#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int max_depth = 0;
int depth[100];
int leaves[100];
vector<int> tree[100];
vector<int> level[100];

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; ++i)
	{
		int id, k;
		cin >> id >> k;
		for (int j = 0; j < k; ++j)
		{
			int child;
			cin >> child;
			tree[id].push_back(child);
		}
	}
		queue<int> q;
		q.push(1);
		depth[1] = 0;
		leaves[0] = 0;
		while (!q.empty())
		{
			int top = q.front();
			q.pop();
			if (!tree[top].empty())
			{
				for (int child : tree[top])
				{
					depth[child] = depth[top] + 1;
					if (depth[child]>max_depth)
						max_depth = depth[child];
					q.push(child);
				}
			}
			else
			{
				++leaves[depth[top]];
			}
		}
		for (int i = 0; i < max_depth; ++i)
			cout << leaves[i] << " ";
		cout << leaves[max_depth] << endl;
	return 0;
}