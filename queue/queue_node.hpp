#ifndef _QUEUE_NODE_HPP_
#define _QUEUE_NODE_HPP_


template <typename E>
class QueueNode
{
private:
    QueueNode<E>* next;
    E value;

public:
    QueueNode(const E& _value);
    ~QueueNode() = default;

    // no return methods
    void set_next(QueueNode<E>* _next);

    // return methods
    QueueNode<E>* get_next(void) const;
    const E& get_value(void) const;
};


// queue_node definition

// constructor
template <typename E>
QueueNode<E>::QueueNode(const E& _value) : value(_value), next(nullptr) {}


// no return methods
template <typename E>
void QueueNode<E>::set_next(QueueNode<E>* _next) { this->next = _next; }


// return methods
template <typename E>
QueueNode<E>* QueueNode<E>::get_next(void) const { return this->next; }

template <typename E>
const E& QueueNode<E>::get_value(void) const { return this->value; }


#endif