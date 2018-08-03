#include <iostream>
using namespace std;
int a[510],b[510],c[510];
int main(){
    int n,i,j;
    while(cin>>n,n){
        for(i=0;i<n;i++){
            cin>>b[i];
            c[i] = i;
        }
        for(i=0;i<n;i++){
            a[c[b[i]]]=i+1;
            for(j=b[i];j<n-i;j++)
                c[j]=c[j+1];
        }
        for(j=0,n--;j<n;j++)
            cout<<a[j]<<",";
        cout<<a[j]<<endl;
    }
    return 0;
}
/*
#include<stdio.h>
#include<algorithm>
using namespace std;
int n;
int num[501];
int great(int x)
{
int i,count=0;
for(i=1;num[i]!=x;i++)
  if(num[i]>x)
   count++;
return count;
}

int main()
{
int i,flag;
int order[501];

while(scanf("%d",&n),n)
{
  for(i=1;i<=n;i++) 
  {
   scanf("%d",&order[i]);
   num[i]=i;
  }
  flag=0;
  do
  {
   for(i=1;i<=n;i++)
    if(great(i)!=order[i])
     break;
   if(i==n+1)
    flag=1;
  }while(!flag && next_permutation(num+1,num+n+1));
  printf("%d",num[1]);
  for(i=2;i<=n;i++)
   printf(",%d",num[i]);
  printf("\n");
}
return 0;
}

*/
