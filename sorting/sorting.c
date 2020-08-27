#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(x, y) (((x) > (y)) ? (x) : (y))
#define MIN(x, y) (((x) < (y)) ? (x) : (y))

int lexicographic_sort(const char* a, const char* b) {
    return strcmp(a, b);
}

int lexicographic_sort_reverse(const char* a, const char* b) {
    return strcmp(b, a);
}

int sort_by_number_of_distinct_characters(const char* a, const char* b) {
    int c0, c1, tslen;
    char *ta, *tb;
    
    tslen = 0;
    ta = (char *)malloc(strlen(a) * sizeof(char));
    tb = (char *)malloc(strlen(b) * sizeof(char));

    for(c0 = 0; c0 < strlen(a); c0++)	{
        for(c1 = 0; c1 < c0; c1++)
            if( ta[c1] == a[c0] )    break;
        if( c0 == c1 ) ta[tslen++] = a[c0];
    }
    // ta[tslen] = 0;

    tslen = 0;
    for(c0 = 0; c0 < strlen(b); c0++)   {
        for(c1 = 0; c1 < c0; c1++)
            if( tb[c1] == b[c0] )    break;
        if( c0 == c1 ) tb[tslen++] = b[c0];
    }
    // tb[tslen] = 0;
    
    tslen = strlen(ta) - strlen(tb);
    if( tslen == 0 )
        return strcmp(a, b);
    else
        return tslen;
}

int sort_by_length(const char* a, const char* b) {
    int i = strlen(a) - strlen(b);
    // b daha uzunsa pozitif doner o zaman degistir. 
    if( i == 0 ) 
        return strcmp(a, b);
    else
        return i;
}

void string_sort(char** arr,const int len,int (*cmp_func)(const char* a, const char* b))    {
    int i, j, swapped;
    char* t;

    for(i = 0; i < len; i++)	{
        swapped = 0;
        for(j = i + 1; j < len; j++)	{
            //printf("i = %d, j = %d, cf = %d, arg1 = %s, arg2 = %s\n",
            //    i, j, cmp_func( arr[i], arr[j]), arr[i], arr[j]);

            if( cmp_func( arr[i], arr[j] ) > 0 )	{
                t = arr[i]; arr[i] = arr[j]; arr[j] = t;
                swapped = 1;
            }
        }
        if( swapped = 0 ) break;
    }
}

int main() 	{
    int n;
    scanf("%d", &n);
  
    char** arr;
	arr = (char**)malloc(n * sizeof(char*));
  
    for(int i = 0; i < n; i++){
        *(arr + i) = malloc(1024 * sizeof(char));
        scanf("%s", *(arr + i));
        *(arr + i) = realloc(*(arr + i), strlen(*(arr + i)) + 1);
    }
  
    string_sort(arr, n, lexicographic_sort);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);
    printf("\n");

    string_sort(arr, n, lexicographic_sort_reverse);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");

    string_sort(arr, n, sort_by_length);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]);    
    printf("\n");

    string_sort(arr, n, sort_by_number_of_distinct_characters);
    for(int i = 0; i < n; i++)
        printf("%s\n", arr[i]); 
    printf("\n");
}
