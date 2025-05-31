#ifndef STACK_HPP
#define STACK_HPP

#include "./stack_node.hpp"

#include <stdexcept>
#include <utility>


template <typename E>
class Stack
{
private:
    StackNode<E>* top_node;
    int stack_size;

public:
    // constructor / destructor
    Stack(void);
    ~Stack();

    // no return  methods
    void push(const E& it);
    void clear(void);

    // return methods
    E pop(void);
    int size(void) const;
    const E& top(void) const;
};

// definition

// constructor / destructor
template <typename E>
Stack<E>::Stack(void) : top_node(nullptr), stack_size(0) {}

template <typename E>
Stack<E>::~Stack()
{
    if (stack_size > 0) { clear(); }
}


// no return methods
template <typename E>
void Stack<E>::push(const E& it)
{
    StackNode<E>* new_node = new StackNode(it);

    new_node->set_next(top_node);
    top_node = new_node;

    stack_size++;
}

template <typename E>
void Stack<E>::clear(void)
{
    while (stack_size > 0) { pop(); }
}


// return methods
template <typename E>
E Stack<E>::pop(void)
{
    if (stack_size == 0)
    {
        throw std::out_of_range("Stack is empty");
    }
    
    StackNode<E>* temp = top_node;
    E popped_value = std::move(temp->get_value());

    top_node = top_node->get_next();
    delete temp;
    stack_size--;

    return popped_value;
}

template <typename E>
int Stack<E>::size(void) const { return stack_size; }

template <typename E>
const E& Stack<E>::top(void) const
{
    if (stack_size > 0)
    {
        return top_node->get_value();
    }

    throw std::out_of_range("Stack is empty");
}


#endif