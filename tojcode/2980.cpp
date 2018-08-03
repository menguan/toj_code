#include <cstdio>   
#include <cstring>   
using namespace std;  
int main()  
{  
    int n,i,round,score;  
    char line[101],goal[19];  
    while(scanf("%d",&n) && n)  
    {  
        getchar();  
        memset(goal,'-',sizeof(goal));  
        for(i=1;i<=n;i++)  
        {  
            gets(line);  
            if(strlen(line)>8 && strcmp(line+strlen(line)-7,"no good")==0 && line[ strlen( line ) - 8 ] == ' ' )    
                goal[i]='X';  
            else  
                goal[i]='O';  
        }  
        round=n/2;  
        if(2*round<n)  
            round++;  
        for(i=1;i<=round;i++)  
            printf("%d ",i);  
        printf("Score\n");  
        score=0;  
        for(i=1;i<=round;i++)  
        {  
            printf("%c ",goal[2*i-1]);  
            if(goal[2*i-1]=='O')  
                score++;  
        }  
        printf("%d\n",score);  
        score=0;  
        for(i=1;i<=round;i++)  
        {  
            printf("%c ",goal[2*i]);  
            if(goal[2*i]=='O')  
                score++;  
        }  
        printf("%d\n",score);  
    }  
    return 0;  
}  
