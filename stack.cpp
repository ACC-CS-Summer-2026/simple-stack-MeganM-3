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

