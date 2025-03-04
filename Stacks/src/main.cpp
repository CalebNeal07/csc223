#include <string>
#include <iostream>
#include <fstream>

#include "Stack.h"

using namespace std;

bool isHTMLValid(const string& text) {
    Stack<char> stack;

    for (char ch : text) {
        if (ch == '<') {
            stack.push(ch);
        } else if (ch == '>') {
            if (stack.empty()) {
                return false; // Unmatched closing bracket
            }
            stack.pop();
        }
    }

    return stack.empty(); // If stack is empty, all brackets are matched
}

int main(int argc, char* argv[]) {
if (argc == 1) {
        cerr << "Provide the name of an HTML file" << endl;
        return 1;
    }

    ifstream f(argv[1]);
    if (!f.is_open()) {
        cerr << "Error opening the file!" << endl;
        return 1;
    }

    // Read the entire file into a string
    string text((istreambuf_iterator<char>(f)), istreambuf_iterator<char>());
    f.close();

    if (isHTMLValid(text)) {
        cout << "The HTML file has matched angle brackets." << endl;
    } else {
        cout << "The HTML file has unmatched angle brackets." << endl;
    }

    return 0;
}
