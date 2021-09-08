
#include <iostream>

void print_char(void * vptr) {
    char * cptr = (char *)vptr; // Casting from void* to char*
    std::cout << "Cptr: " << *cptr << std::endl;
}

int main() {
    char c = 'A'; // 'A' is 0x41 in hex
    print_char((void *)&c); // Note the explicit cast to (void *)

    int i = 0x41FFFF42;
    print_char(&i); // Implicit cast to (void *); works only if the two types have
			        // a known and well-defined relationship -- like numeric types
}
