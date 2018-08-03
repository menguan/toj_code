#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <cstring>
using namespace std;
int main()

{

    int stocks,days;

    long money;

    int price[100][20];

    long dp[500001];

    long bulk,value;

    cin >>stocks >>days >>money;

    for (long i=0;i<stocks;i++)

        for (long j=0;j<days;j++)

            cin >>price[i][j];

    for (int day=0;day<days-1;day++)   

    {

        memset (dp,0,sizeof(dp[0])*(money+1));

        for (int i=0;i<=stocks;i++)

        {

            value=price[i][day+1];       

            bulk=price[i][day];         

            if (i==stocks)     //不买股票        

            {

               value=1;

               bulk=1;

            }

            for (int j=bulk;j<=money;j++)       

            {

                if (dp[j]<dp[j-bulk]+value)

                   dp[j]=dp[j-bulk]+value;

            }

        }

        money=dp[money];

    }

    cout <<money <<endl;

    //while(1);

}
