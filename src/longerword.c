#include <stdio.h>
#include <string.h>


void findLongestWords(char *phrase, char *result) {
    result[0] = '\0';
    int maxLength = 0;

    char *word = strtok(phrase, " ,;:-");
    while (word != NULL) {
        int len = strlen(word);
        if (len > maxLength) {
            maxLength = len;
            strcpy(result, word);
        } else if (len == maxLength) {
            strcat(result, " ");
            strcat(result, word);
        }
        word = strtok(NULL, " ,;:-");
    }
}

int main() {
    char str[1024];
    char longestWords[1024] = "";

    printf("Введите текст: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    char *phrase_save;
    char *phrase = strtok_r(str, ".!?", &phrase_save);

    while (phrase != NULL) {
        while (*phrase == ' ') phrase++;

        char buffer[256];
        findLongestWords(phrase, buffer);

        if (strlen(buffer) > 0) {
            if (strlen(longestWords) > 0) strcat(longestWords, " ");
            strcat(longestWords, buffer);
        }

        phrase = strtok_r(NULL, ".!?", &phrase_save);
    }

    printf("Самые длинные слова: %s\n", longestWords);
    return 0;
}