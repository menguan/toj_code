#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int solve(string str1, string str2)
{
    int i, j, k, len1, len2, ans;
    bool flag;
    len1 = str1.length();
    len2 = str2.length();
    for (i = 0; i < len1; i++)
    {
        flag = 1;
        for (j = i , k = 0; j < len1 && k < len2; j++ , k++)//前串从j开始 后串从k开始 直到其中一个到头 
        {
            if (str1[j] == '2' && str2[k] == '2')
            {
                flag = 0;
            }
        }
        if (flag)
        {
            return max(len1, i + len2);
        }
    }
    return len1 + len2;
}

int main()
{
    int ans;
    string s1, s2;
    while( cin >> s1 >> s2)
    {
     ans = min(solve(s1, s2), solve(s2, s1));
     cout << ans << endl;
    }
}
