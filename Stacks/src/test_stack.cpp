#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
using namespace std;

#include "Stack.h"

TEST_CASE("Test basic stack operations on stack of ints") {
    Stack<int> stack;
    stack.push(9);
    CHECK(stack.top() == 9);
    stack.push(11);
    CHECK(stack.top() == 11);
    stack.push(42);
    CHECK(stack.top() == 42);
    CHECK(stack.pop() == 42);
    CHECK(stack.top() == 11);
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == 9);
    CHECK(stack.empty() == true);
}

TEST_CASE("Test basic stack operations on stack of strings") {
    Stack<string> stack;
    stack.push("cheese");
    CHECK(stack.top() == "cheese");
    stack.push("anchovies");
    CHECK(stack.top() == "anchovies");
    stack.push("onions");
    CHECK(stack.top() == "onions");
    CHECK(stack.pop() == "onions");
    CHECK(stack.top() == "anchovies");
    CHECK(stack.empty() == false);
    stack.pop();
    CHECK(stack.pop() == "cheese");
    CHECK(stack.empty() == true);
}
