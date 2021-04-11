#include <vector>

namespace lib  {

/* FIFO Queue with fixed buffer size
 * 
 * When getting by index, higher indices mean it was queued later
 *
 * On overflow, earliest  
 * 
 * Implemented as a circular buffer, `i_start` determines where
 * the start of the array is and gets updated whenever an enqueue
 * overwrites an element.
 */
template <typename T, int max_len>
class fixed_queue {
public:
    fixed_queue();
    ~fixed_queue();
    void pop_front();

    bool is_full();
    void enqueue(const T& value);
    const T& get(int i);
    
    // const T& fixed_queue[](std::size_t idx) const;
    int size = 0;
    int capacity = max_len;

private:
    std::vector<T> vec;
    int i_start = 0;
};

template <typename T, int max_len>
fixed_queue<T, max_len>::fixed_queue() :
    vec(max_len) { }

template <typename T, int max_len>
fixed_queue<T, max_len>::~fixed_queue() {  }

template <typename T, int max_len>
bool fixed_queue<T, max_len>::is_full() {
    return (size == vec.size());
}

/* Inserts into fixed queue
 *
 * There are multiple branches depending on 1) how many
 * elements have already been enqueued and 2) i_start:
 *
 * - Vector is full and i_start is past the end and needs
 *   to loop back => set i_start to 0 and overwrite 0 index
 *   with new val
 * - Vector is full => overwrite i_start with new val and
 * - Vector is not full => Add to end
 */
template <typename T, int max_len>
void fixed_queue<T, max_len>::enqueue(const T& value) {
    if (is_full()) {
        if (i_start == size)
           i_start = 0; 
        vec[i_start++] = value;
    } else {
        vec[size++] = value; 
    }
}

template <typename T, int max_len>
const T& fixed_queue<T, max_len>::get(int i) {
    int i_offset = i + i_start;
    if (i_offset >= vec.size())
        i_offset -= vec.size();

    return vec[i_offset]; 
}

} // namespace lib
