#include "DeCode.h"
#include <string>
#include "Algorithm_getKey.h"
using namespace std;
vector<string> DeCode::decode(int p, int a, vector<int> kG, vector<int> Pmkpa, int ra)
{
	Algorithm_getKey agk;
	vector<int> Pm;
	vector<int> rakG;
	vector<int> Pmtotal;
	vector<string> message;
	rakG = agk.algorithm_getKey(p, a, kG[0], kG[1], kG[0], kG[1], ra);
	rakG[1] = p - rakG[1];
	bool state = 1;
	int times = 0;


	for (int i = 0; i < Pmkpa.size() / 2; i++)
	{
		Pm = agk.algorithm_getKey(p, a, Pmkpa[2 * i], Pmkpa[2 * i + 1], rakG[0], rakG[1], 2);
		while (1 && state)
		{
			vector<int> inP = agk.algorithm_getKey(p, a, 283, 315, 283, 315, times);
			if (Pm[0] == inP[0] && Pm[1] == inP[1])
			{
				state = false;
				Pm[0] = times - 1;
			}
			else
			{
				times++;
			}
		}
		state = true;
		times = 0;
		Pmtotal.insert(Pmtotal.end(), Pm.begin(), Pm.end());
	}
	for (int i = 0; i < Pmtotal.size(); i += 2)
	{
		int num = Pmtotal[i];
		string str;
		str = int(num);
		message.push_back(str);
	}
	return message;
}

vector<string> DeCode::format(string str)
{
	vector<string> text;
	int count = 0;
	string x, y;
	for (int i = 2; i < str.size(); i++)
	{
		if (str[i] != 'G' && count % 2 == 0)
		{
			x += string(1, str[i]);
			if (i + 1 < str.size())
			{
				if (str[i + 1] == 'G')
				{
					text.push_back(x);
					x = "";
				}
			}
		}
		else if (str[i] != 'G' && count % 2 == 1)
		{

			y += string(1, str[i]);
			if (i + 1 < str.size())
			{
				if (str[i + 1] == 'G')
				{
					text.push_back(y);
					y = "";
				}
			}
			else if (i == str.size() - 1)
			{
				text.push_back(y);
				y = "";
			}

		}
		else
		{
			count++;
		}
	}
	return text;
}

vector<int> DeCode::HexStrToDecStr(vector<string> format_string)
{
	vector<int> dec_message;
	int pointer = 0;
	while (pointer < format_string.size())
	{
		int n = format_string[pointer].length();
		long long num = 0;
		for (int i = 0; i < n; i++) {
			if (format_string[pointer][i] >= '0' && format_string[pointer][i] <= '9') {
				num += (format_string[pointer][i] - '0');
			}
			else if (format_string[pointer][i] >= 'a' && format_string[pointer][i] <= 'f') {
				num += (format_string[pointer][i] - 'a' + 10);
			}
			else if (format_string[pointer][i] >= 'A' && format_string[pointer][i] <= 'F') {
				num += (format_string[pointer][i] - 'A' + 10);
			}
			if (i < n - 1)
			{
				num *= 16;
			}
		}
		dec_message.push_back(num);
		pointer++;
	}


	return dec_message;
}
