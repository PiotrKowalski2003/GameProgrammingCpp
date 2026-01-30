#include "raylib.h"

int main() {

    // false
    bool equal {4 == 9};

    // true
    bool notEqual {4 != 9};

    // true
    bool less {4 < 9};

    // false
    bool greater {4 > 9};

    // true
    bool lessEqual {4 <= 9};

    // false
    bool greaterEqual {4 >= 9};

    const int width = 350;

    InitWindow(width, 200, "Init Window");




    return 0;
}