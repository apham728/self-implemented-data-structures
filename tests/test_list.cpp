#include <gtest/gtest.h>
#include <algorithm>
#include <string>
#include <ctime>
#include <iostream>
#include <sstream>
#include "../include/List.h"
using namespace std;

namespace {

TEST(ArrayList, ConstructorNormal) {
    ArrayList AL(2);
    EXPECT_TRUE(AL.is_empty());
}

TEST(ArrayList, Insert) {
    ArrayList AL(1);
    string s = "test";
    AL.insert(s);
    EXPECT_FALSE(AL.is_empty());
}

TEST(ArrayList, InsertWhenFll) {
    ArrayList AL(1);
    string s = "test";
    AL.insert(s);
    EXPECT_TRUE(AL.is_full());

    AL.insert("fll");
    EXPECT_FALSE(AL.find("fll"));
}

TEST(ArrayList, Find) {
    ArrayList AL(1);
    string s = "test";
    AL.insert(s);
    EXPECT_TRUE(AL.find(s));
}

TEST(ArrayList, Remove) {
    ArrayList AL(1);
    string s = "test";
    AL.insert(s);
    EXPECT_TRUE(AL.find(s));

    AL.remove(s);
    EXPECT_FALSE(AL.find(s));
}

TEST(ArrayList, RemoveWordNotInList) {
    ArrayList AL(1);
    string s = "test";
    AL.insert(s);
    EXPECT_TRUE(AL.find(s));

    AL.remove("tester");
    EXPECT_TRUE(AL.find(s));
}

TEST(ArrayList, PrintList) {
    stringstream ss;
    
    ArrayList AL(2);
    AL.insert("hello");
    AL.insert("world");
    
    AL.print(ss);
    EXPECT_EQ(ss.str(), "hello\nworld\n");
}

TEST(ArrayList, PrintOperator) {
    stringstream ss;
    
    ArrayList AL(2);
    AL.insert("hello");
    AL.insert("world");
    
    ss << AL;
    EXPECT_EQ(ss.str(), "hello\nworld\n");
}

TEST(ArrayList, PrintEmptyList) {
    stringstream ss;
    
    ArrayList AL(2);
    
    ss << AL;
    EXPECT_EQ(ss.str(), "");
}


}