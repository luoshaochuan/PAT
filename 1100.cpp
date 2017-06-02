///*
//People on Mars count their numbers with base 13:
//
//Zero on Earth is called "tret" on Mars.
//The numbers 1 to 12 on Earch is called "jan, feb, mar, apr, may, jun, jly, aug, sep, oct, nov, dec" on Mars, respectively.
//For the next higher digit, Mars people name the 12 numbers as "tam, hel, maa, huh, tou, kes, hei, elo, syy, lok, mer, jou", respectively.
//For examples, the number 29 on Earth is called "hel mar" on Mars; and "elo nov" on Mars corresponds to 115 on Earth. In order to help communication between people from these two planets, you are supposed to write a program for mutual translation between Earth and Mars number systems.
//
//Input Specification:
//
//Each input file contains one test case. For each case, the first line contains a positive integer N (< 100). Then N lines follow, each contains a number in [0, 169), given either in the form of an Earth number, or that of Mars.
//
//Output Specification:
//
//For each number, print in a line the corresponding number in the other language.
//
//Sample Input:
//4
//29
//5
//elo nov
//tam
//Sample Output:
//hel mar
//may
//115
//13
//*/
//
///*
//题意：根据第一行输入行数将地球和火星数字互相翻译
//分析：需要判断输入的是字符串还是数字，然后查表翻译
//*/
//
//#include<iostream>
//#include<string>
//#include<map>
//
//using namespace std;
//
//bool is_num(string str)
//{
//	for (int i = 0; i < str.length(); ++i)
//	{
//		if (!isdigit(str[i]))
//		{
//			return false;
//		}
//	}
//	return true;
//}
//
//
//int main()
//{
//	//映射
//	string low[13] = {"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
//	string high[13] = {"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
//
//	map<string, int> mars;
//	for (int i = 0; i < 13; ++i)
//	{
//		mars[low[i]] = i;
//		mars[high[i]] = i * 13;
//	}
//
//	int lines;
//	cin >> lines;
//	string str;
//	getline(cin, str);
//	for (int i = 0; i < lines; ++i)
//	{
//		string str;
//		getline(cin, str);
//		if (is_num(str))
//		{
//			int num = atoi(str.c_str());
//			int h = num / 13;
//			int l = num % 13;
//			if (h&&l)
//			{
//				cout << high[h] << " " << low[l];
//			}
//			else if (h)
//			{
//				cout << high[h];
//			}
//			
//			else if (l)
//			{
//				cout<<low[l];
//			}
//			else
//				cout << "tret";
//			cout << endl;
//		}
//		else
//		{
//			if (str.length()>4)
//			{
//				cout << mars[str.substr(0, 3)] + mars[str.substr(4, 7)] << endl;
//			}
//			else
//			{
//				cout << mars[str] << endl;
//			}
//		}
//	}
//	return 0;
//}