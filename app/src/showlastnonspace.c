/**
 * save.c - функция сохранения текста в файл
 * 
 * Copyright (c) 2022, Yaroslav 'YarSlv3' Reikenen <reikenen1234@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text/text.h"

/**
 * выводит последний непустой символ строки
 */
void print_last_nonspace(int index, char *line, int cursor, void *data) {
    
    UNUSED(index);
    UNUSED(cursor);
    UNUSED(data);
    
    size_t i;
    size_t line_size = strlen(line);
    char last = ' ';

    for (i = 0; i < line_size; i++) {
        if (line[i] != ' ' && line[i] != '\n') 
            last = line[i];
    }

    printf("%c", last);

    return;
}

/**
 * для вывода каждого последнего непробельного символа строки 
 * в прямом порядке следования строк
 */
void showlastnonspace(text txt)
{

    process_forward(txt, print_last_nonspace, NULL);

    printf("\n");

    return;
}