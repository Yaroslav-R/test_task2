#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>
#include<fstream>
#include<string>

/* using namespace testing; */
extern "C" {
#include "../app/common.h"
#include "../app/text.h"
#include "../app/_text.h"
}

// char path_to_file[] = "./tests/test_input1.txt";

TEST(showlastnonspace, suite1) {
    text txt = create_text();
    testing::internal::CaptureStdout();
    load(txt, "./tests/test_input1.txt");
    showlastnonspace(txt);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "ooo\n");
}

TEST(showlastnonspace, suite2) {
    text txt = create_text();
    testing::internal::CaptureStdout();
    load(txt, "./tests/test_input_slnp1.txt");
    showlastnonspace(txt);
    std::string output = testing::internal::GetCapturedStdout();
    
    EXPECT_EQ(output, "olabd\n");
}

TEST(showlastnonspace, suite3) {
    text txt = create_text();
    // fprintf(stderr,"length = %d\n", txt -> length);
    testing::internal::CaptureStdout();

    showlastnonspace(txt);
    
    std::string output = testing::internal::GetCapturedStderr();
    
    EXPECT_EQ(output, "There are already no any lines in the text!\n");
}

TEST(cb, suite1) {
    text txt = create_text();
    // testing::internal::CaptureStdout();
    load(txt, "./tests/test_cb_input.txt");
    move(txt, 2, 0);
    cb(txt);
    save(txt, "./tests/test_cb_output.txt");
    
    int k = 0;
    char arr[4] = {'3', '1', '2', '4'};

    std::ifstream f;
    f.open("./tests/test_cb_output.txt");
    std::string s;

    int cnt = 0;
    while (std::getline(f, s))
    {
        EXPECT_EQ(s[0], arr[cnt]);
        cnt++;
    }

}

TEST(cb, suite2) {
    text txt = create_text();
    // testing::internal::CaptureStdout();
    load(txt, "./tests/test_cb_input.txt");
    move(txt, 0, 0);
    cb(txt);
    save(txt, "./tests/test_cb_output.txt");
    
    int k = 0;
    char arr[4] = {'1', '2', '3', '4'};

    std::ifstream f;
    f.open("./tests/test_cb_output.txt");
    std::string s;

    int cnt = 0;
    while (std::getline(f, s))
    {
        EXPECT_EQ(s[0], arr[cnt]);
        cnt++;
    }

}

TEST(cb, suite3) {
    text txt = create_text();

    testing::internal::CaptureStderr();

    cb(txt);
    
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");
}

TEST(show, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 1, 2);
    testing::internal::CaptureStdout();
    show(txt);
    std::string output = testing::internal::GetCapturedStdout();
    int i = 0;
    node *current = txt->begin;
    while(current)
    {
        for (int j = 0; j < strlen(current->contents); j++)
        {
            if (current == txt->cursor->line
                   && j == txt->cursor->position)
            {
                EXPECT_EQ(output[i], '|');
                i++;
            }
            EXPECT_EQ(output[i], current->contents[j]);
            i++;
        }
        i++;
        current = current->next;
    }
    remove_all(txt);
}

TEST(show, suite2) {
    text txt = create_text();
    testing::internal::CaptureStderr();
    show(txt);
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}

TEST(input_string, suite1) {
    text txt = create_text();
    load(txt, path_to_file);
    move(txt, 0, 0);
    input_string(txt, "hello");
    save(txt, "./tests/output_is.txt");
    
    std::ifstream f;
    f.open("./tests/correct_output_is.txt");

    std::ifstream cur_f;
    cur_f.open("./tests/output_is.txt");
    std::string s;
    std::string cur_s;
    while(std::getline(f, s) && std::getline(cur_f, cur_s))
    {
        EXPECT_EQ(s, cur_s);
    }
    EXPECT_FALSE(std::getline(f, s) || std::getline(cur_f, cur_s));
    f.close();
    cur_f.close();
    remove_all(txt);
}

TEST(input_string, suite2) {
    text txt = create_text();
    
    load(txt, path_to_file);

    char *s;
    s = (char*)malloc(sizeof(char) * 256);
    
    for (int i = 0; i < MAXLINE + 1; i++)
    {
        s[i] = 't';
    }
    s[256] = '\0';

    move(txt, 0, 1);
    int code = input_string(txt, s);
    // testing::internal::CaptureStderr();
    EXPECT_EQ(code, 1);


    remove_all(txt);
}

TEST(input_string, suite3) {
    text txt = create_text();
    
    char s[] = "hello";
    
    testing::internal::CaptureStderr();
    input_string(txt, s);
    
    std::string output = testing::internal::GetCapturedStderr();
    EXPECT_EQ(output, "There are already no any lines in the text!\n");

    remove_all(txt);
}

