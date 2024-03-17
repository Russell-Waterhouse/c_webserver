#include <stdlib.h>
#include <stdio.h>
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

