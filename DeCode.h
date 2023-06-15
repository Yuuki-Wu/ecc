#pragma once
#include <vector>
#include <string>
using namespace std;
class DeCode
{
public :
	vector<string> decode(int p, int a, vector<int> kG, vector<int> Pmkpa, int ra);
	vector<string> format(string str);
	vector<int> HexStrToDecStr(vector<string> format_string);
};