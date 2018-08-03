/*aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa  aaa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa 
aaaaa    aaaaa    aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaa          aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa aaaaaaaa   aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaa    aaaaa     aaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaa aaaaa  aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaa a aaaaa   aa  aaaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaa  aaaaa  aaaaa aaaaaaaaaaaaaaaaaaaaaaaaaaa
aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa
*/
#include<iostream>
#include<cstring>
#include<stdio.h>
#include<stack>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a;
priority_queue<int,vector<int>,greater<int> > q;
int main()
{
    int n;long long ans=0;
    
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a;
        q.push(a);
        //cout<<a<<endl;
    }
   q.push(1000000001);int b,c;
   while(!q.empty())  
   {
     b=q.top();
     q.pop();                    
     c=q.top();
     q.pop();
     if(c==1000000001)
       break;
     ans+=(c+b);
     //cout<<ans<<" "<<b<<" "<<c<<endl;
     q.push(c+b);
   }
   
   cout<<ans<<endl;
    //while(1);
}   
