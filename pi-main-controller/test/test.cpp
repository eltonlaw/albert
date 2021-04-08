#include <iostream>
#include <vector>
#include "test_queue.h"
#include "test_random.h"

void run_tests() {
    // Instantiate vector of all testing functions (thunks)
    std::vector<void(*)()> test_fns {
        test_fixed_queue,
        test_urandom,
    };
    // Loop over each unit test, running it
    for (const auto& test_fn : test_fns) {
        test_fn();
    }
    std::cout << std::endl;
}

// Runs all unit tests
int main(int argc, char** argv) {
    run_tests();
    return 0;
}
