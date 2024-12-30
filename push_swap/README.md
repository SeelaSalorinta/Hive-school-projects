7th project

You have 2 stacks named a and b.
At the beginning: The stack a contains a random amount of negative and/or positive numbers without duplicates.
The stack b is empty. The first argument should be at the top of the stack.

The goal is to sort in ascending order numbers into stack with the lowest possible number of operations.
Using following operations:
sa (swap a): Swap the first 2 elements at the top of stack a.
sb (swap b): Swap the first 2 elements at the top of stack b.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
pb (push b): Take the first element at the top of a and put it at the top of b.
ra (rotate a): Shift up all elements of stack a by 1. The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1. The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1. The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1. The last element becomes the first one.
rrr : rra and rrb at the same time.

The program must display the smallest list of instructions possible to sort the stack
a, the smallest number being at the top.
Instructions must be separated by a ’\n’ and nothing else.

We had a checker to use to check if the operations the program outputs sorts the stack.
For maximum points:
100 random numbers needed to be sorted 700 operations or less.
500 random numbers needed to be sorted 5500 operations or less.
