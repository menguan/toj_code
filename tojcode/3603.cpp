#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int t[10010];
int d[10010];
int main()
{ 
    int N,K;
    while(cin>>N>>K)
    {
            for(int i=1;i<=K;i++)
            {  cin>>t[i];d[i]=N-t[i];
            }
           sort(d+1,d+K+1);
           int answer=0;
           for (int i=1;i<=K;i++)

              if (answer<(d[i+1]-d[i])/2) answer=(d[i+1]-d[i])/2;

          if (answer<N-d[K]) answer=N-d[K];

          if (answer<d[1]) answer=d[1];

          cout<<answer<<endl;
    }
}  
    
