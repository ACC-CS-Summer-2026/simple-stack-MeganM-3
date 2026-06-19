/* *************************************************
 * Name: Megan Triesch
 * Assignment: Assignment 4
 * Purpose: Create and define 'stack' data structure class.
 ************************************************* */
 
 #ifndef CLASSES_STACK_H
 #define CLASSES_STACK_H 
 
 #define STACKSIZE 10
 
 class Stack {
 
    public:
    /**********************
    Constructors/Destructor
    ***********************/
    Stack();
    ~Stack();

    /**********************
    Getters/Accessors
    ***********************/
    int peek(); // or bool peek(int*); // return the top value
    bool isEmpty(); // test for empty (i.e., top < 0)

    /**********************
    Setters/Mutators
    ***********************/
    int pop(); // or bool pop(int*); // remove and return the top value
    bool push(int); // insert to the top of the stack

    /**********************
    Printing
    ***********************/

protected: // we use protected here to allow access to derived classes
    /**********************
    Methods
    ***********************/

    /**********************
    Attributes
    ***********************/
    int array[STACKSIZE];
    int top;
    
};

#endif //CLASSES_STACK_H
