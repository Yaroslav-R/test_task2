/**
 * editor.c -- строковый текстовый редактор
 * 
 * Copyright (c) 2017, Alexander Borodin <aborod@petrsu.ru>
 *
 * This code is licensed under a MIT-style license.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "text.h"
#include "common.h"

#define MAXLINE 255

int main()
{
    char cmdline[MAXLINE + 1];
    char *cmd;
    char *arg;
   
    /* Создаем объект для представления текста */
    text txt = create_text();

    /* Цикл обработки команд */
    while (1) {
        printf("ed > ");
        
        /* Получаем команду */
        fgets(cmdline, MAXLINE, stdin);

        /* Извлекаем имя команды */
        if ((cmd = strtok(cmdline, " \n")) == NULL) {
            continue;
        }

        /* Распознаем поддерживаемую команду */
        
        /* Завершаем работу редактора */
        if (strcmp(cmd, "quit") == 0) {
            fprintf(stderr, "Bye!\n");
            break;
        }

        if (strcmp(cmd, "showlastnonspace") == 0) {
            showlastnonspace(txt);
            continue;
        }

        /* Загружаем содержимое файла, заданного параметром */
        if (strcmp(cmd, "load") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: load filename\n");
            } else {
                load(txt, arg);
            }
            continue;
        }

        if (strcmp(cmd, "save") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: save filename\n");
            } else {
                save(txt, arg);
            }
            continue;
        }

        /* Выводим текст */
        if (strcmp(cmd, "show") == 0) {
            show(txt);
            continue;
        }
        
        if (strcmp(cmd, "cb") == 0) {
            cb(txt);
            continue;
        }

        if (strcmp(cmd, "m") == 0) {
            if ((arg = strtok(NULL, "\n")) == NULL) {
                fprintf(stderr, "1Usage: m line index\n");
                continue;
            }

            int a[2];

            if (parse_convert(arg, a)) {
                fprintf(stderr, "1Usage: m line index\n");
                continue;
            }
            
            if (move(txt, a[0], a[1])) {
                fprintf(stderr, "1Usage: m line index\n");
                continue;
            } 
            
            continue;
        }

    // для вставки строки от курсора i строка с контролем переполнения;
        if (strcmp(cmd, "is") == 0) {
            if ((arg = strtok(NULL, " \n")) == NULL) {
                fprintf(stderr, "Usage: is string\n");
            } else {
                if (input_string(txt, arg)) {
                    fprintf(stderr, "so big\n");
                }
            }

            continue;
        }

        /* Если команда не известна */
        fprintf(stderr, "Unknown command: %s\n", cmd);
    }

    return 0;
}
