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