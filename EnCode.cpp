#include <vector>
#include <iostream>
#include "encode.h"
#include "Algorithm_getPoint.h"
#include "Algorithm_getKey.h"
#include "inArea.h"
using namespace std;
vector<int> EnCode::encode(string str, int p, int a, int b, int px, int py, int k, int ra)
{
    Algorithm_getKey agk;
    inArea inA;
    vector<int> get_publickey;
    get_publickey = agk.algorithm_getKey(p, a, px, py, px, py, ra);//raG
    k = inA.inarea(k, p);
    vector<int> get_kG;
    get_kG = agk.algorithm_getKey(p, a, px, py, px, py, k);//kG
    vector<int> get_str_point;
    vector<int> PmkPa;
    vector<int> get_kPa;
    vector<int> encoded_message;
    get_kPa = agk.algorithm_getKey(p, a, get_publickey[0], get_publickey[1], get_publickey[0], get_publickey[1], k);//kPa
    for (int i = 0; i < str.size(); i++)
    {
        get_str_point = agk.algorithm_getKey(p, a, px, py, px, py, str[i] + 1);
        PmkPa = agk.algorithm_getKey(p, a, get_str_point[0], get_str_point[1], get_kPa[0], get_kPa[1], 2);
        encoded_message.push_back(get_kG[0]);
        encoded_message.push_back(get_kG[1]);
        encoded_message.push_back(PmkPa[0]);
        encoded_message.push_back(PmkPa[1]);

        //vector<int> kee = Algorithm_getKey(p, a, px, py, px, py, k);
    }
    return encoded_message;
}

string EnCode::DecIntToHexStr(long long num)
{
    string str;
    long long Temp = num / 16;
    int left = num % 16;
    if (Temp > 0)
        str += DecIntToHexStr(Temp);
    if (left < 10)
        str += (left + '0');
    else
        str += ('A' + left - 10);
    return str;
}

string EnCode::DecStrToHexStr(string str)
{
    long long Dec = 0;
    for (int i = 0; i < str.size(); ++i)
        Dec = Dec * 10 + str[i] - '0';
    return DecIntToHexStr(Dec);
}