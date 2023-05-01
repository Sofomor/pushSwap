/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imorina <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 20:47:35 by imorina           #+#    #+#             */
/*   Updated: 2021/11/29 15:25:46 by imorina          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

int		ft_atoi(const char *str);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isdigit(int c);

int		ft_isprint(int c);

void	*ft_memchr(const void *s, int c, size_t n);

size_t	ft_strlen(const char *s);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

char	*ft_strdup(const char *s1);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(char *str, int fd);

void	ft_putstr_fd(char *str, int fd);

void	ft_putnbr_fd(int n, int fd);

char	*ft_strjoin(char const *s1, char const *s2);

char	*ft_strdup(const char *s1);

char	*ft_substr(const char *s, unsigned int start, size_t len);

char	**ft_split(char const*s, char c);

#endif
