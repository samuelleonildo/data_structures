#ifndef HEAP_HPP
#define HEAP_HPP

#include <vector>
#include <stdexcept> // for std::out_of_range
#include <functional> // for std::less


template <typename E, typename Compare = std::less<E>>
class Heap
{
private:
    std::vector<E> vec;
    Compare comp;

    size_t parent_(size_t i) const { return (i - 1) / 2; }
    size_t left_child_(size_t i) const { return (i * 2) + 1; }
    size_t right_child_(size_t i) const { return (i * 2) + 2; }

    void sift_up_(size_t i);

    void sift_down_(size_t i);

public:
    Heap(void) = default;
    Heap(const std::vector<E>& _vec);
    
    ~Heap() = default;

    void push(const E& value);

    void pop(void);

    const E& top(void) const
    {
        if (vec.size() > 0) { return vec[0]; }
        throw std::out_of_range("Heap::top() - Heap is empty");
    }

    const size_t size(void) const { return vec.size(); }

    const bool empty(void) const { return vec.empty(); }
};


// === constructor ===
template <typename E, typename Compare>
Heap<E, Compare>::Heap(const std::vector<E>& _vec)
{
    vec = _vec;

    if (!vec.empty())
    {
        for (size_t i = parent_(vec.size()); i > 0; i--)
        {
            sift_down_(i - 1);
        }
    }
}


// === private methods ===
template <typename E, typename Compare>
void Heap<E, Compare>::sift_up_(size_t i)
{
    bool heap = false;
    while (i > 0 && !heap)
    {
        size_t pi = parent_(i);

        if (comp(vec[i], vec[pi]))
        {
            std::swap(vec[i], vec[pi]);
            i = pi;
        }
        else { heap = true; }
    }
}

template <typename E, typename Compare>
void Heap<E, Compare>::sift_down_(size_t i)
{
    size_t n = vec.size();
    size_t k = i;

    bool heap = false;
    while (!heap)
    {
        size_t left = left_child_(k);
        size_t right = right_child_(k);
        size_t smallest = k;
    
        if (left < n && comp(vec[left], vec[smallest])) { smallest = left; }
        if (right < n && comp(vec[right], vec[smallest])) { smallest = right; }

        if (smallest != k)
        {
            std::swap(vec[k], vec[smallest]);
            k = smallest;
        }
        else { heap = true; }
    }
}


// === public methods ===
template <typename E, typename Compare>
void Heap<E, Compare>::pop(void)
{
    if (!vec.empty())
    {
        vec[0] = vec.back();
        vec.pop_back();

        if (!vec.empty()) { sift_down_(0); }
    }
}

template <typename E, typename Compare>
void Heap<E, Compare>::push(const E& value)
{
    vec.push_back(value);
    sift_up_(vec.size() - 1);
}

#endif