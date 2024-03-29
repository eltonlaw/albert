#pragma once

#include "test_utils.h"

#include "../src/lib/lib.h"

namespace t = testing;

void test_circular_queue() {
    t::assert_equal(0, 0);
    lib::circular_queue<int, 3> q;
    t::assert_equal(q.size, 0);
    t::assert_equal(q.get(0), 0);
    q.enqueue(1);
    t::assert_equal(q.get(0), 1);
    q.enqueue(2);
    t::assert_equal(q.get(1), 2);
    q.enqueue(3);
    t::assert_equal(q.get(2), 3);
    q.enqueue(4);
    t::assert_equal(q.get(0), 2);
    t::assert_equal(q.get(1), 3);
    t::assert_equal(q.get(2), 4);
    q.enqueue(5);
    t::assert_equal(q.get(0), 3);
    t::assert_equal(q.get(1), 4);
    t::assert_equal(q.get(2), 5);
    q.enqueue(6);
    t::assert_equal(q.get(0), 4);
    t::assert_equal(q.get(1), 5);
    t::assert_equal(q.get(2), 6);
    q.enqueue(7);
    t::assert_equal(q.get(0), 5);
    t::assert_equal(q.get(1), 6);
    t::assert_equal(q.get(2), 7);
}
