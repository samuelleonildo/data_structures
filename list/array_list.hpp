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
ArrayList<E>::~ArrayList() { this->clear(); }


// no return methods
template <typename E>
void ArrayList<E>::push_back(const E& it)
{
    if (this->list_size >= this->capacity)
    {
        size_t new_capacity = (this->capacity == 0) ? 1 : (this->capacity * 2);
        E* new_arr = new E[new_capacity];

        if (this->arr != nullptr)
        {
            std::copy(arr, arr + this->list_size, new_arr);
            delete[] this->arr;
        }
        
        this->arr = new_arr;
        this->capacity = new_capacity;
    }

    this->arr[this->list_size++] = it;
}

template <typename E>
void ArrayList<E>::clear(void)
{
    if (this->arr != nullptr)
    {
        delete[] this->arr;
        this->arr = nullptr;

        this->list_size = 0;
        this->capacity = 0;
    }
}


// return methods
template <typename E>
size_t ArrayList<E>::size(void) const { return this->list_size; }

template <typename E>
bool ArrayList<E>::empty(void) const { return (this->list_size == 0); }

template <typename E>
const E& ArrayList<E>::front(void) const
{
    if (this->list_size == 0)
    {
        throw std::out_of_range("List is empty");
    }

    return (this->arr[0]);
}

template <typename E>
const E& ArrayList<E>::back(void) const
{
    if (this->list_size == 0)
    {
        throw std::out_of_range("List is empty");
    }

    return (this->arr[this->list_size - 1]);
}

template <typename E>
E ArrayList<E>::pop_back(void)
{
    if (this->list_size <= 0) { throw std::out_of_range("List is empty"); }
    return this->arr[--this->list_size];
}


// operators
template <typename E>
E& ArrayList<E>::operator[](size_t index)
{
    if (index >= this->list_size)   
    {
        throw std::out_of_range("Index out of List range");
    }

    return this->arr[index];
}


#endif