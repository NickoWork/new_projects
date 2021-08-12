#include<stdio.h>
#include<stdlib.h>
#include"s21_string.h"

void s21_strcpy_test(const int result, const int expected) {
    if  (expected == result)
        printf("\e[0;32mSUCCESS\n\n");
    else
        printf("\e[0;31mFAIL\n\n");
    printf("\e[0m");
}

void output_strcpy(int result, int expected, const char *len1, const char *len2) {
    printf("%s\n", len1);
    printf("%s\n", len2);
    printf("expected >> %d\nresult >> %d\n", expected, result);
    s21_strcpy_test(result, expected);
}

void s21_strcmp_test(const int result, const int expected) {
    if  (expected == result)
        printf("\e[0;32mSUCCESS\n\n");
    else
        printf("\e[0;31mFAIL\n\n");
    printf("\e[0m");
}

void output_strcmp(int result, int expected, char *len1, char *len2) {
    printf("%s\n", len1);
    printf("%s\n", len2);
    printf("expected >> %d\nresult >> %d\n", expected, result);
    s21_strcmp_test(result, expected);
}

void s21_strlen_test(const int result, const int expected) {
    if  (expected == result)
        printf("\e[0;32mSUCCESS\n\n");
    else
        printf("\e[0;31mFAIL\n\n");
    printf("\e[0m");
}

void output_strlen(int result, int expected, char *len) {
    printf("%s\n", len);
    printf("expected >> %d\nresult >> %d\n", expected, result);
    s21_strlen_test(result, expected);
}


int main() {
    int result, expected;
    char *len1 = "Hello";
    char *len2 = "Good";
    char *len3 = "Hi";
    char *len4 = "PC";
    char *len5 = "root";
    char *len6 = "Hi";

    printf("\n\n[[ s21_strlen_test ]]\n\n");
    result = s21_strlen(len1);
    expected = 5;
    output_strlen(result, expected, len1);
    result = s21_strlen(len2);
    expected = 4;
    output_strlen(result, expected, len2);
    result = s21_strlen(len3);
    expected = 2;
    output_strlen(result, expected, len3);
    printf("\n[[ s21_strcmp_test ]]\n\n");
    result = s21_strcmp(len1, len4);
    expected = -8;  // -8
    output_strcmp(result, expected, len1, len4);
    result = s21_strcmp(len2, len5);
    expected = -43;  // -43
    output_strcmp(result, expected, len2, len5);
    result = s21_strcmp(len3, len6);
    expected = 0;  // 0
    output_strcmp(result, expected, len3, len6);
    printf("\n[[ s21_strcpy_test ]]\n\n");
    char *len;
    len = malloc(sizeof(len1));
    s21_strcpy(len, len1);
    result = s21_strcmp(len, len1);
    expected = 0;
    output_strcpy(result, expected, len, len1);
    len = NULL;
    len = malloc(sizeof(len2));
    s21_strcpy(len, len2);
    result = s21_strcmp(len, len2);
    expected = 0;
    output_strcpy(result, expected, len, len2);
    len = malloc(sizeof(len3));
    s21_strcpy(len, len3);
    result = s21_strcmp(len, len3);
    expected = 0;
    output_strcpy(result, expected, len, len3);
}
