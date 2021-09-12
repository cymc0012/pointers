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
    // TODO Exercise 1: Implement print_bytes
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

// TODO Exercise 3: Define a function called hello_world which fcn_ptr_t can
//                  point to.

/*
 * Computes the area of a rectangular prism (length * width * height)
 */
double compute_area(void *arg) {
    // TODO Exercise 4: Implement compute_area
}

int main() {
    /*** print the raw bytes of some variables ***/
    int i = 0xdeadbeef;
    print_bytes((void*)&i, sizeof(i));

    double pi = 3.14159265;
    print_bytes((void*)&pi, sizeof(pi));

    /*** call some functions using function pointers ***/

    // TODO Exercise 2: Create typedefs for foo_ptr_t and bar_ptr_t
    foo_ptr_t foo_ptr = foo;
    foo(0, 0.0, '0');

    bar_ptr_t bar_ptr = bar;
    char c = 'A';
    int x = bar(&c, 0);

    typedef double* (*fcn_ptr_t)(void);
    fcn_ptr_t hello_world_ptr = hello_world;
    hello_world_ptr();

    /*** pass multiple arguments using a void pointer ***/

    // TODO Exercise 4: Design a way to pass the length, width, and height of a
    //                  rectangular prism to a function which takes a single
    //                  void pointer as an argument.
    double area = compute_area(/* TODO */);
}