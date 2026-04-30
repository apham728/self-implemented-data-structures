#include <iostream>
#include <fstream> // ifstream
#include "../include/List.h"
#include "Timer.h"
using namespace std;

// !!!  ARRAY LIST !!!

// constructor
ArrayList::ArrayList(int max_len) 
    : List("ArrayList"),
        capacity((max_len < 1) ? 1 : max_len), 
        size(0), 
        buf(new string[capacity]) {}

// helper method find_index
int ArrayList::find_index(const string & word) {
    for (int i = 0; i < size; i++) {
        if (buf[i] == word) return i;
    }
    
    return -1;
}

bool ArrayList::find(const string & word) {
    return find_index(word) != -1;
}

bool ArrayList::is_empty() {
    return size == 0;
}

bool ArrayList::is_full() {
    return size == capacity;
}