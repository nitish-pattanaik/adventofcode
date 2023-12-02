#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define one 1
#define two 2
#define three 3
#define four 4
#define five 5
#define six 6
#define seven 7
#define eight 8
#define nine 9

int main ()
{
    FILE *ptr = fopen("demo.txt", "r");
    char ch;
    if(!ptr){
        puts("File can't be open");
        return 0;
    }
    puts("contents of file:");

    char str[100];
    while(fgets(str, sizeof(str), ptr)){
        printf("%s", str);
    }

    fclose(ptr);
    return 0;
}
