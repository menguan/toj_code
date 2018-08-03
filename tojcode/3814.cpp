#include<stdio.h>
int main(){
    int T;
    int x[100000];
    scanf("%d",&T);
    for(int i = 1 ; i < 2 * T ; i+= 2)
        scanf("%d",&x[i]);
    int ok,a,b;
    for(a = 0 ; a <= 10000 ; a++){
        for(b = 0; b <= 10000 ; b++){
             ok = 1;
             for(int i = 2 ; i <= 2 * T ; i++){
                 if(i & 1){
                    if(x[i] != ((a * x[i - 1] + b) % 10001)){
                        ok = 0;
                        break;
                    }
                 }
                 else{
                    x[i] = (a * x[i - 1] + b) % 10001;
                 }
             }
             if(ok)
                break;
        }
        if(ok)
            break;
    }
    for(int i = 2 ; i <= 2 * T ; i+= 2)
    printf("%d\n",x[i]);
    //while(1);
    return 0;
}
