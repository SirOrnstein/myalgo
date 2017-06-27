#ifndef __RECURSION_H__
#define __RECURSION_H__

//compute fib
#include <stdint.h>

uint32_t recursive_fib_internal( uint32_t a, uint32_t b, uint32_t n) {
    if (n == 1) {
        return b;
    }
    return recursive_fib_internal(b, a+b, n-1);
}

uint32_t recursive_fib(uint32_t n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    return recursive_fib_internal(0, 1, n);
}

uint32_t iterative_fib(uint32_t n) {
    if (n == 0) {
        return 0;
    }

    if (n == 1) {
        return 1;
    }

    uint32_t a = 0, b = 1, t = b;
    for (uint32_t i = n; i > 1; --i) {
        t = a + b;
        a = b;
        b = t;
    }
    return t;
}

int recursive_pow(uint32_t base, uint32_t n) {

    if (n == 0 || base == 1) {
        return 1;
    }

    if (n == 1 || base == 0) {
        return base;
    }

    if (n & 1) {
        return base * recursive_pow( base * base, n/2);
    } else {
        return recursive_pow( base * base, n/2);
    }
}

#endif //__RECURSION_H__
