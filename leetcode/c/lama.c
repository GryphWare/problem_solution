#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct lama_Value {
    char key;
    int value;
};

struct lama_Value lama[7] = {
    {'I', 1}, {'V', 5}, {'X', 10},
    {'L', 50}, {'C', 100}, {'D', 500},
    {'M', 1000}
};

int convert(char *user) {
    int current, result, prev;
    result = prev = 0;

    for (int i = strlen(user) - 1; i >= 0; i--) {
        current = 0;
        for (int j = 0; j < 7; j++) {
            if (user[i] == lama[j].key) {
                current = lama[j].value;
                break;
            }
        }

        if (current < prev) {
            result -= current;
        } else {
            result += current;
        }
        prev = current;
    }
    return result;
}

int main(void) {
    char *user = NULL;
    size_t len = 0;
    ssize_t read = getline(&user, &len, stdin);

    if (read == -1) {
        perror("what happen?");
        free(user);
        exit(EXIT_FAILURE);
    }

    user[strcspn(user, "\n")] = 0;
    int total = convert(user);
    printf("%d\n", total);

    free(user);
    return EXIT_SUCCESS;
}
