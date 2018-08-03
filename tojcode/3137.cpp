#include<cstdio> //每次把变量后面的type逆序放到前面来 简单模拟 
#include<ctype.h> 
#include<cstring> 
int main() 
{ 
     char end,head[300],sub[300],output[300]; 
     int i,j,k,len,start; 
     while(scanf("%s",head)!=EOF) 
     { 
         for(i=0,j=0;head[i]!='\0';i++,j++) 
             output[j]=head[i]; 
         start=j; 
         while(1) 
         { 
             scanf("%s",sub); 
             len=strlen(sub); 
             end=sub[len-1]; 
             sub[len-1]='\0'; 
             for(i=len-2,j=start;!isalpha(sub[i]);i--,j++) 
             { 
                 if(sub[i]==']') 
                 { 
                     output[j++]='['; 
                     output[j]=']'; 
                     i--; 
                 } 
                 else 
                     output[j]=sub[i]; 
             } 
             output[j]=' '; 
             for(i=0,k=j+1;isalpha(sub[i]);i++,k++) 
                 output[k]=sub[i]; 
             output[k]=';'; 
             output[k+1]='\0'; 
             printf("%s\n",output); 
             if(end==';')
                break; 
         } 
     }   
} 
