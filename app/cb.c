/**
 * cb.c - функция перемещения текущей строки в начало
 * 
 * Copyright (c) 2022, Yaroslav 'YarSlv3' Reikenen <reikenen1234@gmail.com>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <string.h>
#include "common.h"
#include "text.h"
#include "_text.h"

/**
 * для вывода каждого последнего непробельного символа строки 
 * в прямом порядке следования строк
 */
void cb(text txt)
{
    if (txt == NULL || txt->length == 0) {
        fprintf(stderr, "There are already no any lines in the text!\n");
        return;
    }
    
    if (txt -> cursor -> line == NULL) return;

    if (txt -> cursor -> line == txt -> begin) return;
    
    node *cur = txt -> begin;

    while (cur != NULL) {
        if (txt -> cursor -> line == cur) {
            cur -> previous -> next = cur -> next;

            if (cur -> next != NULL) {
                cur -> next -> previous = cur -> previous;
            }
            
            cur -> next = txt -> begin;
            txt -> begin = cur;
            return;
        }

        cur = cur -> next;
    }

    return;
}
