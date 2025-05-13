#include <stdio.h>
#include <string.h>

int main(){

    char *str[] = {"Hell", "Hi", "Hello"};
    size_t size = sizeof(str) / sizeof(str[0]);

    /*tim chi so nho nhat de toi uu*/
    size_t min_size = strlen(str[0]);
    
    for(size_t i = 1; i < size; i++){
        if(strlen(str[i]) < min_size){
            min_size = strlen(str[i]);
        }
    }

    size_t j;
    for(j = 0; j < min_size; j++){
        char c = str[0][j];
        size_t i;
        for(i = 1; i < size; i++){
            if(c != str[i][j]){
                break;
            }
        }
        if(i < size){
            break;
        }
    }

    for(size_t k = 0; k < j; k++){
        putchar(str[0][k]);
    }
    
    return 0;
}
