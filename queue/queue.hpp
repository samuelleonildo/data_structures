#ifndef QUEUE_HPP
#define QUEUE_HPP


#include "./queue_node.hpp"

#include <stdexcept>
#include <utility>


template <typename E>
class Queue
{
private:
    QueueNode<E>* first_node;
    QueueNode<E>* rear;
    int queue_size;

public:
    // constructor / destructor
    Queue(void);
    ~Queue();

    // no-return methods
    void enqueue(const E& it);
    void clear(void);

    // return methods
    E dequeue(void);
    int size(void) const;
    const E& front(void) const;
};


// queue def below

// constructor / destructor
template <typename E>
Queue<E>::Queue(void) : queue_size(0), first_node(nullptr), rear(nullptr) {}

template <typename E>
Queue<E>::~Queue()
{
    if (queue_size > 0) { clear(); }
}


// no return methods
template <typename E>
void Queue<E>::enqueue(const E& it)
{
    QueueNode<E>* new_node = new QueueNode<E>(it);

    if (queue_size == 0)
    {
        first_node = new_node;
        rear = new_node;
    }
    else
    {
        rear->set_next(new_node);
        rear = rear->get_next();
    }

    queue_size++;
}

template <typename E>
void Queue<E>::clear(void)
{
    while (queue_size > 0) { dequeue(); }
}


// return methods
template <typename E>
E Queue<E>::dequeue(void)
{
    if (queue_size == 0)
    {
        throw std::out_of_range("Queue is empty");
    }

    QueueNode<E>* temp = first_node;
    E dequeued_value = std::move(temp->get_value());

    first_node = first_node->get_next();
    delete temp;
    queue_size--;

    if (queue_size == 0) { rear = nullptr; }

    return dequeued_value;
}

template <typename E>
int Queue<E>::size(void) const { return queue_size; }

template <typename E>
const E& Queue<E>::front(void) const
{
    if (queue_size > 0)
    {
        return first_node->get_value();
    }
    
    throw std::out_of_range("Queue is empty");
}


#endif