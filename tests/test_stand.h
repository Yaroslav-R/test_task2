#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include <stdio.h>
#include <string>
#include <fstream>

/* using namespace testing; */
extern "C" {
#include "../app/common.h"
#include "../app/text.h"
#include "../app/_text.h"
}

static char path_to_file[] = "./tests/test_input1.txt";

TEST(load, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    std::ifstream f;
    f.open(path_to_file);
    std::string s;
    node *current = txt->begin;
    EXPECT_NE(txt->begin, nullptr);
    EXPECT_NE(txt->end, nullptr);
    size_t len = txt -> length;
    int cnt = 0;
    while (std::getline(f, s))
    {
        cnt++;
        if (cnt != len)
            s += "\n";
        EXPECT_EQ(current->contents, s);
        current = current->next;
    }
}

TEST(move_cursor, sute1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, 3);
    EXPECT_EQ(txt->cursor->position, 3);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute2) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, -3, 0);
    EXPECT_EQ(txt->cursor->position, 17); 
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute3) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 15, 0);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, txt->length - 1);
    remove_all(txt);
}

TEST(move_cursor, sute4) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, -5);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}


TEST(move_cursor, sute5) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 2, 30);
    EXPECT_EQ(txt->cursor->position, 17);
    int k = 0;
    node *current = txt->begin;
    while(current != txt->cursor->line)
    {
        k++;
        current = current->next;
    }
    EXPECT_EQ(k, 2);
    remove_all(txt);
}

TEST(move_cursor, sute6) {
    text txt = create_text();
    // load(txt, path_to_file);
    testing::internal::CaptureStderr();

    move(txt, 2, 30);
        
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}