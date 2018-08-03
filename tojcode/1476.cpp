#include<iostream>
using namespace std;

int mi(int k,int l)
{
    int w=1;
    if(l==0)
    return 1;
    else{
    for(int i=0;i<l;i++)
        {w*=k;}
    return w;
        }
}
int main()
{
 int d,k;
 cin>>d;
 int a[10]={0,0,0,0,0,0,0,0,0,0};
 for(int i=0;i<d;i++)
 {cin>>a[i];}
 
 for(int j=0;j<d;j++)
 { 
   for(k=0;a[j]%mi(2,k)==0;k++);
   cout<<a[j]/mi(2,k-1)<<" "<<k-1<<endl;
 }
 
 return 0;
}