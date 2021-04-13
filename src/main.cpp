#include <iostream>

int main (const int argc, const char** argv) {
#ifdef TEST
    std::cout << "Hello, World!" << std::endl;
#endif
    return 0;
}
