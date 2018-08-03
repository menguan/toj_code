#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
int main()
{
	int i;
	int nNum;
	string ori[11], rep[11];
	string nText;
	while (cin >> nNum, nNum)
	{
		getchar();
		for (i = 0; i < nNum; i ++)
		{
			getline(cin, ori[i]);
			getline(cin, rep[i]);
		}
		getline(cin, nText);
		for (i = 0; i < nNum; i ++)
		{
			int pos = nText.find(ori[i]);
			while (pos != string::npos) 
			{
				nText = nText.replace(pos, ori[i].size(), rep[i]);
				pos = nText.find(ori[i]);
			}
		}
		if (nText.size() <= 80)
		{
			cout << nText << endl;
		}
		else
		{
			nText[80] = '\0';
			cout << nText << endl;
		}
	}
	return 0;
}