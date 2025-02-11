#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int *index_map(char *pattern)
{
    int pattern_length = strlen(pattern);
    int *index = (int *) malloc(sizeof(int) * pattern_length);
    
    
    int match = 0;
    index[0] = match;
    int flag; // compared index from the front
    int i = 1; // current index from the back
    while(i < pattern_length)
    {
        flag = index[i-1];
        // this while loop is the most important and difficult in the algorithm
        while((pattern[flag] != pattern[i]) && (flag != 0))
        {
            flag = index[flag - 1];
        }
        
        if(pattern[flag] == pattern[i]){
            match = flag + 1;
        }
        else match = 0;

        index[i] = match;
        i++;
    }
    /*
    for(int i=0; i<pattern_length; i++)
    {
        printf("%d ", *(index+i));
    }
    */
    return index;
}


void KMP(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);
    int compare_num = 0;


    //==================== solution 1 : O(n) = n^2 ======================
    /*
    for(int i=0; i<text_length; i++)
    {
        int j = 0;
        for(j=0; j<pattern_length; j++)
        {
            compare_num++;
            if(i+j >= text_length) return;
            if(pattern[j] == text[i+j]) continue;
            else break; 
        }

        if(j == pattern_length){
            printf("find pattern %s in test %d position\n", pattern, i);
        }
    }
    printf("comparison iteration = %d\n", compare_num);
    */
    
    //==================== solution 2 : KMP search ======================
    ///*
    int *index = (int *) malloc(sizeof(int) * pattern_length); 
    index = index_map(pattern);
    
    int i = 0;
    int j = 0;
    while(i < text_length){
        while(j < pattern_length){
            compare_num++;
            if(pattern[j] == text[i]){
                if(j == pattern_length - 1){
                    printf("find pattern %s in test %d position\n", pattern, i - pattern_length + 1);
                    i = i + 1;
                    j = 0;
                    break;
                }
                else{
                    i++;
                    j++;
                }
            }
            else{
                if(j == 0){
                    i++;
                }
                else{
                    j = index[j];
                }
            }            
        }
    }

    printf("comparison iteration = %d\n", compare_num);

    free(index);
    return;
    //*/
}

int main(){
    char text[1000], pattern[1000];

    printf("Enter the text : ");
    scanf("%s", text);
    printf("Enter the pattern : ");
    scanf("%s", pattern);

    KMP(text, pattern);


    return 0;
}