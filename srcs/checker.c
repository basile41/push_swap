/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:10:25 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/24 22:00:24 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
//#include "../libft/libft.h"

void	ft_exit_error(t_stack *a, t_stack *b)
{
	ft_put_error();
	ft_free_stack(a);
	ft_free_stack(b);
	exit(0);
}

void	ft(t_stack *a, t_stack *b, void f(t_stack*))
{
	f(a);
	f(b);
}

int	ft_if_forest(t_stack *a, t_stack *b, char *line)
{
	if (strcmp(line, "sa\n") == 0)
		ft_swap(a);
	else if (strcmp(line, "sb\n") == 0)
		ft_swap(b);
	else if (strcmp(line, "ss\n") == 0)
		ft(a, b, ft_swap);
	else if (strcmp(line, "pa\n") == 0)
		ft_push(b, a);
	else if (strcmp(line, "pb\n") == 0)
		ft_push(a, b);
	else if (strcmp(line, "ra\n") == 0)
		ft_rotate(a);
	else if (strcmp(line, "rb\n") == 0)
		ft_rotate(b);
	else if (strcmp(line, "rr\n") == 0)
		ft(a, b, ft_rotate);
	else if (strcmp(line, "rra\n") == 0)
		ft_rrotate(a);
	else if (strcmp(line, "rrb\n") == 0)
		ft_rrotate(b);
	else if (strcmp(line, "rrr\n") == 0)
		ft(a, b, ft_rrotate);
	else
		return (0);
	return (1);
}

void	ft_checker(t_stack *a, t_stack *b)
{
	char	*line;
	int		ret;

	line = get_next_line(0);
	while (line)
	{
		ret = ft_if_forest(a, b, line);
		free(line);
		if (!ret)
			ft_exit_error(a, b);
		line = get_next_line(0);
	}
	if (b->size == 0 && ft_is_sorted(a->head))
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;

	ft_bzero(&a, sizeof(a));
	ft_bzero(&b, sizeof(b));
	if (argc > 1)
	{
		if (ft_parse_args(argc, argv, &a) == 0)
		{
			ft_free_stack(&a);
			return (ft_put_error());
		}
		ft_checker(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
	}
	return (0);
}
