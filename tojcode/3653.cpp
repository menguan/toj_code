#include <iostream>
#include <string.h>
#include<stdio.h>
using namespace std;
bool mark[20000000];
void prime()
{
    int i, j;
    memset(mark, false, sizeof(mark));
    mark[1]=true;
    for(i=2; i<=6500; i++)
        if(mark[i]==false)
        {
            
            for(j=30000000/i-1; i*j<=40000000; j++)
                mark[i*j-20000000]=true;
        }
}

int main()
{
    int i;
    prime();
    for(i=30000000; i<=40000000; i++)
        if(mark[i-20000000]==false)
   printf("%d\n",i);
   //while(1);
    return 0;
}
