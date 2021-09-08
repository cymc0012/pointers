
#include <cstdint>
#include <iostream>

void foo(void * vptr) {
    int i = (intptr_t)vptr;
    std::cout << i << std::endl;
}

int main() {
    intptr_t iptr = 482;
    foo((void *)iptr);
}
