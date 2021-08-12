#include"s21_string.h"

char *s21_strcpy(char *str1, const char *str2) {
    while (*str2 != '\0') {
        *str1 = *str2;
        str1++;
        str2++;
    }
    return str1;
}

int s21_strlen(const char *str) {
    int len = 0;
    while (*(str + len) != 0)
        len++;
    return len;
}

int s21_strcmp(const char *str1, const char *str2) {
    while (*str1 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}
