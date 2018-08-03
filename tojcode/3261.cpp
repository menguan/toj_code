#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s[1010];
int main()
{
    string ss;
    int n,m;
    int a,b;
    cin>>n>>m;
    for(int i=0;i<n;i++)
      cin>>s[i];
    for(int cas=1;cas<=m;cas++)
    {
         cin>>ss>>a>>b;
         if(a>b)
           swap(a,b);
         cout<<"Number "<<cas<<":"<<endl;
         int cnt=0;
         for(int i=0;i<n;i++)
         {
              int temp=0;
              for(int j=0;j<11;j++)
              {
                  if(s[i][j]!=ss[j])
                    temp++;
              }
              if(temp>=a&&temp<=b)
              {
                cnt++;
                cout<<s[i]<<endl;
              }
         }
         cout<<"Total: "<<cnt<<endl<<endl;
    }
}
                     
