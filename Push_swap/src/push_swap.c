/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:14:47 by imorina           #+#    #+#             */
/*   Updated: 2022/07/17 20:40:11 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

void    print_stack(t_bucket *a, t_bucket *b, int size)
{
    int    i;

    i = 0;
    printf("\n\e[1;32mA\e[0m             \e[1;31mB          \n\e[0m");
    printf("-             -          \n");
    while (i < size)
    {
        if (i < a->current_size)
            printf("\e[0;32m%-14d\e[0m", a->nb[i]);
        else
            printf("              ");
        if (i < b->current_size)
            printf("\e[0;31m%-11d\e[0m\n", b->nb[i]);
        else
            printf("           \n");
        i++;
    }
    printf("-             -          \n");
}

void	array_atoi(t_stacks *all, char **argv)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (argv[j])
	{
		all->stack_a->nb[i] = ft_atoi(argv[j]);
		i++;
		j++;
	}
}

void	single_arg_atoi(t_stacks *all, char *argv)
{
	int		i;
	char	**tmp;

	i = 0;
	tmp = ft_split(argv, ' ');
	//printf("test\n");
	while (tmp[i])
	{
		all->stack_a->nb[i] = ft_atoi(tmp[i]);
		i++;
	}
}

void	push_swap(t_stacks *all)
{
	if (is_args_sorted(all))
		return;
	else
	{
		if (all->stack_a->current_size == 2)
		{
			//printf("J'entre dans sort 2\n");
			sa(all);
		}
		else if (all->stack_a->current_size == 3)
		{
			//printf("J'entre dans sort 3\n");
			sort_3_elem(all);
		}	
		else if (all->stack_a->current_size > 3 && all->stack_a->current_size < 6)
		{
			//printf("J'entre dans sort 5\n");
			sort_5_elem(all);
		}
		else
			//test_sort(all);
			simple_sort(all);
			//radix_sort(all, 1);
	}
}

int	main(int argc, char **argv)
{
	t_stacks all;
	int	*tmp;

	if (argc < 2)
		handle_error("+ d'arguments mec.");
	else if (argc == 2)
	{
		is_args_nb(argv);
		init_struct(&all, count_words(argv[1], ' '));
		single_arg_atoi(&all, argv[1]);
	}
	else
	{
		init_struct(&all, argc - 1);
		array_atoi(&all, argv);
	}
	tmp = malloc(all.max_size * sizeof(int));
	//print_stack(all.stack_a, all.stack_b, all.max_size);
	indexation(&all, tmp);
	push_swap(&all);
	print_stack(all.stack_a, all.stack_b, all.max_size);
	return (0);
}


// 1. verifier les leaks (free + double free)
// 2. verifier la longueur des fonctions [casse pas tt stp]
// 3. verifier int max int min : print error
// 4. verifier les doublons : print error
// 5. norminer
// 6. relire le sujet
// 7. commenter
// 8. comprendre le code
// 9. tout savoir reecrire
// 10. faire un nouveau push_swap
// 11. inventer un algorithme meilleur que tous ceux qui existent deja
// 12. apprendre à coder
// 13. buter hermes
// 14. trouver un remplaçant sur superprof.com
// 15. le sequestrer (hermes)
// 16. faire des incantations malefiques sur sa sepulture
// 17. faire 150%
