#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#define char_size 10

char buffer[char_size];

//end
void endOfProgram(){
    snprintf(buffer, sizeof(buffer), "End here");
    fprintf(stdout, "\n%s\n", buffer);
}

int main(){
    //sign up for exit function
    atexit(endOfProgram);
    clock_t start, finish;
    double elapsed_time;

    start = clock();

    //code here
    int8_t size;
    scanf("%hhd", &size);

    int arr[size];
    
    for(int8_t i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }

    int closest = arr[0];

    for(int8_t i = 1; i < size; i++){
        if(abs(closest) > abs(arr[i])){
            closest = arr[i];
        } else if(abs(closest) == abs(arr[i]) && closest < arr[i]){
            closest = arr[i];
        }
    }

    printf("%d ", closest);
    
    finish = clock();
    elapsed_time = (double)(finish - start) / CLOCKS_PER_SEC;
    printf("\ntotal: %.6fs ", elapsed_time);
    return EXIT_SUCCESS;
}
