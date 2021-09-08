
#include <cstdint>
#include <iostream>

void* baz(void) {
    return (void*)(intptr_t) 482;
}

// TODO: Try simplifying the syntax below by using a typedef for the function pointer

int main() {
    // declare a function pointer named baz_ptr
    void* (*baz_ptr)(void);
    // assign baz_ptr to point to baz; explicit cast is not necessary
    baz_ptr = (void*(*)(void))baz; 
    // deference baz_ptr, and call the function
    void* retptr = (*baz_ptr)();
    // cast the returned void* and print it out
    std::cout << (intptr_t)retptr << std::endl;
}

