#ifndef FATCHAR_H
#define FATCHAR_H

/*
 * fat_char module
 * example use:
 *
 * char* s = "Hello, World!";
 * fat_char fc = make_fat_char(strlen(s), s);
 * int length = len(&fc);
 * fat_char_result fcr = char_at(&fc, 0)
 * if(fcr.success) {
 *   char c = fcr.character
 *   // Do something with the character
 * }
 */

struct fat_char_result {
    int success;
    char character;
};

typedef struct fat_char_result fat_char_result;
typedef struct fat_char fat_char;

fat_char make_fat_char(int length, char* str);
unsigned int len(fat_char* fc);
fat_char_result char_at(fat_char* fc, int idx);

#endif
