#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test can create and render List Nodes") {
    Node<int>* node1 = new Node<int>(0);
    CHECK(node1->cargo == 0);
}

TEST_CASE("Test can create and render List Nodes") {
    Node<int>* node1 = new Node<int>(0);
    Node<int>* node2 = new Node<int>(42);
    CHECK(node2->cargo == 42);
    CHECK(node1->to_string() == "0");
    CHECK(node2->to_string() == "42");
}

TEST_CASE("Test can link nodes together") {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2, node1);
    Node<int>* node3 = new Node<int>(3, node2);
    CHECK(node2->next == node1);
    CHECK(node3->next == node2);
    CHECK(node3->next->next == node1);
}

TEST_CASE("Test can display linked nodes") {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2, node1);
    Node<int>* node3 = new Node<int>(3, node2);
    CHECK(render_list(node3) == "3, 2, 1");
}

TEST_CASE("Test can display linked nodes backwards") {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2, node1);
    Node<int>* node3 = new Node<int>(3, node2);
    Node<int>* node4 = new Node<int>(4, node3);
    CHECK(render_list(node4) == "4, 3, 2, 1");
    CHECK(render_list_backward(node4) == "1, 2, 3, 4");
}

TEST_CASE("Test can display linked nodes with parenthesis") {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2, node1);
    Node<int>* node3 = new Node<int>(3, node2);
    Node<int>* node4 = new Node<int>(4, node3);
    CHECK(render_pretty(node4, &render_list) == "(4, 3, 2, 1)");
    CHECK(render_pretty(node4, &render_list_backward) == "(1, 2, 3, 4)");
}

TEST_CASE("Test can remove second element from a linked list") {
    Node<int>* node1 = new Node<int>(1);
    Node<int>* node2 = new Node<int>(2, node1);
    Node<int>* node3 = new Node<int>(3, node2);
    Node<int>* node4 = new Node<int>(4, node3);
    CHECK(render_list(node4) == "4, 3, 2, 1");
    Node<int>* second_node = remove_second(node4);
    CHECK(render_list(node4) == "4, 2, 1");
}