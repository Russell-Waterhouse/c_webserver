#include <stdlib.h>
#include "fatchar.h"


struct fat_char {
    int len;
    char* str;
};


fat_char make_fat_char(int length, char* str) {
    fat_char fc;
    fc.len = length;
    fc.str = str;
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
        fcr.success = 0;
        fcr.character = 'a';
        return fcr;
    }

    fat_char_result fcr;
    char* str = fc -> str;
    str = str + idx;
    fcr.success = 1;
    fcr.character = *str;
    return fcr;
}

