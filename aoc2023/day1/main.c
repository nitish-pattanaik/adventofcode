#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    FILE *ptr = fopen("input.txt", "r");
    char ch;

    if(ptr == NULL){
        puts("File can't be open!!\n");
        return 1;
    }

    puts("Content of file:\n");

    int ctr = 0;
    /* while((ch = fgetc(ptr)) != EOF){ */
    /*     printf("%c", ch); */
    /*     ctr++; */
    /* } */
    /* printf("%d", ctr); */
    /* while(feof(ptr) == 0){         //feof(ptr) == 0 same as, !(feof(ptr)) */
    /*     ch = fgetc(ptr); */
    /*     printf("%c", ch); */
    /* } */

    /* char *fgets(char *s, int size, FILE *stream); */
    /* get one string at a time from the file */
    char str[100];

    char ch1, ch2;
    int ch3,ch4;
    int rel =0;
    while(fgets(str, sizeof(str), ptr) != NULL){   //fgets() returns null when EOF reads
        printf("%s", str);
        for(int i=0; i < strlen(str); ++i){
            if(str[i] >= 48 && str[i] <= 57){
                ch1 = str[i];
                ch3 = (int) ch1 - 48;
                break;
            }
        }
        for(int j=strlen(str)-1; j >= 0; --j){
            if(str[j] >= 48 && str[j] <= 57){
                ch2 = str[j];
                ch4 = (int) ch2 - 48;
                break;
            }
        }
         rel += ch3 * 10 + ch4;

        printf("chars:%c, %c = (dec)%d, %d = (result)%d\n", ch1, ch2, ch3, ch4, rel);
    }


    fclose(ptr);
    return 0;
}
