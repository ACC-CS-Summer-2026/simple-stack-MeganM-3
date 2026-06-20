# Simple Stack
A C++ program that demonstrates abstract data types through a fixed-size
integer stack implementation.

---

## Description
This program implements a stack ADT backed by a static integer array. The
Stack class supports push, pop, peek, and isEmpty operations. Using exception handling, Pop and peek
throw a std::underflow_error when called on an empty stack, which the caller
handles with a try/catch block. The main driver serves as a comprehensive
test bed, testing every operation in every possible state including underflow,
overflow, and normal operation, as well as random testing scaled to the stack
size.

---

## Features
- Stack class backed by a fixed-size static integer array
- Push, pop, peek, and isEmpty operations
- Overflow handled by returning false from push
- Underflow handled by throwing std::underflow_error from pop and peek
- Stack size controlled by a single STACKSIZE define requiring no other changes
- Comprehensive explicit, boundary, and random testing in main

---

## Files
```bash
main.cpp        # Driver: entry point and full test bed for the Stack class
main.h          # Driver header: includes and dependencies for main
stack.cpp       # Stack class implementation
stack.h         # Stack class definition and prototypes
```

---

## Requirements
- Linux operating system
- g++ compiler (C++11 or later)

---

## Building
Compile at the command line using:
```bash
g++ -I ./ *.cpp
```

---

## Usage
Run the program with no arguments:
```bash
./a.out
```

Example output:
```bash
=== Stack Test Suite ===
STACKSIZE: 10

--- Explicit Tests ---

[State: Empty]
isEmpty (expect true): true - PASS
peek on empty (expect underflow_error): PASS - peek on empty stack
pop on empty (expect underflow_error): PASS - pop on empty stack
push(10) on empty (expect true): true - PASS

[State: Normal]
isEmpty (expect false): false - PASS
peek (expect 4): 4 - PASS
pop (expect 4): 4 - PASS
push(999) on normal (expect true): true - PASS

[State: Full]
isEmpty (expect false): false - PASS
peek (expect 9): 9 - PASS
pop (expect 9): 9 - PASS
push on full (expect false/overflow): false - PASS

--- Boundary Tests ---
Push to full (10 items):
  push(0): PASS
  push(1): PASS
  push(2): PASS
  push(3): PASS
  push(4): PASS
  push(5): PASS
  push(6): PASS
  push(7): PASS
  push(8): PASS
  push(9): PASS
Push beyond STACKSIZE (expect false): false - PASS
Pop to empty (10 pops):
  pop (expect 9): 9 PASS
  pop (expect 8): 8 PASS
  pop (expect 7): 7 PASS
  pop (expect 6): 6 PASS
  pop (expect 5): 5 PASS
  pop (expect 4): 4 PASS
  pop (expect 3): 3 PASS
  pop (expect 2): 2 PASS
  pop (expect 1): 1 PASS
  pop (expect 0): 0 PASS
Pop beyond empty (expect underflow_error): PASS - pop on empty stack

--- Random Tests (1000 operations) ---
  Pushes:            253 (overflows: 29)
  Successful pops:   214
  Successful peeks:  191
  isEmpty calls:     258
  Underflows caught: 84
Random testing complete.

=== All Tests Complete ===

```
---

## File Summary
- The Stack class uses a single STACKSIZE define to control array size. Changing
this value requires no other modifications for both the stack and the tests to
work correctly.
- Pop and peek throw std::underflow_error on an empty stack, caught in main
with try/catch blocks during testing.
- All testing is performed in main with no helper functions, covering every
operation in every state.

---

## Acknowledgements
- Developed with assistance from Claude AI

---

## License
This code was created with the intention of completing a college assignment and is not to be shared or reused by others.


