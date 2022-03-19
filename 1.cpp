#include <sstream>
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

#define MAX_N 200

class Solution
{
public:
    int calcStr(string s)
    {
        int num = 0;
        for (char i : s)
        {
            if (i >= '0' && i <= '9')
            {
                num = num * 16 + (i - '0');
            }
            if (i >= 'A' && i <= 'Z')
            {
                num = num * 16 + ((i - 'A') + 10);
            }
        }
        return num;
    }
    string SimpleCheckSum(const string &inputStr)
    {
        unsigned int num[MAX_N + 5];
        memset(num, 0, sizeof(num));
        int count = 0;
        int pre = 0;
        int current = inputStr.find(' ', pre);
        while (current != string::npos)
        {
            if (current > pre)
            {
                string temp = inputStr.substr(pre, current - pre);
                num[count] = calcStr(temp);
                count++;
            }
            pre = current + 1;
            current = inputStr.find(" ", pre);
        }
        if (pre != inputStr.size())
        {
            string temp = inputStr.substr(pre);
            num[count] = calcStr(temp);
            count++;
        }
        // for (int i = 0; i < count; i++) {
        //     printf("%X\n", num[i]);
        // }
        if (count / 4 != 0 && count != 1) {
            int t = 4 - (count % 4);
            for (int i = 0; i < t; i++) {
                num[count++] = 0xff;
            }
        }
        unsigned int re[4];
        memset(re, 0, sizeof(re));
        for (int i = 0; i < count; i += 4) {
            re[0] ^= num[i];
            re[1] ^= num[i + 1];
            re[2] ^= num[i + 2];
            re[3] ^= num[i + 3];
        }
        char cre[8];
        sprintf(cre, "%X%X%X%X", re[0], re[1], re[2], re[3]);
        return cre;
    }
};

inline string ReadLine()
{
    string line;
    getline(cin, line);
    return line;
}

int main()
{
    string inputStr = ReadLine();
    Solution solu;
    string result = solu.SimpleCheckSum(inputStr);
    cout << result << endl;
    return 0;
}