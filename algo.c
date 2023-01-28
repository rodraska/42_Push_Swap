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
    
    while (lst_size((*a)) > 3)
    {
        if ((*a)->value <= lst_average(*a))
            push(a, b);
        else
        {
            printf("ola");
            rotate(a);
        }
            
    }
    sort_3(a);
    while (*b)
    {
        pos = ft_cost(*b, (*a)->value);
        if (pos <= lst_size((*b)) / 2)
        {
            while (pos > 0)
            {
                rotate(b);
                pos--;
            }
        }
        else if (pos > lst_size((*b)) / 2)
        {
            pos = lst_size((*b)) - pos + 1;
            while (pos > 0)
            {
                rev_rotate(b);
                pos--;
            }
        }
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
            pos = n;
        b = b->next;
        n++;
    }
    return (pos);
}