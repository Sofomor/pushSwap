#include "../inc/pushswap.h"

int find_max(t_stacks *all)
{
    int i;
    int max;
    int ret;

    i = 0;
    ret = 0;
    max = all->stack_a->nb[0];
    while (i++ < all->stack_a->current_size - 1)
    {
        if (all->stack_a->nb[i] > max)
        {
            max = all->stack_a->nb[i];
            ret = i;
        }
    }
    return (ret);
}

void    selection_sort(t_stacks *all)
{
    int i;
    int m;

    i = 0;
    m = find_max(all);
    if (m < (all->stack_b->current_size - 1) / 2)
        while (i++ < m)
            rb(all);
    else
        while (i++ != all->stack_b->current_size - m)
            rrb(all);
    pa(all);
}

void    push_chunk(t_stacks *all)
{
    int pivot;
    int i = 0;

    pivot = all->stack_a->nb[0];
    while (i < all->stack_a->current_size)
    {
        if (all->stack_a->nb[i] <= pivot)
            pb(all);
        else
            ra(all);
        i++;
    }
}

void    test_sort(t_stacks *all)
{
    while (all->stack_a->current_size)
        push_chunk(all);
    while (all->stack_b->current_size)
	    selection_sort(all);
}

/*
void	radix_sort(t_stacks *all, int max_bits)
{
	int	i;
	int	j;
	int	num;

	i = -1;
	while (((all->max_size - 1) >> max_bits) != 0)
		++max_bits;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < all->max_size)
		{
			num = all->stack_a->nb[0];
			if (((num >> i) & 1) == 1)
				ra(all);
			else
				pb(all);
		}
		while (all->stack_b->current_size)
			pa(all);
	}
	if (all->stack_a->nb[0] > all->stack_a->nb[all->stack_a->current_size - 1])
		ra(all);
}*/