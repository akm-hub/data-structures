/** 
 *  @brief      Generic queue data structure implementation
 * 
 *  @author     Ashish
 *  @version    1.0
 *  Copyright (C) 2015 Ashish, MIT license
 * 
 *     TODO         add more constructors,
 *                 provide emplace method,
 *                   provide swap method
 * 
 */

#ifndef _INCLUDE_QUEUE_H_
#define _INCLUDE_QUEUE_H_

#include <deque>

/*
 * @brief  The queue implementation class
 * 
 * It uses an encapsulated object of a specific container class as its 
 * underlying container, providing a specific set of member functions 
 * to access its elements. Elements are pushed into the "back" of the
 * specific container and popped from its "front".
 * The underlying container shall support the following operations:
 *        empty
 *        size
 *        front
 *        back
 *        push_back
 *        pop_front
 * 
 * The suitable standard container classes are: deque and list.
 * 
 * By default, if no container class is specified deque is used.
 */

 ///  Forward declaration of class is required for making 
 ///  operators == and < friends of Queue class
template < typename T, typename Container >
class Queue;

template < typename T, typename Container >
bool operator==(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs);

template < typename T, typename Container >
bool operator<(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs);

template < typename T, typename Container = std::deque<T> >
class Queue {
 private:
    typedef unsigned size_type;
    Container items_;

 public:
    Queue();
    bool empty() const;
    size_type size() const;
    T& front();
    T& back();
    void push(const T& val);
    void pop();

    friend bool operator== <> (const Queue& lhs, const Queue& rhs);
    friend bool operator< <> (const Queue& lhs, const Queue& rhs);
};

/*
 * @brief        Default constructor
 */
template < typename T, typename Container >
Queue<T, Container>::Queue() {
}

/*
 * @brief        Test whether Queue is empty
 * @param        None
 * @return       true if queue empty
 */
template < typename T, typename Container >
bool Queue<T, Container>::empty() const {
    return items_.empty();
}

/*
 * @brief        Get size of queue, i.e. no. of items 
 * @param        None
 * @return       The number of items in the queue
 */
template < typename T, typename Container >
typename Queue<T, Container>::size_type Queue<T, Container>::size() const {
    return items_.size();
}

/*
 * @brief        Access the front item in Queue 
 * @param        None
 * @return       Reference to the front item in Queue
 * @throws       runtime_error - if Queue empty
 */
template < typename T, typename Container >
T& Queue<T, Container>::front() {
    if (items_.empty()) {
        throw std::runtime_error("Queue empty");
    } else {
        return items_.front();
    }
}

/*
 * @brief        Access the back item in Queue 
 * @param        None
 * @return       Reference to the back item in Queue
 * @throws       runtime_error - if Queue empty
 */
template < typename T, typename Container >
T& Queue<T, Container>::back() {
    if (items_.empty()) {
        throw std::runtime_error("Queue empty");
    } else {
        return items_.back();
    }
}

/*
 * @brief        Add a new item at end of Queue 
 * @param        The item
 * @return       Nothing
 */
template < typename T, typename Container >
void Queue<T, Container>::push(const T& val) {
    items_.push_back(val);
}

/*
 * @brief        Delete an item in Queue
 * @param        None
 * @return       Nothing
 * @throws       runtime_error - if Queue empty
 */
template < typename T, typename Container >
void Queue<T, Container>::pop() {
    if (items_.empty()) {
        throw std::runtime_error("Queue empty");
    } else {
        items_.pop_front();
    }
    return;
}

/*
 * @brief        Performs the equality test on operands
 * @param        Two queue objects to be compared
 * @return       true if equal
 */
template < typename T, typename Container >
bool operator==(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return lhs.items_ == rhs.items_;
}

/*
 * @brief        Performs the inequality test on operands
 * @param        Two queue objects to be compared
 * @return       true if unequal
 */
template < typename T, typename Container >
bool operator!=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return !(lhs == rhs);
}

/*
 * @brief        Performs the gretaer than or equal to test on operands
 * @param        Two queue objects to be compared
 * @return       true if left is less than right operand
 */
template < typename T, typename Container >
bool operator<(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return lhs.items_ < rhs.items_;
}

/*
 * @brief        Performs the less than or equal to test on operands
 * @param        Two queue objects to be compared
 * @return       true if left is less than or equal to right operand
 */
template < typename T, typename Container >
bool operator<=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return !(rhs < lhs);  // !(lhs > rhs)
}


/*
 * @brief        Performs the greater than or equal to test on operands
 * @param        Two queue objects to be compared
 * @return       true if left is greater than or equal to right operand
 */
template < typename T, typename Container >
bool operator>=(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return !(lhs < rhs);
}


/*
 * @brief        Performs the greater than test on operands
 * @param        Two queue objects to be compared
 * @return       true if left is greater than right operand
 */
template < typename T, typename Container >
bool operator>(const Queue<T, Container>& lhs, const Queue<T, Container>& rhs) {
    return rhs < lhs;
}


#endif
