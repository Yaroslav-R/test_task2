/**
 * functions.c -- вспомогательные функции
 *
 * Copyright (c) 2022, Yaroslav 'YarSlv3' Reikenen <reikenen1234@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "common.h"

#define ERROR 1
#define SUCCSES 0

/**
 * Преобразует пару чисел в строке в два целых неотрицательных числа
 */
int parse_convert(char *str, int* out) {
    // printf("parse called with s =%s*\n", str);
    out[0] = out[1] = 0;
    int cnt = 0;
    int i = 0;
    int len = strlen(str);

    for (i = 1; i < len; i++) {
        cnt += (str[i - 1] == ' ' && str[i] >= '0' && str[i] <= '9');
    }
    if (cnt != 1) {
        // fprintf(stderr, "bad cnt\n");
        return ERROR;
    }

    for (i = 0; str[i] != ' '; i++) {
        if (str[i] < '0' || str[i] > '9') 
            return ERROR;
        out[0] = out[0] * 10 + str[i] - '0';
        if (out[0] > MAXLINE) 
            return ERROR;
    }

    i++;

    for (; i < len; i++) {
        if (str[i] < '0' || str[i] > '9') return ERROR;
        out[1] = out[1] * 10 + str[i] - '0';
        if (out[1] > MAXLINE) 
            return ERROR;
    }
    
    return SUCCSES;

    
}