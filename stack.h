/* *************************************************
 * Name: Megan Triesch
 * Assignment: Assignment 4
 * Purpose: Create and define 'stack' data structure class.
 ************************************************* */
 
 #ifndef CLASSES_STACK_H
 #define CLASSES_STACK_H 
 
 class Stack {
 
    public:
    /**********************
    Constructors/Destructor
    ***********************/
    

    /**********************
    Getters/Accessors
    ***********************/
    

    /**********************
    Setters/Mutators
    ***********************/
    

    /**********************
    Printing
    ***********************/

protected: // we use protected here to allow access to derived classes
    /**********************
    Methods
    ***********************/
    int pop(); // or bool pop(int*); // remove and return the top value
    int peek(); // or bool peek(int*); // return the top value
    bool push(int); // insert to the top of the stack
    bool isEmpty(); // test for empty (i.e., top < 0)

    /**********************
    Attributes
    ***********************/
    int array;
    int top;
    
};

#endif //CLASSES_STACK_H
