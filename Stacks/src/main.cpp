#include <string>
#include <iostream>
#include <fstream>
#include "Stack.h"

using namespace std;

// Helper function to extract the tag name from a tag string
string extractTagName(const string& tag) {
    if (tag.empty() || tag[0] != '<') return ""; // Not a valid tag

    size_t end = tag.find_first_of(" />");
    if (end == string::npos) return ""; // Invalid tag format

    string tagName = tag.substr(1, end - 1); // Extract the tag name
    if (tagName[0] == '/') {
        tagName = tagName.substr(1); // Remove '/' for closing tags
    }
    return tagName;
}

// Function to check if all tags are properly matched
bool isHTMLValid(const string& text) {
    Stack<string> stack;
    size_t pos = 0;

    while (pos < text.length()) {
        size_t openBracket = text.find('<', pos);
        if (openBracket == string::npos) break; // No more tags

        size_t closeBracket = text.find('>', openBracket);
        if (closeBracket == string::npos) return false; // Unmatched '<'

        string tag = text.substr(openBracket, closeBracket - openBracket + 1);
        string tagName = extractTagName(tag);

        if (tagName.empty()) return false; // Invalid tag

        // Check if it's a self-closing tag (ends with "/>")
        if (tag.length() >= 2 && tag[tag.length() - 2] == '/' && tag[tag.length() - 1] == '>') {
            // Self-closing tag: skip it (do not push onto the stack)
            pos = closeBracket + 1;
            continue;
        }

        if (tag[1] != '/') {
            // Opening tag: push onto the stack
            stack.push(tagName);
        } else {
            // Closing tag: check if it matches the top of the stack
            if (stack.empty() || stack.top() != tagName) {
                return false; // Mismatched tag
            }
            stack.pop();
        }

        pos = closeBracket + 1; // Move to the next character after '>'
    }

    return stack.empty(); // All tags must be matched
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
        cout << "The HTML file has valid and matched tags." << endl;
    } else {
        cout << "The HTML file has invalid or unmatched tags." << endl;
    }

    return 0;
}