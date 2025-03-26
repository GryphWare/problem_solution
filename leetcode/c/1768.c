#include <stdio.h>
#include <string.h>

int main(){

    char str[20], str2[20];

    //input 2 string
    fgets(str, sizeof(str), stdin);
    fgets(str2, sizeof(str2), stdin);

    //size
    int sizeChar1 = strlen(str);
    int sizeChar2 = strlen(str2);

    //which larger?
    int larger = (sizeChar1 > sizeChar2) ? sizeChar1 : sizeChar2;

    for(int i = 0; i < larger; i++){
        if(i < sizeChar1){
            printf("%c ", str[i]);
        }
        if(i < sizeChar2){
            printf("%c ", str2[i]);
        }
    }
    
    return 0;
}
