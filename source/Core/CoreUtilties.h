#include <iostream>

namespace Core {
    void Log(const char* text) {
        std::cout << "[cppmon] " << text;
    }
}