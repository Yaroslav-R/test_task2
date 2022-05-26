/**
 * save.c - функция сохранения текста в файл
 * 
 * Copyright (c) 2022, Yaroslav 'YarSlv3' Reikenen <reikenen1234@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "text.h"

/**
 * Записывает строку в конец файла
 */
void input_line(int index, char *line, int cursor, void *data) {
    UNUSED(index);

    if (cursor == -1) 
        return;
    
    char **tmp = (char**)data;
    char *str = (char*)tmp[1];
    char *code = (char*)tmp[0];

    size_t cur_size = strlen(line);
    size_t str_size = strlen(str);
    size_t next_size = cur_size + str_size;

    if (next_size >= MAXLINE) {
        *code = 1;
        return;
    }
    
    char buff[MAXLINE] = "";
    
    size_t i;
    size_t j;

    for (i = 0; i < (size_t)cursor; i++) 
        buff[i] = line[i];

    for (j = 0; j < str_size; i++, j++) {
        buff[i] = str[j];
    }

    for (j = cursor; j < cur_size; i++, j++) {
        buff[i] = line[j];
    }

    for (i = 0; i < next_size; i++) {
        line[i] = buff[i];
    }

    
    
    return;
}

/**
 * Сохраняет содержимое в указанный файл
 */
int input_string(text txt, char *str)
{
    char *code = (char*)malloc(sizeof(char));
    *code = 0;
    char *data[2] = {code, str};

    process_forward(txt, input_line, (void*)data);
    // printf("%d\n", (int)(*(data[0])));
    if ((int)(*(data[1]))) {
        fprintf(stderr, "so big\n");
    }
    return (int)(*(data[1]));
}
