#include<stdlib.h>
#include<string.h>
#include<stdio.h> 

long fbase[20];

long faktoryel(int n)	{
    if((n == 0) || (n == 1))
        return 1;
    else if( n <= 20 )
        return n * faktoryel(n - 1);
    else
        return -1;
}

void fill_fbase()	{
    int c; 

    fbase[0] = 1;
    for(c = 1; c <= 20; c++)
        fbase[c] = fbase[c - 1] * c;
}

char *int2f(int n)	{
    char *facns, t; 
    int p, slen;
    int bolen = 2;

    facns = (char *)malloc(sizeof(char) * 20);
    p = 1; 
    facns[0] = 0x30;
    while(n > 0)	{
        facns[p++] = (n % bolen) + 0x30;
        n = n / bolen++; 
    }
    
    slen = p;
    p = p >> 1; 
    while(p--)	{
        t = facns[p]; 
        facns[p] = facns[slen - p - 1];
        facns[slen - p - 1] = t; 
    }
        
    
    return facns;
}


int main()	{
    int c;
    char *test;

    fill_fbase();
/*  test = int2f(463);

    printf("%s\n", test);
    free(test);

    test = int2f(1903);

    printf("%s\n", test);
    free(test);
*/
    for(c = 0; c <= 24; c++)	{
        test = int2f(c);
        printf("%s\n", test);
        free(test);
    }
    
    return 0; 
}
