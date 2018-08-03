/*版权所有 版权所有 版权所有 hehe
 */
#include <iostream>
#include <cstring>
#include <set>
using namespace std;
int dir[5][2] = {-1,0,0,-1,1,-1,1,0,0,1};
pair < int, int > maja[200000];

int main()
{
	for (int i = 1, j = 1, k = 0; i < 190000 ; i += j, j += 6, k++)
	{
		maja[i] = make_pair(0, k);
		for (int m = 0; m < k; m++)
			maja[i - m] = make_pair(m, k - m);

		int current = i;
		for (int m = 0; m < 5; m++)
			for (int n = 0; n < k; n++)
			{
				int x = maja[current].first + dir[m][0];
				int y = maja[current].second + dir[m][1];
				maja[current + 1] = make_pair(x, y);
				current++;
			}
	}

	int willi;
	while (cin >> willi)
		cout << maja[willi].first << " " << maja[willi].second << endl;

	return 0;
}
