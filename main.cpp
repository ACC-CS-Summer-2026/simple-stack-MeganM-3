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
    // EXPLICIT TESTING
    // Every operation tested in every possible state:
    //   State 1 - Empty (underflow)
    //   State 2 - Normal (between empty and full)
    //   State 3 - Full (overflow)
    // ------------------------------------------------
    
    std::cout << "--- Explicit Tests ---" << std::endl;
    
    // ---- State 1: Empty stack ----
    std::cout << "\n[State: Empty]" << std::endl;

    std::cout << "isEmpty (expect true): "
              << (stack.isEmpty() ? "true" : "false") << " - "
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
    std::cout << (result ? "true" : "false") << " - "
              << (result ? "PASS" : "FAIL") << std::endl;
    
    // ---- State 2: Normal stack (partially filled) ----
    // Reset, then push half-capacity items
    stack = Stack();
    for (int i = 0; i < STACKSIZE / 2; i++) {
        stack.push(i);
    }

    std::cout << "\n[State: Normal]" << std::endl;

    std::cout << "isEmpty (expect false): "
              << (stack.isEmpty() ? "true" : "false") << " - "
              << (!stack.isEmpty() ? "PASS" : "FAIL") << std::endl;

    std::cout << "peek (expect "
              << (STACKSIZE / 2 - 1) << "): ";
    try {
        value = stack.peek();
        std::cout << value << " - "
                  << (value == (STACKSIZE / 2 - 1) ? "PASS" : "FAIL")
                  << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "FAIL - " << e.what() << std::endl;
    }

    std::cout << "pop (expect "
              << (STACKSIZE / 2 - 1) << "): ";
    try {
        value = stack.pop();
        std::cout << value << " - "
                  << (value == (STACKSIZE / 2 - 1) ? "PASS" : "FAIL")
                  << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "FAIL - " << e.what() << std::endl;
    }

    std::cout << "push(999) on normal (expect true): ";
    result = stack.push(999);
    std::cout << (result ? "true" : "false") << " - "
              << (result ? "PASS" : "FAIL") << std::endl;
    
    // ---- State 3: Full stack ----
    stack = Stack();
    for (int i = 0; i < STACKSIZE; i++) {
        stack.push(i);
    }

    std::cout << "\n[State: Full]" << std::endl;

    std::cout << "isEmpty (expect false): "
              << (stack.isEmpty() ? "true" : "false") << " - "
              << (!stack.isEmpty() ? "PASS" : "FAIL") << std::endl;

    std::cout << "peek (expect "
              << (STACKSIZE - 1) << "): ";
    try {
        value = stack.peek();
        std::cout << value << " - "
                  << (value == (STACKSIZE - 1) ? "PASS" : "FAIL")
                  << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "FAIL - " << e.what() << std::endl;
    }

    std::cout << "pop (expect "
              << (STACKSIZE - 1) << "): ";
    try {
        value = stack.pop();
        std::cout << value << " - "
                  << (value == (STACKSIZE - 1) ? "PASS" : "FAIL")
                  << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "FAIL - " << e.what() << std::endl;
    }

    std::cout << "push on full (expect false/overflow): ";
    stack = Stack();
    for (int i = 0; i < STACKSIZE; i++) {
        stack.push(i);
    }
    result = stack.push(9999);
    std::cout << (result ? "true" : "false") << " - "
              //!result because false is a PASS in this case
              << (!result ? "PASS" : "FAIL") << std::endl;

    // ------------------------------------------------
    // BOUNDARY TESTING
    // Push exactly to capacity, then one more.
    // Pop down to empty, then one more.
    // ------------------------------------------------
    std::cout << "\n--- Boundary Tests ---" << std::endl;

    stack = Stack();
    std::cout << "Push to full (" << STACKSIZE << " items):" << std::endl;
    for (int i = 0; i < STACKSIZE; i++) {
        result = stack.push(i);
        std::cout << "  push(" << i << "): "
                  << (result ? "PASS" : "FAIL") << std::endl;
    }

    std::cout << "Push beyond STACKSIZE (expect false): ";
    result = stack.push(9999);
    std::cout << (result ? "true" : "false") << " - "
              //!result because false is a PASS in this case
              << (!result ? "PASS" : "FAIL") << std::endl;

    std::cout << "Pop to empty (" << STACKSIZE << " pops):" << std::endl;
    for (int i = STACKSIZE - 1; i >= 0; i--) {
        try {
            value = stack.pop();
            std::cout << "  pop (expect " << i << "): " << value
                      << (value == i ? " PASS" : " FAIL") << std::endl;
        } catch (std::underflow_error& e) {
            std::cout << "  FAIL - " << e.what() << std::endl;
        }
    }

    std::cout << "Pop beyond empty (expect underflow_error): ";
    try {
        value = stack.pop();
        std::cout << "FAIL - no exception" << std::endl;
    } catch (std::underflow_error& e) {
        std::cout << "PASS - " << e.what() << std::endl;
    }

    // ------------------------------------------------
    // RANDOM TESTING
    // STACKSIZE * 100 random operations across all
    // four methods. Count outcomes to verify coverage.
    // ------------------------------------------------
    int totalOps = STACKSIZE * 100;
    std::cout << "\n--- Random Tests (" << totalOps
              << " operations) ---" << std::endl;

    srand(time(0));
    stack = Stack();

    int pushCount    = 0;
    int popCount     = 0;
    int peekCount    = 0;
    int isEmptyCount = 0;
    int overflows    = 0;
    int underflows   = 0;

    for (int i = 0; i < totalOps; i++) {
        int op = rand() % 4;
        if (op == 0) {
            result = stack.push(rand() % 1000);
            pushCount++;
            if (!result) {
                overflows++;
            }
        } else if (op == 1) {
            try {
                value = stack.pop();
                popCount++;
            } catch (std::underflow_error& e) {
                underflows++;
            }
        } else if (op == 2) {
            try {
                value = stack.peek();
                peekCount++;
            } catch (std::underflow_error& e) {
                underflows++;
            }
        } else {
            stack.isEmpty();
            isEmptyCount++;
        }
    }

    std::cout << "  Pushes:            " << pushCount
              << " (overflows: " << overflows << ")" << std::endl;
    std::cout << "  Successful pops:   " << popCount << std::endl;
    std::cout << "  Successful peeks:  " << peekCount << std::endl;
    std::cout << "  isEmpty calls:     " << isEmptyCount << std::endl;
    std::cout << "  Underflows caught: " << underflows << std::endl;
    std::cout << "Random testing complete." << std::endl;

    std::cout << "\n=== All Tests Complete ===" << std::endl;

    return 0;
}
