/** 
 *  @brief      Generic stack data structure implementation
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

#ifndef _INCLUDE_STACK_H
#define _INCLUDE_STACK_H_

#include <deque>

/*
 * @brief  The stack implementation class
 * 
 * It uses an encapsulated object of a specific container class as its 
 * underlying container, providing a specific set of member functions 
 * to access its elements. Elements are pushed/popped from the "back" 
 * of the specific container, which is known as the top of the stack. 
 * The underlying container shall support the following operations:
 *        empty
 *        size
 *        back
 *        push_back
 *        pop_back
 * 
 * The suitable standard container classes are: vector, deque and list.
 * 
 * By default, if no container class is specified deque is used.
 */

template < typename T, typename Container >
class Stack;

template < typename T, typename Container >
bool operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs);

template < typename T, typename Container >
bool operator<(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs);

template < typename T, typename Container = std::deque<T> >
class Stack {
 private:
    typedef unsigned size_type;
    Container items_;

 public:
    Stack();
    bool empty() const;
    size_type size() const;
    T& top();
    void push(const T& val);
    void pop();

    friend bool operator== <>(const Stack& lhs, const Stack& rhs);
    friend bool operator< <>(const Stack& lhs, const Stack& rhs);
};

/*
 * @brief    Default constructor
 */
template < typename T, typename Container >
Stack<T, Container>::Stack() {
}

/*
 * @brief    Test whether stack is empty
 * @param     None
 * @return   true if stack empty
 */
template < typename T, typename Container >
bool Stack<T, Container>::empty() const {
    return items_.empty();
}

/*
 * @brief        Get size of stack, i.e. no. of items 
 * @param         None
 * @return         The number of items in the stack
 */
template < typename T, typename Container >
typename Stack<T, Container>::size_type Stack<T, Container>::size() const {
    return items_.size();
}

/*
 * @brief        Access the top item in stack 
 * @param         None
 * @return         Reference to the top item in stack
 * @throws      runtime_error - if stack empty
 */
template < typename T, typename Container >
T& Stack<T, Container>::top() {
    if (items_.empty()) {
        throw std::runtime_error("Stack empty");
    } else {
        return items_.back();
    }
}

/*
 * @brief        Add a new item at top of stack 
 * @param         The item
 * @return         Nothing
 */
template < typename T, typename Container >
void Stack<T, Container>::push(const T& val) {
    items_.push_back(val);
}

/*
 * @brief        Delete a new item in stack
 * @param         None
 * @return         Nothing
 * @throws      runtime_error - if stack empty
 */
template < typename T, typename Container >
void Stack<T, Container>::pop() {
    if (empty()) {
        throw std::runtime_error("Stack empty");
    } else {
        items_.pop_back();
    }
    return;
}

/*
 * @brief        Performs the equality test on operands
 * @param         Two stack objects to be compared
 * @return         true if equal
 */
template < typename T, typename Container >
bool operator==(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return lhs.items_ == rhs.items_;
}

/*
 * @brief        Performs the inequality test on operands
 * @param         Two stack objects to be compared
 * @return         true if unequal
 */
template < typename T, typename Container >
bool operator!=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return !(lhs == rhs);
}

/*
 * @brief        Performs the gretaer than or equal to test on operands
 * @param         Two stack objects to be compared
 * @return         true if left is less than right operand
 */
template < typename T, typename Container >
bool operator<(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return lhs.items_ < rhs.items_;
}

/*
 * @brief        Performs the less than or equal to test on operands
 * @param         Two stack objects to be compared
 * @return         true if left is less than or equal to right operand
 */
template < typename T, typename Container >
bool operator<=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return !(rhs < lhs);  // !(lhs > rhs)
}


/*
 * @brief        Performs the greater than or equal to test on operands
 * @param         Two stack objects to be compared
 * @return         true if left is greater than or equal to right operand
 */
template < typename T, typename Container >
bool operator>=(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return !(lhs < rhs);
}


/*
 * @brief        Performs the gretaer than or equal to test on operands
 * @param         Two stack objects to be compared
 * @return         true if left is greater than right operand
 */
template < typename T, typename Container >
bool operator>(const Stack<T, Container>& lhs, const Stack<T, Container>& rhs) {
    return rhs < lhs;
}



#endif
