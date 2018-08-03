#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <utility>
#include <iomanip>
#include <stack>
#include <list>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <ctype.h>
/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
using namespace std;

int main()
{
	//freopen ("beads.in", "r", stdin);
	//freopen ("beads.out", "w", stdout);
	int i, len, maxs, start, change;
	bool hash[30] = {0};
	string s;
	cin >> len >> s;
	s = s + s;    //实现首尾相
	maxs = 1, change = start = 0;
	len <<= 1;    
	if (s[0] != 'w')
		hash[s[0]-'a'] = true, change = 1;
	for (i = 1; i < len; i++)
	{
		if (s[i] != 'w' && !hash[s[i]-'a'])
			memset (hash, false, sizeof(hash)), hash[s[i]-'a'] = true, change++;
		if (change > 2 || i == len-1)
		{
			if (maxs < i - start)
				maxs = i - start;
			change = 0;
			memset (hash, false, sizeof(hash));
			i = start;
			start++;
			if (s[start] != 'w')
				hash[s[start]-'a'] = true, change = 1;
		}
	}
	if (maxs > len / 2)   
		maxs = len / 2;
	cout << maxs << endl;
	//while(1);
	return 0;
}
