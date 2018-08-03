#include<stdio.h>
#include<iostream>
using namespace std;

#include<math.h>
#include<algorithm>
char words[610][30];
char L[310];
int dp[310];
int main()
{
    int w,len;
    while( scanf("%d%d", &w, &len) != EOF )
    {
           scanf("%s", L);
           for(int i=0;i< w;i++)
             scanf("%s", &words[i][0]);
           int dt;
           for(int i=0;i< len; i++)
             dp[i] = len - i;
           bool flag;
           int tmp;

           for(int i=len-1; i>=0; i--)
           {
                   dp[i] = dp[i+1] + 1;
                   for(int j=0; j<w;j++)
                   {
                           flag = false;
                           if(L[i] != words[j][0])  continue;
                           dt = i;
                           tmp = 0;
                           while(dt < len)
                           {
                                if( words[j][tmp] == L[dt] )
                                {  ++dt;  ++tmp;  }
                                else ++dt;

                                if(words[j][tmp] == '\0')
                                {  flag = true;  break;  }
                           }

                           if(flag) dp[i] = min( dp[i], dp[dt]+dt-i-tmp );
                   }


           }

           printf("%d\n", dp[0]);

    }
}
