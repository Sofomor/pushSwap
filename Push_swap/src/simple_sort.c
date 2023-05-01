#include "../inc/pushswap.h"

int    find_min(t_stacks *all)
{
    unsigned int i = 0;
    int min = all->stack_a->nb[0];
    while (i < all->stack_a->current_size)
    {
        if (all->stack_a->nb[i] < min)
            min = all->stack_a->nb[i];
        i++;
    }
    return (min);
}

void test_chunk(t_stacks *all, int pivot, int pivot2)
{
    unsigned int i = 0;
    while (i < all->stack_a->current_size)
    {
        if (all->stack_a->nb[0] <= pivot)
        {
            pb(all);
            if (all->stack_b->current_size > 1 && all->stack_b->nb[0] < pivot2)
                rb(all);
        }
        else
            ra(all);
        i++;
    }
}

unsigned int    find_max_i(t_stacks *all)
{
    unsigned int i = 0;
    unsigned int    ret = 0;
    int max = all->stack_b->nb[0];
    while (i < all->stack_b->current_size)
    {
        if (all->stack_b->nb[i] > max)
        {
            ret = i;
            max = all->stack_b->nb[i];
        }
        i++;
    }
    return (ret);
}

void    selection_sort2(t_stacks *all)
{
    unsigned int    i;
    unsigned int max;

    while (all->stack_b->current_size)
    {
        i = 0;
        max = find_max_i(all);
        if (max < (all->stack_b->current_size - 1) / 2)
            while (i++ < max)
                rb(all);
        else
            while (i++ < all->stack_b->current_size - max)
                rrb(all);
        pa(all);
    }
}

void simple_sort(t_stacks *all)
{
    int min;
    int div;

    while (all->stack_a->current_size)
    {
        min = find_min(all);
        div = (int)((all->stack_a->current_size / 4 + 42) / 2);
        test_chunk(all, min + div, min + (div / 2));
    }
    selection_sort2(all);
}
