//compute fib 
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;



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

int main()
{
    cout << "recursive : " << endl;
    cout << recursive_fib(1) << endl; 
    cout << recursive_fib(2) << endl; 
    cout << recursive_fib(3) << endl; 
    cout << recursive_fib(5) << endl; 
    cout << recursive_fib(6) << endl; 

    cout << "iterative : " << endl;
    cout << iterative_fib(1) << endl; 
    cout << iterative_fib(2) << endl; 
    cout << iterative_fib(3) << endl; 
    cout << iterative_fib(5) << endl; 
    cout << iterative_fib(6) << endl; 
}
