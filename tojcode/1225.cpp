/*struct f
{
       int v,w,next;
}edge[121212];
int adj[101010];
for(int i=adj[u];i!=-1;i=edge[i].next)
{
  */             



#include <stdio.h>   
#include <iostream>   
#include <string.h>   
#include <string>   
using namespace std;   
int main()   
{   
    char a[300],b[300];   
    int map[300];   
    int t,i,j,n;   
    scanf("%d",&t);   
    getchar();   
    while(t--)   
    {   
        gets(a);   
        memset(map,0,sizeof(map));   
        for(i = 0,j = 0; a[i]; i++)  
        {   
            if(a[i] != ' ')   
            {   
                b[j++] = a[i];   
            }   
        }   
        b[j] = 0;   
        n = j;   
        for(i = 0; i < n; i++)   
        {   
            if(b[i] == '-' && b[i+1] == '(')   
            {   
                map[i+1] = 1;   
                int count = 0,flag = 0;   
                for(j = i + 1;; j++)   
                {   
                    if(b[j] == '(')   
                    {   
                        count++;   
                        flag = 1;   
                    }   
                    else if(b[j] == ')')   
                    {   
                        count--;   
                        if(!count && flag)   
                        {   
                            map[j] = 1;   
                            break;   
                        }   
                    }   
                }   
            }   
        }   
        for(i = 0;i < n; i++)   
        {   
            if(map[i] && b[i] == '(')   
            {   
                int count = 0, count2 = 0;   
                for(j = i;; j++)   
                {   
                    if(b[j] == '(')   
                    {   
                        count++;   
                    }   
                    else if(b[j] == ')')   
                    {   
                        count--;   
                        if(!count)   
                        {   
                            if(count2 == 1)   
                            {   
                                map[j] = 0;   
                                map[i] = 0;   
                            }   
                            break;   
                        }   
                    }   
                    else   
                    {   
                        count2++;   
                    }   
                }   
            }   
        }   
                        
        for(i = 0;i < n; i++)   
        {   
            if(b[i] == '(' || b[i] == ')')   
            {   
                if(map[i])   
                {   
                    printf("%c",b[i]);   
                }   
            }   
            else   
                printf("%c",b[i]);   
        }   
        puts("");   
    }   
    return 0;   
}
