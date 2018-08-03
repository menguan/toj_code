#include<stdio.h>
#include<string.h>
#include<cstdlib>
#include<cstring>
char ss[120010][50];
bool Bsearch(char *s, int n) {
	int left = 0, right = n - 1, middle, r;
	while (left <= right) {
		middle = (left + right) / 2;
		r = strcmp(s, ss[middle]);
		if (r == 0) 
  			return 1;
		if (r < 0)
			right = middle - 1;
		else
			left = middle + 1;
	}
	return 0;
} 
int main() {
    char s1[100], s2[100];
    int i = 0, j, k, n, len,l,m;
	while (scanf("%s", ss[i]) != EOF) i++;
	n = i;
	for (i = 0; i < n; i++) {
		len = strlen(ss[i]);
		for (j = 0, k = 0; j < len - 1; j++) {
			s1[k++] = ss[i][j];
			s1[k] = '\0';
			for(m=0,l=k;l<len;l++)
				s2[m++]=ss[i][l];
			s2[m]='\0';  
//puts(s1);
//puts(s2);
//system("pause");
			if (Bsearch(s1, n) && Bsearch(s2, n)) {
				puts(ss[i]);
				break;
			}
		}
	}
}

