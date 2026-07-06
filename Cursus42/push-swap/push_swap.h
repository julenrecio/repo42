/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrecio-t <jrecio-t@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 09:43:09 by azahino-          #+#    #+#             */
/*   Updated: 2026/07/01 13:36:47 by jrecio-t         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

# include "printf/ft_printf.h"		

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_cll
{
	int		size;
	int		moves[12];
	int		bench;
	double	disorder;
	t_node	*head;
}					t_cll;

typedef enum mode
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}			t_mode;

void	alg_simple(t_cll *stack_a, t_cll *stack_b);
void	alg_simple_medium(t_cll *stack_a, t_cll *stack_b);
void	alg_medium(t_cll *stack_a, t_cll *stack_b, int n_chunks, int size);
void	alg_complex(t_cll *stack_a, t_cll *stack_b);
void	alg_adaptive(double disorder, t_cll *stack_a, t_cll *stack_b);
void	ft_assignment(int argc, char **argv, t_cll *stack_a);
void	ft_bench(double disorder, t_mode mode, t_cll *a);
void	ft_count_flags(char **argv, t_mode *mode, int *count, t_cll *stack_a);
t_node	*ft_lstnew(int val);
void	ft_lstadd_back(t_cll *lst, t_node *new);
double	ft_compute_disorder(t_cll *stack_a);
long	ft_atoi(const char *nptr);
void	ft_mode(t_mode mode, t_cll *stack_a, float disorder);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);
int		ft_pos_index(t_cll *stack, int min_index, int max_index);
int		ft_cost(int index, int size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_addition(t_cll *a, t_cll *b);
void	ft_show_error(void);
int		ft_repetition(t_cll *stack_a);
void	ft_lstclear(t_cll *lst);
float	ft_square_root(int val);
char	**ft_split(char const *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
void	ft_freeall(char **array, int count);
int		ft_count_words(char const *s);
int		ft_check_error(char *arg, t_mode *mode_p, t_mode mode, size_t len);
int		how_many_chunks(t_cll *a);
void	ft_pa(t_cll *a, t_cll *b);
void	ft_pb(t_cll *a, t_cll *b);
void	ft_ss(t_cll *a, t_cll *b);
void	ft_sa(t_cll *a);
void	ft_sb(t_cll *b);
void	ft_ra(t_cll *a);
void	ft_rb(t_cll *b);
void	ft_rr(t_cll *a, t_cll *b);
void	ft_rra(t_cll *a);
void	ft_rrb(t_cll *b);
void	ft_rrr(t_cll *a, t_cll *b);

#endif