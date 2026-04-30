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

TEST(ListNode, Find) {
    ListNode* node = new ListNode("first", nullptr);
    EXPECT_EQ(ListNode::find("first", node), node); 
    delete node;
}

TEST(ListNode, FindNonExistent) {
    ListNode* node = new ListNode("first", nullptr);
    EXPECT_EQ(ListNode::find("second", node), nullptr); 
    delete node;
}

TEST(ListNode, FindMultiple) {
    ListNode* node2 = new ListNode("second", nullptr);
    ListNode* node = new ListNode("first", node2);
    EXPECT_EQ(ListNode::find("second", node), node2); 
    EXPECT_EQ(ListNode::find("first", node), node);
    delete node;
    delete node2;
}

TEST(ListNode, Remove) {
    ListNode* node2 = new ListNode("second", nullptr);
    ListNode* node = new ListNode("first", node2);
    EXPECT_EQ(ListNode::find("second", node), node2);

    // remove "second" and searching for it returns nullptr
    ListNode::remove("second", node);
    EXPECT_EQ(ListNode::find("second", node), nullptr);
    delete node;
}

TEST(ListNode, RemoveFromHead) {
    ListNode* node = new ListNode("first", nullptr);

    // test node exists
    EXPECT_EQ(ListNode::find("first", node), node);

    ListNode::remove("first", node);
    EXPECT_EQ(ListNode::find("first", node), nullptr);
}

TEST(ListNode, RemoveInMiddle) {
    ListNode* node3 = new ListNode("third", nullptr);
    ListNode* node2 = new ListNode("second", node3);
    ListNode* node = new ListNode("first", node2);

    // test that every node exists
    EXPECT_EQ(ListNode::find("first", node), node);
    EXPECT_EQ(ListNode::find("second", node), node2);
    EXPECT_EQ(ListNode::find("third", node), node3);

    // delete 2nd node and check it doesn't exist in the list anymore
    ListNode::remove("second", node);
    EXPECT_EQ(ListNode::find("second", node), nullptr);
    delete node;
    delete node3;
}

TEST(ListNode, RemoveNonExistent) {
    ListNode* node = new ListNode("first", nullptr);

    // remove a word that isn't in linked list and expect that nothing in the list changed
    ListNode::remove("none", node);
    EXPECT_EQ(ListNode::find("first", node), node);
    delete node;
}

TEST(ListNode, delete_list) {
    ListNode* node3 = new ListNode("third", nullptr);
    ListNode* node2 = new ListNode("second", node3);
    ListNode* node = new ListNode("first", node2);

    // test that the nodes exist
    EXPECT_EQ(ListNode::find("first", node), node);

    // use delete_list() 
    ListNode::delete_list(node);
}

TEST(ListNode, delete_empty_list) {
    ListNode* empty_list = nullptr;

    ListNode::delete_list(empty_list);

    // deleting an empty list should not do anything to the list
    EXPECT_EQ(empty_list, nullptr);
}

TEST(ListNode, Print) {
    stringstream ss;
    
    ListNode* node3 = new ListNode("third", nullptr);
    ListNode* node2 = new ListNode("second", node3);
    ListNode* node = new ListNode("first", node2);

    ListNode::print(ss, node);
    
    EXPECT_EQ(ss.str(), "first\nsecond\nthird\n");

    ListNode::delete_list(node);
}

TEST(ListNode, PrintEmptyList) {
    stringstream ss;

    ListNode::print(ss, nullptr);
    EXPECT_EQ(ss.str(), "");
}

TEST(LinkedList, Constructor) {
    LinkedList LL;
    EXPECT_TRUE(true);
}

TEST(LinkedList, Insert) {
    LinkedList LL;
    std::string s = "test";
    LL.insert(s);
    EXPECT_FALSE(LL.is_empty());
}

TEST(LinkedList, Find) {
    LinkedList LL;
    std::string s = "test";
    LL.insert(s);
    EXPECT_TRUE(LL.find(s));
}

TEST(LinkedList, FindMultiple) {
    LinkedList LL;
    LL.insert("test1");
    LL.insert("test2");
    EXPECT_TRUE(LL.find("test1"));
    EXPECT_TRUE(LL.find("test2"));
}

TEST(LinkedList, Remove) {
    LinkedList LL;
    LL.insert("test1");
    LL.insert("test2");
    LL.remove("test1");
    EXPECT_FALSE(LL.find("test1"));
}

TEST(LinkedList, RemoveNonExistent) {
    LinkedList LL;
    LL.insert("test1");
    LL.insert("test2");

    // attempt to remove non existent word in list
    LL.remove("test3");
    EXPECT_TRUE(LL.find("test1"));
    EXPECT_TRUE(LL.find("test2"));
    EXPECT_FALSE(LL.find("test3"));
}

TEST(LinkedList, Print) {
    LinkedList LL;
    stringstream ss;
    
    LL.insert("test1");
    LL.insert("test2");
    LL.print(ss);

    // check in reverse order bc insert() inserts at the beginning
    EXPECT_EQ(ss.str(), "test2\ntest1\n");
}

TEST(LinkedList, PrintEmptyList) {
    LinkedList emptyLL;
    stringstream ss;

    emptyLL.print(ss);

    EXPECT_EQ(ss.str(), "");
}


}