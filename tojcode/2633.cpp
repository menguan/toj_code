#include<iostream>
#include<algorithm>
#include<set>

using namespace std;
long long s[100010];
long long r2[100000];
long long r3[100000];
long long r5[100000];
long long r7[100000];
int main()
{
    s[1]=1;
    int pos2,pos3,pos5,pos7;
    pos2=pos3=pos5=pos7=1;
    for(int i=1;i<80000;i++)
    {
       r2[i]=s[i]*2;
       r3[i]=s[i]*3;
       r5[i]=s[i]*5;
       r7[i]=s[i]*7;  
       while(r2[pos2]<=s[i]) pos2++;
       while(r3[pos3]<=s[i]) pos3++;
       while(r5[pos5]<=s[i]) pos5++;
       while(r7[pos7]<=s[i]) pos7++; 
       s[i+1]=min(min(r2[pos2],r3[pos3]),min(r5[pos5],r7[pos7]));
       
    }     
    int t;
    cin>>t;
    int n;
    while(t--)
    {
              cin>>n;
              cout<<s[n]<<endl;
    }
}          
    
    
