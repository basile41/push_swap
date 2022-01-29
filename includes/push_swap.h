/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:03:31 by bregneau          #+#    #+#             */
/*   Updated: 2022/01/29 14:16:38 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_elem	t_elem;
struct s_elem
{
	int		value;
	t_elem	*prev;
	t_elem	*next;
};

typedef struct s_stack
{
	t_elem	*head;
	int		size;
}	t_stack;

int	*ft_parse_args(int argc, char **argv);
int	ft_check_errors(int argc, char **argv);
int	ft_put_error(void);

// //Operations
// void	ft_swap(t_stack *s);
// void	ft_push(t_stack *src, t_stack *dst);
// void	ft_rotate(t_satck *s);
// void	ft_rev_rot(t_stack);

#endif