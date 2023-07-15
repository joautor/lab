#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n)
{
    return *(*(*(document + n) + m) + k);
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m)
{
    return *(*(document + m) + k);
}

char*** kth_paragraph(char**** document, int k)
{
    return *(document + k);
}

char**** get_document(char* text)
{
    char* c = text;
    int wordCount = 0, senCount = 0, paraCount = 0;

    char**** document = (char****)malloc(sizeof(char***));

    *(document) = (char***)malloc(sizeof(char**));
    *(*(document)) = (char**)malloc(sizeof(char*));
    *(*(*(document))) = (char*)malloc(sizeof(char) * 100);

    while (*c != '\0')
    {
        if (*c == ' ' || *c == '.')
        {
            if (*(c + 1) != '\n')
            {
                ++wordCount;

                if (*c == '.')
                {
                    ++senCount;

                    *(document + paraCount) = (char***)realloc(*(document + paraCount), sizeof(char**) * (senCount + 1));

                    *(*(document + paraCount) + senCount) = (char**)malloc(sizeof(char*));
                    wordCount = 0;
                }

                *(*(document + paraCount) + senCount) = (char**)realloc(*(*(document + paraCount) + senCount), sizeof(char*) * (wordCount + 1));
                *(*(*(document + paraCount) + senCount) + wordCount) = (char*) malloc(sizeof(char) * 100);
            }
        }
        else if(*c == '\n')
        {
            ++paraCount;
            document = (char****)realloc(document, sizeof(char***) * (paraCount + 1));
            *(document + paraCount) = (char***)malloc(sizeof(char**));
            senCount = 0;
            wordCount = 0;
            *(document + paraCount) = (char***)realloc(*(document + paraCount), sizeof(char**) * (senCount + 1));
            *(*(document + paraCount) + senCount) = (char**)malloc(sizeof(char*));
            *(*(document + paraCount) + senCount) = (char**)realloc(*(*(document + paraCount) + senCount), sizeof(char*) * (wordCount + 1));
            *(*(*(document + paraCount) + senCount) + wordCount) = (char*) malloc(sizeof(char) * 100);
        }
        else
        {
            char str[2] = {*c,'\0'};
            strcat(*(*(*(document + paraCount) + senCount) + wordCount), str);
        }
        ++c;
    }
    return document;
}

int main()
{
    char* text = "Hello World.This is sparta.\nOllla patola.\n";
    char**** document = get_document(text);
    printf("%s\n", kth_word_in_mth_sentence_of_nth_paragraph(document, 0, 0, 0));
    printf("%s\n", kth_word_in_mth_sentence_of_nth_paragraph(document, 1, 1, 0));
    printf("%s\n", kth_word_in_mth_sentence_of_nth_paragraph(document, 1, 0, 1));
    printf("%s\n", kth_word_in_mth_sentence_of_nth_paragraph(document, 2, 1, 0));


    return 0;
}
