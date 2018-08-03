#include <iostream>
using namespace std;
int score[63]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,3,6,9,12,15,18,21,24,27,30,33,36,39,42,45,48,51,54,57,60,25,50};
int main()
{
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++)
    {
        int temp;
        int ans=0;
        cin>>temp;
        for(int j=0;j<63;j++)
            for(int k=j;k<63;k++)
                for(int m=k;m<63;m++)
                    if(score[j]+score[k]+score[m]==temp)
                        ans++;
        cout<<"Scenario #"<<cas<<":"<<endl<<ans<<endl<<endl;
    }
}
