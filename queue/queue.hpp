#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_


#include "./queue_node.hpp"

#include <stdexcept>


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
    void dequeue(void);
    void clear(void);

    // return methods
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
    if (this->queue_size > 0) { this->clear(); }
}


// no return methods
template <typename E>
void Queue<E>::enqueue(const E& it)
{
    QueueNode<E>* new_node = new QueueNode<E>(it);

    if (this->queue_size == 0)
    {
        this->first_node = new_node;
        this->rear = new_node;
    }
    else
    {
        this->rear->set_next(new_node);
        this->rear = this->rear->get_next();
    }

    this->queue_size++;
}

template <typename E>
void Queue<E>::dequeue(void)
{
    if (this->queue_size > 0)
    {
        QueueNode<E>* temp = this->first_node;
        this->first_node = this->first_node->get_next();
        delete temp;

        this->queue_size--;

        if (this->queue_size == 0) { this->rear = nullptr; }
    }
}

template <typename E>
void Queue<E>::clear(void)
{
    while (this->queue_size > 0) { this->dequeue(); }
}


// return methods
template <typename E>
int Queue<E>::size(void) const { return this->queue_size; }

template <typename E>
const E& Queue<E>::front(void) const
{
    if (this->queue_size > 0)
    {
        return this->first_node->get_value();
    }
    
    throw std::out_of_range("Queue is empty");
}


#endif