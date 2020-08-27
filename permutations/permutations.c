#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int next_permutation(int n, char **s)	{
    int i, k, l;
    char te[11];

    k = -1;
    for(i = 0; i < n - 1; i++)    {
        if(strcmp(s[i], s[i + 1]) < 0)    k = i;
        //printf("i = %d, s1 = %s, s2 = %s, S = %d\n", i, s[i], s[i+1], strcmp(s[i], s[i + 1]));
    }

    // printf("k = %d\n", k);
    if(k == -1) 	// last permutation 
        return 0;

    for(i = k; i < n; i++)
        if(strcmp(s[k], s[i]) < 0)    l = i;

    // printf("l = %d\n", l);
    // swap 
    strcpy(te, s[k]);
    strcpy(s[k], s[l]);
    strcpy(s[l], te);

    // reverse
    if(k < n - 2)	{
        for(i = k + 1; i < (n + k + 1) / 2; i++)	{
            strcpy(te, s[i]);
            strcpy(s[i], s[n + k - i]);
            strcpy(s[n + k - i], te);
        }
    }
   
    return 1;
}

int main()	{
	char **s;
	int n;
	scanf("%d", &n);
	s = calloc(n, sizeof(char*));
	for (int i = 0; i < n; i++)	{
		s[i] = calloc(11, sizeof(char));
		scanf("%s", s[i]);
	}

	do	{
		for (int i = 0; i < n; i++)
			printf("%s%c", s[i], i == n - 1 ? '\n' : ' ');
	} while (next_permutation(n, s));

	for (int i = 0; i < n; i++)
		free(s[i]);

	free(s);
	return 0;
}
