/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 03:06:25 by imorina           #+#    #+#             */
/*   Updated: 2022/07/17 20:40:09 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/pushswap.h"

// void    sort_3_elem(t_stacks *all)
// {
//     //int first;
//     //int second;
//     //int last;

//     //first = all->stack_a->nb[0];
//     //second = all->stack_a->nb[1];
//     //last = all->stack_a->nb[2];

//     if (all->stack_a->nb[0] > all->stack_a->nb[1] && all->stack_a->nb[0] > all->stack_a->nb[2])
//         ra(all);
//     else if (all->stack_a->nb[1] > all->stack_a->nb[0] && all->stack_a->nb[1] > all->stack_a->nb[2])
//         rra(all);
//     if (all->stack_a->nb[1] > all->stack_a->nb[0])
//         sa(all);
//     /*
//     if (second < first && first < last)
// 		sa(all);
// 	else if (first < second && first > last)
// 		rra(all);
// 	else if (first > second && first > last && second < last)
// 		ra(all);
// 	else if (first > second && second > last)
// 	{ 
// 		sa(all);
// 	}
// 	else if (first < second && second > last)
// 	{
// 		sa(all);
// 		ra(all);
// 	}*/
// }

void    sort_3_elem(t_stacks *all)
{
     if (all->stack_a->nb[0] > all->stack_a->nb[1] && all->stack_a->nb[0] > all->stack_a->nb[2])
        ra(all);
    else if (all->stack_a->nb[1] > all->stack_a->nb[0] && all->stack_a->nb[1] > all->stack_a->nb[2])
        rra(all);
    if (all->stack_a->nb[0] > all->stack_a->nb[1])
        sa(all);
}




int min_size(t_stacks *all)
{
    int min_size;
    int i;

    i = 0;
    min_size = all->stack_a->nb[0];
    while (i++ < all->stack_a->current_size - 1)
        if (all->stack_a->nb[i] < min_size)
            min_size = all->stack_a->nb[i];
    return (min_size);
}
/*
void    sort_5_elem(t_stacks *all) //THE BEST
{
    int min;
    int first;
    int last;
    int max;

    while (all->stack_a->current_size > 3)
    {
        max = max_size(all);
        min = min_size(all);
        first = all->stack_a->nb[0];
        last = all->stack_a->nb[4];
        if (last == min)
            rra(all);
        if (first == min)
            pb(all);
        else
            ra(all);
    }
    sort_3_elem(all);
    while (all->stack_b->current_size)
        pa(all);
}*/

void    sort_5_elem(t_stacks *all) //THE BEST
{
    int min;

    while (all->stack_a->current_size > 3)
    {
        min = min_size(all);
        while (all->stack_a->nb[0] != min)
        {
            if ((all->stack_a->current_size == 5 && all->stack_a->nb[4] == min) || all->stack_a->nb[3] == min)
                rra(all);
            else
                ra(all);
        }
        pb(all);
    }
    sort_3_elem(all);
    if (all->max_size == 5)
        pa(all);
    pa(all);
}

void	ft_swap(int a, int b)
{
	int	swap;

	swap = a;
	a = b;
	b = swap;
}
/*
void    radix_sort(t_stacks *all)
{
	int i;
    int min;

    i = 0;
    min = all->stack_a->nb[0];
    while (++i < all->stack_a->current_size - 1)
    {
        if (all->stack_a->nb[i] < min)
            min = all->stack_a->nb[i];
    }

}*/

// pb tous les nombres de A du plus petit au plus grand dans B





/* algorithme

idee generale

1. division de groupes de nb :
    1.1 decouper notre stack a en petites portions, il faut que je trie sans louper aucun nombre, des groupes avec une longueur premeditee
2. trier les sous-ensembles
    2.1 une sorte de selection sort : trier de facon a le chercher le plus grand a chaque fois et le mettre a une place (en bas par exemple)
3. implementer l'algorithme avec les commandes et la stack a et b

1 fichier pour la division des groupes
2 fichier trier les sous ensembles
3 fichier implementer l'algo

chunk = groupe de x nombres

*/

// division des groupes
// si je mets 40 nombres dans mon argc, j'aimerais qu'ils soient divisés en 20
// on essaie de diviser par groupes de 3
/*
void    ft_divide_nbrs(t_stacks *all)
{
    int i; // index qui va naviguer a travers la stack_a
    int j; // nombre comparateur
    int x; // nombre qui divise par 2 les groupes

    x = 0;
    j = 0;
    while (i < all->stack_a->nb[current_size])
    {
        x = all->stack_a->nb[current_size] / 2;
        while (j < x)
        {

            j++;
        }
        i++;
    }
    if ()

}*/

//steps    |   1          2            3
//         |
//         |  
//         |
//1 [0]    |      
//2 [1]    |
//3 [2]    |
//4 [3]    |  
//5 [4]    |
//6 [5]    |
//7 [6]    |

//current_size - 1

// j'ai 9 nombres je veux les diviser en groupe de 3

//pb = push stack_a[0] dans stack_b[0]
//pa = push stack_b[0] dans stack_a[0]
/*
void    ft_divide_nbrs(t_stacks *all)
{
    int i;
    int j;
    int temp;

    i = 0;
    temp = 0;
    while (i < all->stack_a->current_size)
    {
        j = i + 1;
        while (j < all->stack_a->current_size)
            {
                if (all->stack_a->nb[i] > all->stack_a->nb[j]){
                temp = all->stack_a->nb[i];
                all->stack_a->nb[i] = all->stack_a->nb[j];
                all->stack_a->nb[j] = temp;
                j++;
            }
        i++;
    }
}*/
/*
int min_size(t_stacks *all)
{
    int min_size;
    int i;

    i = 0;
    min_size = all->stack_a->nb[0];
    while (i < all->stack_a->current_size - 1)
    {
        i++;
        if (all->stack_a->nb[i] < min_size)
            min_size = all->stack_a->nb[i];
    }
    return (min_size);
}*/
/*
int	get_index(t_stacks *all, int min_size)
{
	int	i;
	int	index;
	int	size;

	i = 0
	index = 0;
	while (i < all->stack_a->current_size - 1)
	{
		if (min_size == all->stack_a[i])
		{
			index = i;
		}
	}
	return (i);
}

int	ft_first(t_stacks *all)
{
	int	min_size
	int	index;
	int	proximity;

	min_size = min_size(&all);
	index = get_index(&all, min_size);
	proximity = (all->stack_a->current_size / 2);
	if (proximity > index)
		ra();
	else
		rra();
}*/

/*

selectionner les 20 premiers nombres,
prendre le 20eme nombre comme sorte de pivot
trouver les nombres qui sont plus petit que le stack_
*/

/*
tu vas chercher le plus petit nombre qui est plus grand que le dernier plus petit nombre
que t'avais trouvé
une fois que j'ai le plus petit nombre je vais remplacer le dernier plus petit nombre
que j'ai trouvé par le nouveau que j'ai trouvé
je vais repeter ca autant de fois que le nombre de nombres que je veux dans chaque chunk

si tu vx envoyer les 20 plus petits nombres faut trouver le plus grand nombre de ces vingt plus
petits pour pouvoir l'utiliser comme valeur pivot
fonction qui va trouver le plus petit nombre

stack_a
plus petit nombre de la stack = fonction

longueur d'un chunk

--

chunk
renvoyer le plus petit nombre a chaque fois dans la fonction chunk (a coder)


*/
