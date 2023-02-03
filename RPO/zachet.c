#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
        FILE *file = fopen("task11.txt", "r");
        char c = ' ';
        int numberOfWords = 1;
        char **words = NULL;
        char given[32000];
        int symbol = 0;
        int maxL = 0;
        int cL = 0;
        while (c != EOF) {
                c = fgetc(file);
                //printf("%c", c);
                if (c == ' ') {
                        numberOfWords++;
                        if (cL > maxL) {
                                maxL = cL;
                        }
                        cL = 0;
                }
                else {
                        cL++;
                }
                given[symbol] = c;
                symbol++;
        }
        given[symbol - 1] = '\0';
        words = (char**)calloc(numberOfWords, sizeof(char*));
        int cW = 0;
        int curL = 0;
        words[cW] = (char*)calloc(maxL, sizeof(char));
        for (int i = 0; i < symbol; ++i) {
                if (given[i] != ' ' && given[i] != '.' && given[i] != ',') {
                        /*if ((int)given[i] < 97) {
                                given[i] = (char)((int)given[i] + 32);
                        }*/
                        words[cW][curL] = given[i];
                        curL++;
                }
                else if(given[i] == ' ') {
                        words[cW][curL] = '\0';
                        curL = 0;
                        cW++;
                        words[cW] = (char*)calloc(maxL, sizeof(char));
                }
        }
        /*printf("Words to be filtered: \n");
        for (int i = 0; i < numberOfWords; ++i) {
                printf("%s ",words[i]);
        }*/
        char *buf = NULL;
        int flag = 0;
        int changedFlag = 0;
        int neededIndex;
        char pastChar;
        char oldWord[maxL];
        for (int i = 0; i < numberOfWords; ++i) {
                for (int j = 0; j < numberOfWords - i - 1; ++j) {
                        if ((int)words[j][0] < (int)('a')) {
                                //pastChar = words[j][0];
                                //strcpy(oldWord,words[j]);
                                //*oldWord = words[j];
                                words[j][0] = (char)((int)words[j][0] + 32);
                                flag = 1;
                        }
                        if (strcmp(words[j], words[j + 1]) > 0) {
                                buf = words[j];
                                words[j] = words[j + 1];
                                words[j + 1] = buf;
                                //if (flag == 1) {
                                //      words[j + 1] = oldWord;
                                //      flag = 0;
                                //}
                                buf = NULL;
                                changedFlag = 0;
                        }
                        /*if (flag == 1) {
                                if (changedFlag == 1) {
                                        neededIndex = j + 1;
                                }
                                else {
                                        neededIndex = j;
                                }
                                //printf("\n%c\n", words[neededIndex][0]);
                                words[neededIndex][0] = (char)((int)words[j][0] - 32);
                                //printf("\n%c\n", words[neededIndex][0]);
                                flag = 0;
                                changedFlag = 0;
                                words[neededIndex][0] = pastChar;
                        }       */
                }
        }
        //printf("\nSorted words: \n");
        for (int i = 0; i < numberOfWords; ++i) {
                printf("%s ", words[i]);
        }
        for (int i = 0; i < numberOfWords; ++i) {
                free(words[i]);
        }
        printf("\n");
        free(words);
        fclose(file);
        return 0;
}
