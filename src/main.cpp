#include <iostream>
#include <string>
#include "../include/List.h"
using namespace std;

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./hw <input_file>" << std::endl;
        return 1;
    }

    string input_file = "words.txt";
    
    cout << "Running list benchmarks with input file: "
         << input_file << endl;

    measure_lists(input_file);

    return 0;
}