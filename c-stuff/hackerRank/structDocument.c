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

typedef struct word word;
typedef struct sentence sentence;
typedef struct paragraph paragraph;
typedef struct document document;

typedef enum Type {DOC_TYPE = 0, PARA_TYPE, SEN_TYPE, WORD_TYPE} Type;

void* createNewObj(Type t, size_t size)
{
    void* objPtr = malloc(size);
    if (objPtr == NULL)
    {
        fprintf(stderr, "Error: Unable to allocate memory");
        exit(1);
    }
    switch(t)
    {
        case DOC_TYPE:
            ((document*)objPtr)->data = NULL;
            ((document*)objPtr)->paragraph_count = 0;
            break;
        case PARA_TYPE:
            ((paragraph*)objPtr)->data = NULL;
            ((paragraph*)objPtr)->sentence_count = 0;
            break;
        case SEN_TYPE:
            ((sentence*)objPtr)->data = NULL;
            ((sentence*)objPtr)->word_count = 0;
            break;
        case WORD_TYPE:
            ((word*)objPtr)->data = NULL;
            break;
        default:
            fprintf(stderr, "Error: Unknown type!\n");
            exit(1);
    }
    return objPtr;
}

void addChar(word* w, char c)
{
    size_t length = (w->data == NULL) ? 0 : strlen((const char*)(w->data));
    w->data = (char*)realloc(w->data, sizeof(char) * (length + 2));
    w->data[length] = c;
    w->data[length + 1] = '\0';
}

void addWord(sentence* s, word* w)
{
   s->data = (word*)realloc(s->data, sizeof(word) * (s->word_count + 1));
   s->data[s->word_count] = *w;
   ++(s->word_count);
   //reset word
   //free(w->data);
   w->data = NULL;
}

void addSentence(paragraph* p, sentence* s)
{
    p->data = (sentence*)realloc(p->data, sizeof(sentence) * (p->sentence_count + 1));
    p->data[p->sentence_count] = *s;
    ++(p->sentence_count);
    //reset sentence
    s->data = NULL;
    s->word_count = 0;
}

void addParagraph(document* d, paragraph* p)
{
    d->data = (paragraph*)realloc(d->data, sizeof(paragraph) * (d->paragraph_count + 1));
    d->data[d->paragraph_count] = *p;
    ++(d->paragraph_count);
    //reset paragraph
    p->data = NULL;
    p->sentence_count = 0;
}

struct document get_document(char* text) 
{
    document* docPtr = (document*)createNewObj(DOC_TYPE, sizeof(document));
    paragraph* paraPtr = (paragraph*)createNewObj(PARA_TYPE, sizeof(paragraph));
    sentence* senPtr = (sentence*)createNewObj(SEN_TYPE, sizeof(sentence));
    word* wordPtr = (word*)createNewObj(WORD_TYPE, sizeof(word));

    char* c = text;
    while (*c != '\0')
    {
        switch(*c)
        {
            case ' ':
                addWord(senPtr, wordPtr);
                break;
            case '.':
                if (wordPtr->data != NULL)
                {
                    addWord(senPtr, wordPtr);
                }
                addSentence(paraPtr, senPtr);
                break;
            case '\n':
                addParagraph(docPtr, paraPtr);
                break;
            default:
                addChar(wordPtr, *c);
        }
        ++c;
    }
    //add last paragraph to doc
    if (paraPtr->data != NULL)
    {
        addParagraph(docPtr, paraPtr);
    }

    document newdoc = *docPtr;

    free(wordPtr);
    free(senPtr);
    free(paraPtr);
    free(docPtr);

    return newdoc;
    //return *docPtr;
}

struct word kth_word_in_mth_sentence_of_nth_paragraph(struct document Doc, int k, int m, int n)
{
    return Doc.data[n-1].data[m-1].data[k-1];
}

struct sentence kth_sentence_in_mth_paragraph(struct document Doc, int k, int m)
{ 
    return Doc.data[m-1].data[k-1];
}

struct paragraph kth_paragraph(struct document Doc, int k)
{
    return Doc.data[k-1];
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