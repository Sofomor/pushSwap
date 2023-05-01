#include "../inc/pushswap.h"

void    indexation(t_stacks *all, int *tmp)
{
    int i;
    int j;
    int min;
    int min_i;
    int ex_min;

    i = 0;
    min = 2147483647;
    ex_min = -2147483648;
    while (i < all->stack_a->current_size)
    {
        j = 0;
        while (j < all->stack_a->current_size)
        {
            if (all->stack_a->nb[j] < min && all->stack_a->nb[j] > ex_min)
            {
                min = all->stack_a->nb[j];
                min_i = j;
            }
            j++;
        }
        ex_min = min;
        min = 2147483647;
        tmp[min_i] = i;
        i++;
    }
    free(all->stack_a->nb);
    all->stack_a->nb = tmp;
}
