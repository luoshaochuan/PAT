#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct Record
{
	string id;
	int hour;
	int min;
	int sec;
};

bool cmp(Record &r1, Record &r2)
{
	if (r1.hour != r2.hour)
		return r1.hour<r2.hour;
	else if (r1.min != r2.min)
		return r1.min<r2.min;
	else
		return r1.sec<r2.sec;
}


int main()
{
	vector<Record> in_rec;
	vector<Record> out_rec;
	int m;
	cin >> m;
	for (int i = 0; i<m; ++i)
	{
		string id, in_time, out_time;
		cin >> id >> in_time >> out_time;
		Record irec, orec;
		irec.id = id;
		irec.hour = atoi(in_time.substr(0, 2).c_str());
		irec.min = atoi(in_time.substr(3, 5).c_str());
		irec.sec = atoi(in_time.substr(6, 8).c_str());
		orec.id = id;
		orec.hour = atoi(out_time.substr(0, 2).c_str());
		orec.min = atoi(out_time.substr(3, 5).c_str());
		orec.sec = atoi(out_time.substr(6, 8).c_str());
		in_rec.push_back(irec);
		out_rec.push_back(orec);
	}
	sort(in_rec.begin(), in_rec.end(), cmp);
	sort(out_rec.begin(), out_rec.end(), cmp);
	cout << in_rec[0].id << " " << out_rec.back().id << endl;
	return 0;
}