//compute pow
#include <iostream>
#include <string>
#include <stdint.h>

using namespace std;

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

int main()
{
    cout << recursive_pow(1, 4) << endl; 
    cout << recursive_pow(2, 0) << endl; 
    cout << recursive_pow(1, 0) << endl; 
    cout << recursive_pow(0, 4) << endl; 
    cout << recursive_pow(3, 4) << endl; 
    cout << recursive_pow(2, 10) << endl; 
    cout << recursive_pow(5, 3) << endl; 
}
