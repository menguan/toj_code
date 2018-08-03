#include<cstring>
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long LL;
const int maxn = 1e5 + 10;
int A[maxn],cnt[maxn],f[maxn];
std::vector<int> v;
int main(){
	int n;
	while(~scanf("%d",&n)&&n){
		memset(cnt,0,sizeof(cnt));
		memset(f,0,sizeof f);
		v.clear();
		LL sum=0;
		LL M=0;
		for(int i=1;i<=n;i++){
			scanf("%d",A+i);
			if(A[i]>M)M=A[i];
			sum+=A[i];
			cnt[A[i]]++;
		}
		if(sum&1){
			puts("No");
			continue;
		}
		sum/=2;
		bool ok=false;
		for(int i=M;!ok&&i>=1;i--){
			f[i]=min((LL)cnt[i],sum/i);
			sum-=(LL)f[i]*i;
			if(sum==0){
				ok=true;
				break;
			}
		}
		if(!ok){
			puts("No");
		}else{
			puts("Yes");
			for(int i=1;i<=n;i++){
				if(i==1){
					if(f[A[i]]>0){
						printf("1");
						f[A[i]]--;
					}
					else printf("-1");
				}
				else{
					if(f[A[i]]>0){
						printf(" 1");
						f[A[i]]--;
					}
					else printf(" -1");
				}
			}
			puts("");
		}

	}
	return 0;
}
