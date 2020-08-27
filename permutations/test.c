#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*void strrev(char *s)	{
  int i; 
  // 2 3 4 
  for(i = 0; i < num / 2; i++)  {  // num = 3
    t = arr[i];     // i = 0,
    arr[i] = arr[num - i - 1];
    arr[num - i - 1] = t;
}
*/
  

int main()	{
    int i, k, l, n, nt;
    char t;
    char s[] = "122";

    n = strlen(s);
    
    printf("%s\n", s);
    
    while(1)	{
      k = -1;
      for(i = 0; i < n; i++)
        if( s[i] < s[i+1] )   k = i;
    
      if(k == -1)	{
        //printf("son perm.\n");
        return 1;
      }
      
      for(i = k; i < n; i++)
        if( s[k] < s[i] )     l = i;
     
      // swap
      t = s[k]; s[k] = s[l]; s[l] = t;

      //printf("n = %d , k = %d , l = %d\n", n, k, l);
      
      // reverse
      if(k < n - 2)	{
	for(i = k + 1; i < (n + k + 1) / 2; i++)	{
	  t = s[i]; 
	  s[i] = s[n + k - i];
	  s[n + k - i] = t;
	  //printf("%d - %d\n", i, n + k - i);  
	}
      }
       
      printf("%s\n", s);
      //getchar();

    }
    
    return 0;
}

