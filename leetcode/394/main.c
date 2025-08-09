#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char* resize_and_append(char* dest, int* current_size, int* current_len, const char* src, int src_len) {
    while (*current_len + src_len + 1 > *current_size) {
        *current_size *= 2;
        dest = (char*)realloc(dest, *current_size);
        if (dest == NULL) {
            exit(1);
        }
    }
    strncat(dest, src, src_len);
    *current_len += src_len;
    return dest;
}

char* decodeStringHelper(char* s, int* index) {
    int current_size = 100;
    int current_len = 0;
    char* result = (char*)malloc(current_size);
    if (result == NULL) exit(1);
    result[0] = '\0';

    while (s[*index] != '\0' && s[*index] != ']') {
        if (isdigit(s[*index])) {
            int num = 0;
            while (isdigit(s[*index])) {
                num = num * 10 + (s[*index] - '0');
                (*index)++;
            }
            
            (*index)++;
            
            char* decoded_substring = decodeStringHelper(s, index);
            
            (*index)++;
            
            for (int i = 0; i < num; i++) {
                result = resize_and_append(result, &current_size, &current_len, decoded_substring, strlen(decoded_substring));
            }
            free(decoded_substring);
        } else {
            char letter[2] = {s[*index], '\0'};
            result = resize_and_append(result, &current_size, &current_len, letter, 1);
            (*index)++;
        }
    }

    return result;
}

char* decodeString(char* s) {
    int index = 0;
    return decodeStringHelper(s, &index);
}