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

At the beggining of the program all elements are contained in stack a and stack b is empty and by the end of the program all elements are sorted in ascending order in stack a. The set of integer values could contain both positive and negative values but no duplicate values.

The algorithm I developed works in the following way:

First, I calculate the average value for the elements in stack a. If the element at the top of a is below the average, I push it to the top of b (pb);
if the element is above the average, I rotate up all elements (ra). If the element is pushed to stack b I calculate the average again, with the elements that remain in stack a.
I repeat this process until there is only one element left in stack a.
The purpose of this process is to leave stack b with an organized tendency, with the lower value element tendentially at the bottom and high value elements tendentially  at the top. This facilitates the next part of the algorithm.

After having the stack b filled, I proceed to pass them again to stack a, in their right order, using a cost function. Each element in stack b has a cost associated with it to pass it to stack a.
The cost is the number of moves needed to bring the element to the top of stack b plus the number of moves needed to bring its best neighour (the element in stack a lower and closest in value to the element of stack b) to the top of stack a.
The cost is calculated for all elements of stack b, and the element with the lower cost is pushed to the top of stack a. The costs are recalculated every time an element is pushed from stack b to stack a. After all elements are passed from stack b to stack a, the element with the lowest value is brought to the top of stack a.
This leaves all the elements in stack a, organized in ascending order.
