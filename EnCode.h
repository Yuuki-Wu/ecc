#pragma once
#include <vector>
using namespace std;
class EnCode
{
public:
	vector<int> encode(string str, int p, int a, int b, int px, int py, int k, int ra);
	string DecIntToHexStr(long long num);
	string DecStrToHexStr(string str);
};