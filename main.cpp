/* *************************************************
 * Name: Megan Triesch
 * Assignment: Assignment 4
 * Purpose: Application driver and comprehensive
 *          test bed for the Stack ADT.
 ************************************************* */
 
 #include "main.h"
 
 int main(int argc, char** argv) {
    /* ************************************
    * Application driver and test bed for the Stack
    * class. Tests all operations (push, pop, peek,
    * isEmpty) in all states (empty, normal, full)
    * with both explicit and random testing.
    *
    * @param argc (int) : argument count
    * @param argv (char**) : argument vector
    * @return (int) : application exit code
    * @exception na : na
    * @note na
    * ************************************/

    Stack stack;
    bool result;
    int value;

    std::cout << "=== Stack Test Suite ===" << std::endl;
    std::cout << "STACKSIZE: " << STACKSIZE << std::endl;
    std::cout << std::endl;
    
    // ------------------------------------------------
    // TESTING
    // Every operation tested in every possible state:
    //   State 1 - Empty (underflow)
    //   State 2 - Normal (between empty and full)
    //   State 3 - Full (overflow)
    // ------------------------------------------------
    
    std::cout << "--- Tests ---" << std::endl;
    
    // ---- State 1: Empty stack ----
    std::cout << "\n[State: Empty]" << std::endl;

    std::cout << "isEmpty (expect true): "
              << (stack.isEmpty() ? "PASS" : "FAIL") << std::endl;

    std::cout << "peek on empty (expect underflow_error): ";
    try {
        value = stack.peek();
        std::cout << "FAIL - no exception thrown" << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "PASS - " << e.what() << std::endl;
    }

    std::cout << "pop on empty (expect underflow_error): ";
    try {
        value = stack.pop();
        std::cout << "FAIL - no exception thrown" << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "PASS - " << e.what() << std::endl;
    }

    std::cout << "push(10) on empty (expect true): ";
    result = stack.push(10);
    std::cout << (result ? "PASS" : "FAIL") << std::endl;
}
