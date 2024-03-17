#ifndef FATCHAR_H
#define FATCHAR_H

/*
 * fat_char module
 * example use:
 * TODO:
 *
 */
#include "result.h"
#include <stdbool.h>

struct fat_char {
    int len;
    char* str;
};

struct fat_char_result {
    enum Result result;
    char character;
};

typedef struct fat_char_result fat_char_result;
typedef struct fat_char fat_char;

fat_char* make_fat_char(fat_char* fc, int length, char* str);
unsigned int len(fat_char* fc);
fat_char_result char_at(fat_char* fc, int idx);
bool fat_chars_equal(fat_char* fc1, fat_char* fc2);
Result delete_fat_char(fat_char* fc);
#endif
