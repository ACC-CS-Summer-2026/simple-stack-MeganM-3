/* *************************************************
 * Name: Megan Triesch
 * Assignment: Assignment 4
 * Purpose: Create and define 'stack' data structure 
 *          class.
 ************************************************* */
  
#include "stack.h"

Stack::Stack() {
    /* ************************************
    * Constructs an empty Stack. Every slot in
    * array is initialized to 0 to avoid garbage
    * memory. top is set to -1 to indicate the
    * stack is empty.
    *
    * @param na : na
    * @return na : na
    * @exception na : na
    * @note na
    * ************************************/
    for (int i = 0; i < STACKSIZE; i++) {
        array[i] = 0;
    }
    top = -1;
}

Stack::~Stack() {
    /* ************************************
    * Destroys a Stack. No dynamic memory was
    * allocated, so nothing to release.
    *
    * @param na : na
    * @return na : na
    * @exception na : na
    * @note na
    * ************************************/
}

int Stack::pop() {
    /* ************************************
    * Removes and returns the top value. Resets
    * the vacated slot to 0.
    *
    * @param na : na
    * @return (int) : value removed from top
    * @exception std::underflow_error : thrown if stack is empty
    * @note na
    * ************************************/
    if (top < 0) {
        throw std::underflow_error("pop on empty stack");
    }
    int value = array[top];
    array[top] = 0;
    top--;
    return value;
}

int Stack::peek() {
    /* ************************************
    * Returns the top value without removing it.
    *
    * @param na : na
    * @return (int) : value at top of stack
    * @exception std::underflow_error : thrown if stack is empty
    * @note na
    * ************************************/
    if (top < 0) {
        throw std::underflow_error("peek on empty stack");
    }
    return array[top];
}

bool Stack::push(int value) {
    /* ************************************
    * Inserts a value at the top of the stack.
    * Returns false without modifying the stack
    * if it is already full.
    *
    * @param value (int) : integer to push
    * @return (bool) : true if successful, false on overflow
    * @exception na : na
    * @note na
    * ************************************/
    bool success = false;
    if (top < STACKSIZE - 1) {
        top++;
        array[top] = value;
        success = true;
    }
    return success;
}

bool Stack::isEmpty() {
    /* ************************************
    * Tests whether the stack contains no elements.
    *
    * @param na : na
    * @return (bool) : true if empty, false otherwise
    * @exception na : na
    * @note na
    * ************************************/
    return (top < 0);
}
