#include<cstdio>
#include<cstring>
using namespace std;

const int MAX=3000;
bool is[MAX+5];
int prime[500],k,c[3005];
struct node {
 	int m;
 	int count;
}a[3001][10];

void getprime() {
 	int i,j;
 	k=0;
 	for(i=2;i<=MAX;i++){
  		if(is[i]==false)
   		prime[k++]=i;
  		for(j=0;j<k&&i*prime[j]<=MAX;j++){
   			is[i*prime[j]]=true;
   			if(i%prime[j]==0) break;
  		}
 	}
}

void func(int n,int &len){
 	int m=n,i;
 	for(i=0;prime[i]*prime[i]<=n;i++)
  	if(n%prime[i]==0) {
   		a[m][len].m=prime[i];
  		a[m][len].count=0;
  		while(n%prime[i]==0){
    		n/=prime[i];
    		a[m][len].count++;
   		}
   		len++;
  	}
 	if(n>1){
  		a[m][len].count=1;
  		a[m][len++].m=n;
 	}
}
int main(){
 	int n,r,len[3005],i,j;
 	bool first;
 	getprime();
 	for(i=2;i<=MAX;i++) {
  		len[i]=0;
  		func(i,len[i]);
 	}
 	while(scanf("%d%d",&n,&r)!=EOF){
  		first=true;
  		memset(c,0,sizeof(c));
  		for(i=n;i>=n-r+1;i--)
   			for(j=0;j<len[i];j++)
    			c[a[i][j].m]+=a[i][j].count;
  		for(i=r;i>1;i--)
   			for(j=0;j<len[i];j++)
    			c[a[i][j].m]-=a[i][j].count;
  				printf("%dC%d = ",n,r);
  		for(i=2;i<=MAX;i++)
   			for(j=1;j<=c[i];j++) {
    			if(first) {
     				printf("%d",i);
     				first=false;
    			}
    			else
     				printf(" * %d",i);
   		}
   		printf("\n");
 	}
 	return 0;
}
