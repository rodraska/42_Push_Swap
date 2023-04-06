42_Push_Swap is a project developed in C for 42 School.

Its objective was to develop a sorting algorithm to sort a set of integer values using the minimum number of moves possible.
We had at our disposal 2 stacks and a set of moves to manipulate both stacks. The moves were the following:

- sa (swap a): Swap the first 2 elements on top of stack a.
- sb (swap b): Swap the first 2 elements on top of stack b.
- ss : sa & sb at the same time.
- pa (push a): Push the first element on top b to the top of a.
- pb (push b): Push the first element on top a to the top of b.
- ra (rotate a): Shift up all elements on stack a. first element becomes last.
- rb (rotate b): Shift up all elements on stack b. first element becomes last.
- rr : ra & rb at the same time.
- rra (reverse rotate a): Shift down all elements on stack a. last element becomes first.
- rrb (reverse rotate b): Shift down all elements on stack b. last element becomes first.
- rrr : rra & rrb at the same time.

