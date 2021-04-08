#include "test_utils.h"

#include "../src/lib/lib.h"

namespace t = testing;

void test_urandom() {
    lib::urandom rng;
    t::assert_true(rng.random() > 0);
    t::assert_true(rng.random() > 0);
    t::assert_true(rng.random() > 0);
    t::assert_true(rng.random() > 0);
    t::assert_true(rng.random() > 0);
}
