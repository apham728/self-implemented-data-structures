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

// !!! LISTNODE STATIC METHODS !!!
ListNode * ListNode::find(const string & word, ListNode * L) {
    for(ListNode* curr = L; curr != nullptr; curr = curr->next) {
        if (curr->data == word) return curr;
    }
    return nullptr;
}

void ListNode::remove(const string & word, ListNode * & L) {
    if (L != nullptr && L->data == word) {
        ListNode* temp = L;
        L = L->next;
        delete temp;
        return;
    }

    for (ListNode* curr = L; curr != nullptr && curr->next != nullptr; curr = curr->next) {
        if (curr->next->data == word) {
            ListNode* temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            return;
        }
    }

    error(word, "Trying to remove a word that doesn't exist in the linked list");
    return;
}

void ListNode::delete_list(ListNode * L) {
    while(L != nullptr) {
        ListNode* temp = L;
        L = L->next;
        delete temp;
    }    
}

void ListNode::print(ostream & out, ListNode * L) {
    for (ListNode* curr = L; curr != nullptr; curr = curr->next) {
        out << curr->data << endl;
    }
}

// !!!  LINKED LIST !!!

LinkedList::LinkedList()
    : List("LinkedList"),
        head(nullptr) {}

void LinkedList::insert(const string & word) {
    // unordered list so just insert at head
    ListNode* temp = new ListNode(word, head);
    head = temp;
}

bool LinkedList::find(const string & word) {
    ListNode* index = ListNode::find(word, head);
    if (index != nullptr) return true;
    return false;
}

void LinkedList::remove(const string & word) {
    ListNode::remove(word, head);
}

bool LinkedList::is_empty() {
    return head == nullptr;
}

bool LinkedList::is_full() {
    return false; // in a sense, linked lists continue to grow without much of a limitation besides memory
}

void LinkedList::erase() {
    ListNode::delete_list(head);
    head = nullptr;
}

void LinkedList::print(ostream & out) {
    ListNode::print(out, head);
}

LinkedList::~LinkedList() {
    ListNode::delete_list(head);
}


ostream & operator << (ostream & out, List & L) {
    L.print(out);
    return out;
}

void error(string word, string msg) {
    cerr << "ERROR: " << msg << " caused by the word: " << word;
}

void insert_all_words(int k, string file_name, List & L) {
    Timer t;
    double eTime;
    ifstream in(file_name); 
    if (!in) {
        error(file_name, "could not open file");
    }   
    int limit = k * NWORDS / 10; // k represents tenths of input file; k = 1 = 10% of file; k = 2 = 20% of file; ...
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.insert(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tInsert = " << eTime << endl;
}

void find_all_words(int k, string file_name, List & L) {
    Timer t;
    double eTime;
    ifstream in(file_name);
    if (!in) {
        error(file_name, "could not open file");
    }
    int limit = k * NWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.find(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tFind = " << eTime << endl;
}

void remove_all_words(int k, string file_name, List & L) {
    Timer t;
    double eTime;
    ifstream in(file_name);
    if (!in) {
        error(file_name, "could not open file");
    }
    int limit = k * NWORDS / 10;
    t.start();
    for (string word; (in >> word) && limit > 0; --limit)
        L.remove(word);
    t.elapsedUserTime(eTime);
    in.close();
    cout << "\t\tRemove = " << eTime << endl;
}

void measure_list_methods(string file_name, List & L) {
    cout << L.name << endl;
    for (int K = 1; K <= 10; ++K) {
        cout << "\tK = " << K << endl;
        insert_all_words(K, file_name, L);
        find_all_words(K, file_name, L);
        remove_all_words(K, file_name, L);
        if (!L.is_empty() )
            error(L.name, "is not empty");
    }
        
}

void measure_lists(string input_file) {
    ArrayList AL(NWORDS);
    LinkedList LL;

    measure_list_methods(input_file, AL);
    measure_list_methods(input_file, LL);
}