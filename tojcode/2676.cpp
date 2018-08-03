/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaa                 aaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaa  aaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaa   aaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaa   aaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaa   aaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaa    aaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaa   aaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaa   aaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaa                aaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
#include<queue>
using namespace std;
int num[200];
int main()
{
    int n,m;int t;int temp;
    while(cin>>n>>m&&(n+m))
    {
        memset(num,0,sizeof(num));
        for(int i=0;i<n;i++)
        {
            cin>>t;
            while(t--)
            {
                cin>>temp;
                num[temp]++;
            }
        }
        int ans=0;
        int now=0;
        for(int i=0;i<101;i++)
        {
           if(num[i]>now)
           {
              ans=i;
              now=num[i];
           }
        }
        if(now>=m)
        {
            cout<<ans<<endl;
        }
        else 
          cout<<0<<endl;
    }
}                                                  
    
