#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
typedef long long ll;
ll num;
ll dp[20][4];
ll digit[20];
void pre() {
    dp[0][0] = 1;
	for (int i = 1; i <= 20; i++) {
		dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
		dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
	}
}
void solve() {
	int cont = 1;
	if (num < 49) {
        puts("0"); return;
	} num++;
	memset(digit, 0, sizeof(digit));
	while (num) {
		digit[cont++] = num % 10;
		num /= 10;
	}
	ll ans = 0;
	bool flag = false;
	for (int i = cont - 1; i >= 1; i--) {
		ans += digit[i] * dp[i - 1][2];
		if (flag) ans += digit[i] * dp[i - 1][0];
		else if (digit[i] > 4) ans += dp[i - 1][1];
		if (digit[i + 1] == 4 && digit[i] == 9) flag = true;
	}
	printf("%lld\n", ans);
}
int main() {
	int cas;
	scanf("%d", &cas);
	pre();
	while (cas--) {
		scanf("%lld", &num);
		solve();
	}
}