#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <string.h>


/* using namespace testing; */
extern "C" {
#include "../app/common.h"
#include "../app/text.h"
}

TEST(test_save, suite1) {
    text txt = create_text();
    char path_for_load[] = "./tests/test_input1.txt";
    char path_for_save[] = "./tests/test_output1.txt";
    load(txt, path_for_load);
    save(txt, path_for_save);
    
    FILE *in  = fopen(path_for_load,  "r");
    FILE *out = fopen(path_for_save, "r");
    if (in == NULL) {
        // printf("problem with in file\n");
        FAIL();
    }
    if (out == NULL) {
        // printf("problem with out file\n");
        FAIL();
    }
    int cnt = 0;
    char ch1, ch2;
    while (!feof(in) && !feof(out)) {
        ch1 = fgetc(in);
        ch2 = fgetc(out);
        cnt++;
        if (ch1 != ch2) {
            // printf("cnt = %d\n", cnt);
            fclose(in); fclose(out);
            FAIL();
        }

    }
    // printf("%d good ch\n", cnt);

    fclose(in);
    fclose(out);
    
    SUCCEED();
}

TEST(test_save, suiteOnEmptyFile) {
    text txt = create_text();
    char path_for_load[] = "./tests/test_input2.txt";
    char path_for_save[] = "./tests/test_output2.txt";
    load(txt, path_for_load);
    save(txt, path_for_save);
    
    FILE *in  = fopen(path_for_load,  "r");
    FILE *out = fopen(path_for_save, "r");
    if (in == NULL) {
        // printf("problem with in file\n");
        FAIL();
    }
    if (out == NULL) {
        // printf("problem with out file\n");
        FAIL();
    }
    int cnt = 0;
    char ch1, ch2;
    while (!feof(in) && !feof(out)) {
        ch1 = fgetc(in);
        ch2 = fgetc(out);
        cnt++;
        if (ch1 != ch2) {
            // printf("cnt = %d\n", cnt);
            fclose(in); fclose(out);
            FAIL();
        }

    }
    // printf("%d good ch\n", cnt);

    fclose(in);
    fclose(out);
    
    SUCCEED();
}