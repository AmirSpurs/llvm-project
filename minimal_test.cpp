#include <iostream>
#include <cassert>

void test_address(int& a) {
    // Should work: taking address of lvalue statement expression
    int* p = &({ a; });
    assert(p == &a);
    *p = 42;
    assert(a == 42);
}

void test_assignment(int& a) {
    ({ a; }) = 100;
    assert(a == 100);
}



int main() {
    int x = 0, y = 0, z = 0;
    
    // Test 1: Taking address
    test_address(x);
    assert(x == 42);
    
    // Test 2: Assignment
    test_assignment(y);
    assert(y == 100);
    
    int c = ({ int v = 9; int tmp = v +1 ; tmp * 100000;}) ;
    assert(c == 1000000);
    
    std::cout << "All tests passed!\n";
    return 0;
}
