#include "push_swap.h"

void    sort_3(t_list **lst)
{
    if ((*lst)->value > (*lst)->next->value)
        swap(*lst);
    if ((*lst)->next->value > (*lst)->value && (*lst)->next->value > (*lst)->next->next->value)
        rev_rotate(lst);
    if ((*lst)->value > (*lst)->next->value)
        swap(*lst);
}

void    sort(t_list **a, t_list **b)
{
    int pos;
    int n;

    n = 0;
    while (lst_size((*a)) > 1)
    {
        /* if (n > lst_size(*a))
            push(a, b); */
        if ((*a)->value <= lst_average(*a))
        {
            push(a, b);
            n = 0;
        }
        else
        {
            rotate(a);
            n++;
        }
    }
    //sort_3(a);
    while (*b)
    {
        //lst_print(*b);
        pos = ft_cost(*b, (*a)->value);
        //printf("pos: %d\n", pos);
        //printf("\n");
        if (pos <= lst_size((*b)) / 2)
        {
            //printf("menor\n");
            while (pos > 0)
            {
                rotate(b);
                pos--;
            }
        }
        else if (pos > lst_size((*b)) / 2)
        {
            //printf("maior\n");
            pos = lst_size((*b)) - pos;
            //printf("pos: %d\n", pos);
            while (pos > 0)
            {
                rev_rotate(b);
                pos--;
            }
        }
        //printf("\n");
        push(b, a);
    }
}

int ft_cost(t_list *b, int top)
{
    int pos;
    int n;
    int dif;

    dif = top - b->value;
    n = 0;
    pos = 0;
    while (b)
    {
        if (top - b->value < dif)
        {
            dif = top - b->value;
            pos = n;
        }
        b = b->next;
        n++;
    }
    return (pos);
}