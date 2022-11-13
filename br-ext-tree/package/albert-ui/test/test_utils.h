#pragma once
#include <iostream>
#include <stdlib.h>

namespace testing {

// FIXME: pass through cmake build
#define ON_FAIL_EXIT 1
#define ON_FAIL ON_FAIL_EXIT

template <class T>
void assert_equal(T x, T y) {
    try {
        if (x == y) {
            std::cout << ".";
        } else {
            std::cout << "F";
            if (ON_FAIL == ON_FAIL_EXIT) {
                std::cout << std::endl << x << " != " << y << std::endl;
                exit (EXIT_FAILURE);
            }
        }
    } catch (std::exception& e) {
        std::cout << "E";
        if (ON_FAIL == ON_FAIL_EXIT) {
            std::cout << std::endl << x << " != " << y << std::endl;
            exit (EXIT_FAILURE);
        }
    }            
}

void assert_true(bool b) {
    assert_equal(b, true);
}

} // namespace testing
