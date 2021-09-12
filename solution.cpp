/*
 * EECS 482 - Lab 01 (Pointers)
 * Exercises for practicing use of void pointers and function pointers.
 *
 * There are a number of TODOs throughout this file: follow the instructions at
 * each one to complete the exercises.
 */

#include <iostream>
#include <iomanip>

using std::cout;
using std::endl;
using std::setw;
using std::setfill;
using std::hex;

/*
 * Prints n bytes from memory, starting at address pointed to by ptr.
 *
 * REQUIRES: ptr points to n bytes of valid memory.
 */
void print_bytes(const void *ptr, const size_t n) {
    uint8_t *base = (uint8_t*)ptr;
    for(uint8_t *p = base; p < base + n; ++p) {
        int byte = (int)*p; // cast so cout doesn't interpret byte as a char
        cout << "0x" << setw(2) << setfill('0') << hex << byte << endl;
    }
}

void foo(int i, double d, char c) {
    cout << "calling foo with args:" << endl;
    cout << "i = " << i << endl;
    cout << "d = " << d << endl;
    cout << "c = " << c << endl;
}

int bar(char *ptr, int n) {
    cout << "calling bar with args" << endl;
    cout << "ptr = " << (void*)ptr << endl;
    cout << "n = " << n << endl;
    return 0;
}

double* hello_world() {
    cout << "hello world" << endl;
    return nullptr;
}

struct FuncArgs {
    double length;
    double width;
    double height;
};

/*
 * Computes the area of a rectangular prism (length * width * height)
 */
double compute_area(void *arg) {
    FuncArgs *args_ptr = (FuncArgs*)arg;
    return args_ptr->length * args_ptr->width * args_ptr->height;
}

int main() {
    /*** print the raw bytes of some variables ***/
    int i = 0xdeadbeef;
    print_bytes((void*)&i, sizeof(i));

    double pi = 3.14159265;
    print_bytes((void*)&pi, sizeof(pi));

    /*** call some functions using function pointers ***/
    typedef void (*foo_ptr_t)(int, double, char);
    foo_ptr_t foo_ptr = foo;
    foo(0, 0.0, '0');

    typedef int (*bar_ptr_t)(char*, int);
    bar_ptr_t bar_ptr = bar;
    char c = 'A';
    int x = bar(&c, 0);

    typedef double* (*fcn_ptr_t)(void);
    fcn_ptr_t hello_world_ptr = hello_world;
    hello_world_ptr();

    /*** pass multiple arguments using a void pointer ***/
    FuncArgs args = {2.0, 3.0, 1.0};
    double area = compute_area((void*)&args);
}