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

At the beggining of the program all elements were contained in stack a and stack b was empty and by the end of the program all elements were sorted in ascending order in stack a. The set of integer values could contain both positive and negative values but no duplicate values.

The algorithm I developed worked in the following way:

First, I calculated the average value for the elements in stack a. If the element at the top of a was below the average, I pushed it to the top of b (pb);
if the element was above thr average, I rotated up all elements (ra). If the element was pushed to stack b I would calculate the average again, with the element that remained in stack a.
I repeated this process until there was only one element left in stack a.
The purpose of this process was to leave stack b with an organized tendency, with the lower value element tendentially at the bottom and high value elements tendentially  at the top. This facilitated the next part of the algorithm.
