
*This project has been created as part of the 42 curriculum by fr3khol.*

# Push_swap

## Description
**Push_swap** is a highly structured algorithmic project at 42 that requires sorting data in a stack. You have at your disposal a set of integer values, two stacks (`a` and `b`), and a limited set of instructions to manipulate both stacks. The goal is to write a C program that calculates and displays the shortest sequence of instructions needed to sort the given integers in ascending order. This project introduces the concept of algorithm complexity and requires choosing the most appropriate sorting algorithm to achieve the lowest possible number of actions.

## Instructions

### Compilation
To compile the project, a `Makefile` is provided. You can compile the program using the standard `make` command, which will compile the source files without unnecessary relinking:

```bash
make
```
This will generate the `push_swap` executable.

### Execution
After compiling, run the executable with a list of integers as arguments. The first argument provided will be at the top of stack `a`:

```bash
./push_swap 2 1 3 6 5 8
```

The program will output the sequence of operations separated by a newline (`\n`) to sort the stack. 
If no parameters are specified, the program will not display anything and will return to the prompt. In case of an error (e.g., non-integer arguments, arguments exceeding integer limits, or duplicates), it will display "Error" on the standard error output.

### Operations
The allowed operations to manipulate the stacks are:
* **sa / sb / ss**: Swap the first 2 elements at the top of stack a / b / both.
* **pa / pb**: Take the first element at the top of one stack and push it to the top of the other.
* **ra / rb / rr**: Shift up all elements of stack a / b / both by 1 (the first element becomes the last).
* **rra / rrb / rrr**: Shift down all elements of stack a / b / both by 1 (the last element becomes the first).

### Resources
* **Manuals**: `man malloc`, `man free`, `man write`, `man read`, `man exit`.
* **AI Usage**: AI tools were used in this project only for understanding some concepts and for testing the program against edge cases.
