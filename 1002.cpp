//#include<iostream>
//#include<vector>
//using namespace std;
//
//double A[1001];
//
//int main()
//{
//	int k, n;
//	double d;
//	cin >> k;
//	for (int j = 0; j < k; ++j)
//	{
//		cin >> n;
//		cin >> d;
//		A[n] = d;
//	}
//	cin >> k;
//	for (int j = 0; j < k; ++j)
//	{
//		cin >> n;
//		cin >> d;
//		A[n] += d;
//	}
//	int count = 0;
//	vector<int> vec;
//	for (int i = 1000; i>=0; --i)
//	{
//		if (A[i]!=0.0)
//		{
//			++count;
//			vec.push_back(i);
//		}
//	}
//	if (count)
//	{
//		cout << count << " ";
//		for (int i = 0; i < count - 1; ++i)
//		{
//			//cout << vec[i] << " " << A[vec[i]] << " ";
//			printf("%d %0.1f ", vec[i], A[vec[i]]);
//		}
//		printf("%d %0.1f", vec[count - 1], A[vec[count - 1]]);
//	}
//	else
//	{
//		cout << 0;
//	}
//	return 0;
//}