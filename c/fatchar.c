#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "fatchar.h"
#include "result.h"


fat_char* make_fat_char(fat_char* fc, int length, char* str) {
    if (fc == NULL) {
        printf("Received NULL fat_char\n");
        fflush(stdout);
        return NULL;
    }
    fc->len = length;
    fc->str = str;
    return fc;
}

unsigned int len(fat_char* fc){
    if (fc == NULL) {
        return 0;
    }

    return fc -> len;
}

fat_char_result char_at(fat_char* fc, int idx) {
    if(fc == NULL || idx < 0 || idx >= fc -> len) {
        fat_char_result fcr;
        fcr.result = FAILURE;
        fcr.character = 'a';
        return fcr;
    }

    fat_char_result fcr;
    char* str = fc -> str;
    str = str + idx;
    fcr.result = SUCCESS;
    fcr.character = *str;
    return fcr;
}

bool fat_chars_equal(fat_char* fc1, fat_char* fc2) {
    if (fc1 == NULL || fc2 == NULL) {
        return false;
    }

    if (fc1->len != fc2->len) {
        return false;
    }

    for (int i = 0; i < fc1->len; i++) {
        if (fc1->str[i] != fc2->str[i]) {
            return false;
        }
    }

    return true;
}

Result delete_fat_char(fat_char* fc) {
    if (fc == NULL) {
        return FAILURE;
    }

    free(fc->str);
    fc->str = NULL;
    free(fc);
    fc = NULL;
    return SUCCESS;
}
