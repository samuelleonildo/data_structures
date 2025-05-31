#ifndef STACK_NODE_HPP
#define STACK_NODE_HPP

template <typename E>
class StackNode
{
private:
    StackNode<E>* next;
    E value;

public:
    // constructor / destructor
    StackNode(const E& _value);
    ~StackNode() = default;

    // no return methods
    void set_next(StackNode<E>* _next);

    // return methods
    StackNode<E>* get_next(void) const;
    const E& get_value(void) const;
};


// definition

// constructor
template <typename E>
StackNode<E>::StackNode(const E& _value) : value(_value), next(nullptr) {}

// no return methods
template <typename E>
void StackNode<E>::set_next(StackNode<E>* _next) { next = _next; }

// return methods
template <typename E>
StackNode<E>* StackNode<E>::get_next(void) const { return next; }

template <typename E>
const E& StackNode<E>::get_value(void) const { return value; }


#endif