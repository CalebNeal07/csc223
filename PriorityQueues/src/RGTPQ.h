#include <stdexcept>
#include <string>
#include <iostream>

#define MAX_SIZE 40

using namespace std;

enum Color { RED, GREEN };

struct RGThing {
    Color color;
    string label;
};

struct RGPair {
    RGThing green_thing;
    RGThing red_thing;
};

class RGTPQ {
private:
    RGPair elements[MAX_SIZE];
    int red_count;
    int green_count;

    void shiftLeft() {
        for (int i = 0; i < MAX_SIZE - 1; i++) {
            elements[i] = elements[i + 1];
        }
    }

public:
    RGTPQ() : red_count(0), green_count(0) {}

    bool empty() {
        return red_count == 0 && green_count == 0;
    }

    void insert(RGThing thing) {
        if (thing.color == RED) {
            if (red_count >= green_count) {
                elements[red_count] = {thing, thing};
            } else {
                elements[red_count].red_thing = thing;
            }
            red_count++;
        } else {
            if (green_count >= red_count) {
                elements[green_count] = {thing, thing};
            } else {
                elements[green_count].green_thing = thing;
            }
            green_count++;
        }
    }

    RGPair remove() {
        if (red_count > 0 && green_count > 0) {
            RGPair val = elements[0];
            shiftLeft();
            red_count--;
            green_count--;
            return val;
        } else {
            throw std::underflow_error("Queue is empty");
        }
    }
};