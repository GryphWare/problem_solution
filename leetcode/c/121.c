#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(){

    int days;
    if(scanf("%d", &days) != 1 || days <= 0){
        fprintf(stderr, "size la so lon hon 0");
        return 1;
    }

    int *prices = malloc (days * sizeof(int));
    if(!prices){
        perror("malloc failed");
        free(prices);
        return 1;
    }

    for(int i = 0; i < days; i++){
        if(scanf("%d", &prices[i]) != 1){
            fprintf(stderr, "loi khi nhap %d\n", i + 1);
            free(prices);
            return 1;
        }
    }

    int min = INT_MAX;
    int max_profit = 0;

    for(int i = 0; i < days; i++){
        if(prices[i] < min){
            min = prices[i];
        } else if(prices[i] - min > max_profit){
            max_profit = prices[i] - min;
        }
    }

    printf("%d", max_profit);
    
    return 0;
}
