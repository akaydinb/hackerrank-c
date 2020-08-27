#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n-1][m-1][k-1];
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m-1][k-1];
}

char*** kth_paragraph(char**** document, int k) {
    return document[k-1];
}

char**** get_document(char* text) {
    int npara = 0, nsent = 0, nword = 0;
    char *save1, *save2, *save3;
    char *pch1, *pch2, *pch3, ****document;

    pch1 = strtok_r(text, "\n", &save1);
    while(pch1 != NULL)	{
        if(npara == 0)
            document = (char ****)malloc(sizeof(char ***));
        else
            document = realloc(document, (npara + 1) * sizeof(char ***));


        pch2 = strtok_r(pch1, ".", &save2);
        while(pch2 != NULL)	{
            if(nsent == 0)
                document[npara] = (char ***)malloc(sizeof(char **));
            else
                document[npara] = realloc(document[npara], (nsent + 1) * sizeof(char **));

            pch3 = strtok_r(pch2, " ", &save3);
            while(pch3 != NULL)    {
                if(nword == 0)
                    document[npara][nsent] = (char **)malloc(sizeof(char *));
                else
                    document[npara][nsent] = realloc(document[npara][nsent], (nword + 1) * sizeof(char *));

                document[npara][nsent][nword] = (char *)malloc((strlen(pch3) + 1) * sizeof(char));
                strcpy(document[npara][nsent][nword], pch3);
                //printf("para = %d, sent = %d, word = %d, -%s-\n", npara, nsent, nword, pch3);

                nword++;
                pch3 = strtok_r(NULL, " ", &save3);
            }

            nword = 0; nsent++;
            pch2 = strtok_r(NULL, ".", &save2);

        }

        nsent = 0; npara++;
        pch1 = strtok_r(NULL, "\n", &save1);

    }
    
    return document;
}


char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main()    {
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}
