#include<stdio.h>
#include<string.h>

char buf_1[1024], buf_2[1024], buf_3[1024];
char *save_ptr1, *save_ptr2, *save_ptr3;
char *token1, *token2, *token3;

int main()	{
    // Populate buf_1, buf_2, and buf_3

    // get the initial tokens
    token1 = strtok_r(buf_1, " ", &save_ptr1);
    token2 = strtok_r(buf_2, " ", &save_ptr2);
    token3 = strtok_r(buf_3, " ", &save_ptr3);

    while(token1 && token2 && token3) {
       // do stuff with tokens

       // get next tokens
       token1 = strtok_r(NULL, " ", &save_ptr1);
       token2 = strtok_r(NULL, " ", &save_ptr2);
       token3 = strtok_r(NULL, " ", &save_ptr3);
    }

    return 0;
}

