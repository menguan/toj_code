#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <map>
using namespace std;

const int N = 25;

int n, m, have[N];
map<string, int> hash;
string name[N];

int main() {
	int cas = 0;
	while (~scanf("%d%d", &n, &m) && n || m) {
		hash.clear();
		memset(have, 0, sizeof(have));
		for (int i = 1; i <= n; i++) {
			cin >> name[i];
			hash[name[i]] = i;
		}
		string a, b; int val;
		while (m--) {
			cin >> a >> b >> val;
			int u = hash[a], v = hash[b];
			have[u] += val;
			have[v] -= val;
		}
		printf("Case #%d\n", ++cas);
		for (int i = 1; i < n; i++) {
			if (have[i] < 0)
				cout << name[i] << " " << name[n] << " " << -have[i] << endl;
			else if (have[i] > 0)
				cout << name[n] << " " << name[i] << " " << have[i] << endl;
			//have[n] -= have[i];
		}
		printf("\n");
	}
	return 0;
}
//*********************************************************8
//*******************************************************8
//**********************************************************8
