#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>

int main(){

    char *expected = NULL, *example = NULL;
    ssize_t read1, read2;
    size_t len1 = 0, len2 = 0;

    read1 = getline(&expected, &len1, stdin);

    if(read1 == -1){
        perror("Read1 bi loi");
        free(expected);
        exit(1);
    }
    
    read2 = getline(&example, &len2, stdin);

    if(read2 == -1){
        perror("read2 bi loi");
        free(expected);
        free(example);
        exit(EXIT_FAILURE);
    }


    expected[strcspn(expected, "\n")] = 0;
    example[strcspn(example, "\n")] = 0;
    
    size_t i, j;
    j = 0;

    size_t size2, size = strlen(expected);
    size2 = strlen(example);
    
    size_t correct = 0;
    
    for(i = 0; i < size2 && j < size; i++){
        char expected_word = expected[j];
        if(example[i] == expected_word){
            j++;
            correct++;
        }
    }

    printf("%d", (correct == size));
    
    free(example);
    free(expected);
    
    return 0;
}
