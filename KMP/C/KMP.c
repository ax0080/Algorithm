#include <stdio.h>
#include <string.h>
/*
char *index(char *pattern)
{

}
*/

void KMP(char *text, char *pattern)
{
    int text_length = strlen(text);
    int pattern_length = strlen(pattern);


    //==================== solution 1 : O(n) = n^2 ======================
    
    for(int i=0; i<text_length; i++)
    {
        int j = 0;
        for(j=0; j<pattern_length; j++)
        {
            if(i+j >= text_length) return;

            if(pattern[j] == text[i+j]) continue;
            else break; 
        }

        if(j == pattern_length){
            printf("find pattern %s in test %d position\n", pattern, i);
        }
    }
    
    
    //==================== solution 2 : KMP search ======================
    /*
    char *index = malloc(sizeof(char) * pattern_length); 
    

    free()
    */
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