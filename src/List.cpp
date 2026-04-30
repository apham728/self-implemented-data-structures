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

void ArrayList::insert(const string & word) {
    // check if inserting into full list
    if (is_full()) {
        error(word, "Trying to insert into a full list"); return;
    }

    // don't have to check if the inserted word will be duplicate so just insert
    buf[size] = word;
    size++;
}

void ArrayList::remove(const string & word) {
    int index = find_index(word);

    // check if word exists
    if (index == -1) { error(word, "Remove a word that doesn't exist in the list"); return; }

    // replace element at index with last word and decrement size
    buf[index] = buf[size-1];
    size--;
}

bool ArrayList::is_empty() {
    return size == 0;
}

bool ArrayList::is_full() {
    return size == capacity;
}

void ArrayList::erase() {
    size = 0;
}

void ArrayList::print(ostream & out) {
    for (int i = 0; i < size; i++) {
        out << buf[i] << endl;
    }
}

ArrayList::~ArrayList() {
    delete[] buf;
}

ostream & operator << (ostream & out, List & L) {
    L.print(out);
    return out;
}

void error(string word, string msg) {
    cerr << "ERROR: " << msg << " caused by the word: " << word;
}