#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

struct word {
    char* data;
};

struct sentence {
    struct word* data;
    int word_count;//denotes number of words in a sentence
};

struct paragraph {
    struct sentence* data  ;
    int sentence_count;//denotes number of sentences in a paragraph
};

struct document {
    struct paragraph* data;
    int paragraph_count;//denotes number of paragraphs in a document
};
struct document get_document(char* text) {
	int npara = 0, nsent = 0, nword = 0;
    char *save1, *save2, *save3;
    char *pch1, *pch2, *pch3;
	struct document *document1; 
	
	document1 = (struct document *)malloc(sizeof(struct document));
	
    pch1 = strtok_r(text, "\n", &save1);
    while(pch1 != NULL)	{
        ++npara;
		/* if(npara = 0)	{
			document1->data[0] = (struct paragraph *)malloc(sizeof(struct paragraph));
			document1.paragraph_count = 1;
		}
		else	{
			document1.data[npara] = realloc(document1.data[npara], sizeof(struct paragraph) * (npara + 1));
			document1.paragraph_count = ++npara;
		} */

		pch2 = strtok_r(pch1, ".", &save2);
        while(pch2 != NULL)	{
            ++nsent;
			/* if(nsent == 0)	{
				document1.data[npara].data[0] = (struct sentence *)malloc(sizeof(struct sentence));
				document1.data[npara].sentence_count = 1;
			}
			else	{
				document1.data[npara].data[nsent] = realloc(document1.data[npara].data[nsent], sizeof(struct sentence) * (nsent + 1));
				document1.data[npara].sentence_count = ++nsent;
			} */
		
            pch3 = strtok_r(pch2, " ", &save3);
            while(pch3 != NULL)    {
                ++nword;
				/* if(nword == 0)	{
					document1.data[npara].data[nsent].data[0] = (struct word *)malloc(sizeof(struct word));
					document1.data[npara].data[nsent].word_count = 1;
				}
				else	{
					document1.data[npara].data[nsent].data[nword] = realloc(document1.data[npara].data[nsent].data[nword], sizeof(struct(word)) * (nword + 1));
					document1.data[npara].data[nsent].word_count == ++nword;
				} */

				//document1.data[npara].data[nsent].data[nword].data = (char *)malloc((strlen(pch3) + 1) * sizeof(char));
				//strcpy(document1.data[npara].data[nsent].data[nword].data, pch3);

				printf("para = %d, sent = %d, word = %d, -%s-\n", npara, nsent, nword, pch3);
				//nword++;
				pch3 = strtok_r(NULL, " ", &save3);
			}
			
            nword = 0; //nsent++;
            pch2 = strtok_r(NULL, ".", &save2);
		}
		
        nsent = 0; //npara++;
        pch1 = strtok_r(NULL, "\n", &save1);
	}
	
	return *document1;


}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n) {

}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m) { 

}

struct paragraph kth_paragraph(struct document Doc, int k) {

}


void print_word(struct word w) {
    printf("%s", w.data);
}

void print_sentence(struct sentence sen) {
    for(int i = 0; i < sen.word_count; i++) {
        print_word(sen.data[i]);
        if (i != sen.word_count - 1) {
            printf(" ");
        }
    }
}

void print_paragraph(struct paragraph para) {
    for(int i = 0; i < para.sentence_count; i++){
        print_sentence(para.data[i]);
        printf(".");
    }
}

void print_document(struct document doc) {
    for(int i = 0; i < doc.paragraph_count; i++) {
        print_paragraph(doc.data[i]);
        if (i != doc.paragraph_count - 1)
            printf("\n");
    }
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

int main() 
{
    char* text = get_input_text();
    struct document Doc = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            struct word w = kth_word_in_mth_sentence_of_nth_paragraph(Doc, k, m, n);
            print_word(w);
        }

        else if (type == 2) {
            int k, m;
            scanf("%d %d", &k, &m);
            struct sentence sen= kth_sentence_in_mth_paragraph(Doc, k, m);
            print_sentence(sen);
        }

        else{
            int k;
            scanf("%d", &k);
            struct paragraph para = kth_paragraph(Doc, k);
            print_paragraph(para);
        }
        printf("\n");
    }     
}
