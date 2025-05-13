#include <stdio.h>

int main(){

    char *str[] = {"Flowers", "Fly", "Flew"};
    size_t size = sizeof(str) / sizeof(str[0]);

    int limit;
    for(limit = 0; ;limit++){
        char first = str[0][limit];
        if(first == '\0') break;
        for(size_t i = 0; i < size; i++){
            if(first != str[i][limit] || str[i][limit] == '\0'){
                goto end;
            }
        }
    }

 end:
    for(int i = 0; i < limit; i++){
        printf("%c", str[0][i]);
    }
    
    return 0;
}
