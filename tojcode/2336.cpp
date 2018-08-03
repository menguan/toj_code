//做这道题真长知识啊
//******************************
//******************************
//******************************
#include <string.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
unsigned n,i,j,tp,mask=~0,ip=~0;
int main(){
	for(scanf("%u ",&n);n--;){
		tp=0;
		for(i=4;i--;){
			scanf("%u%*c",&j);
			tp|=j<<8*i;
		}
		ip&=tp;
		for(i=ip^tp;i;i>>=1)mask&=~i;
	}
	ip&=mask;
	for(j=2;j--;)
		for(i=4;i--;) printf("%d%c",((j?ip:mask)>>8*i)&255,i?'.':'\n');
}
