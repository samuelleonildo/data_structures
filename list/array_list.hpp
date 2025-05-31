#ifndef ARRAY_LIST_HPP
#define ARRAY_LIST_HPP

#include <algorithm>
#include <stdexcept>


template <typename E>
class ArrayList
{
protected:
    E* arr;
    size_t list_size;
    size_t capacity;

public:
    // constructor / destructor
    ArrayList(void);
    ~ArrayList();

    // no return methods
    void push_back(const E& it);
    void clear(void);

    // return methods
    size_t size(void) const;
    bool empty(void) const;
    const E& front(void) const;
    const E& back(void) const;
    E pop_back(void);

    // operators
    E& operator[](size_t index);
};

// definition

// constructor / destructor
template <typename E>
ArrayList<E>::ArrayList(void) : arr(nullptr), list_size(0), capacity(0) {}

template <typename E>
ArrayList<E>::~ArrayList() { clear(); }


// no return methods
template <typename E>
void ArrayList<E>::push_back(const E& it)
{
    if (list_size >= capacity)
    {
        size_t new_capacity = (capacity == 0) ? 1 : (capacity * 2);
        E* new_arr = new E[new_capacity];

        if (arr != nullptr)
        {
            std::copy(arr, arr + list_size, new_arr);
            delete[] arr;
        }
        
        arr = new_arr;
        capacity = new_capacity;
    }

    arr[list_size++] = it;
}

template <typename E>
void ArrayList<E>::clear(void)
{
    if (arr != nullptr)
    {
        delete[] arr;
        arr = nullptr;

        list_size = 0;
        capacity = 0;
    }
}


// return methods
template <typename E>
size_t ArrayList<E>::size(void) const { return list_size; }

template <typename E>
bool ArrayList<E>::empty(void) const { return (list_size == 0); }

template <typename E>
const E& ArrayList<E>::front(void) const
{
    if (list_size == 0)
    {
        throw std::out_of_range("List is empty");
    }

    return (arr[0]);
}

template <typename E>
const E& ArrayList<E>::back(void) const
{
    if (list_size == 0)
    {
        throw std::out_of_range("List is empty");
    }

    return (arr[list_size - 1]);
}

template <typename E>
E ArrayList<E>::pop_back(void)
{
    if (list_size <= 0) { throw std::out_of_range("List is empty"); }
    return arr[--list_size];
}


// operators
template <typename E>
E& ArrayList<E>::operator[](size_t index)
{
    if (index >= list_size)   
    {
        throw std::out_of_range("Index out of List range");
    }

    return arr[index];
}


#endif