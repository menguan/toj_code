#include<stdio.h> 
#include<string.h> 
#include<ctype.h> 
#include<iostream>
#include<string>
#include<cstdlib>
int main() 
{ 
    
    int m,n,i,j,num[20],max,t=1,a,k,len; 
    char word[20][20],excuse[20][71],ch[71]; 
    while(scanf("%d%d",&m,&n)!=EOF) 
    { 
        getchar(); 
        for(i=0; i<m; i++) 
        { 
            scanf("%s",word[i]); 
            getchar(); 
        }   
        memset(num,0,sizeof(num)); 
        max=0; 
        for(i=0; i<n; i++) 
        { 
            gets(excuse[i]); 
            len=strlen(excuse[i]); 
            for(j=0; j<len; j++) 
            { 
                a=0; 
                while(isalpha(excuse[i][j])) 
                { 
                    ch[a++]=tolower(excuse[i][j]); 
                    j++; 
                } 
                if(a>0) 
                { 
                    ch[a]='\0'; 
                    for(k=0; k<m; k++) 
                    { 
                        if(strcmp(ch,word[k])==0) 
                        { 
                            num[i]++;break; 
                        } 
                    } 
                } 
            } 
            max=max>num[i]?max:num[i]; 
        } 
        printf("Excuse Set #%d\n",t++); 
        for(i=0; i<n; i++) 
        { 
            if(num[i]==max) 
            { 
                printf("%s\n",excuse[i]); 
            } 
        } 
        printf("\n"); 
    } 
    return 0; 
} 
