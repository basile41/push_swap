/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:28:17 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/11 17:01:04 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

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
		ft_push_swap(&a, &b);
		ft_free_stack(&a);
		ft_free_stack(&b);
		return (0);
	}
	return (0);
}

// int main()
// {
// 	t_stack	stack;

// 	ft_init_stack(&stack);
// 	ft_add_new_elem(&stack, 5);
// 	ft_add_new_elem(&stack, 8);
// 	ft_add_new_elem(&stack, 1);
// 	// ft_add_new_elem(&stack, 4);
// 	// ft_add_new_elem(&stack, 9);

// 	printf("%d\n", stack.head->value);
// 	printf("%d\n", stack.head->next->value);
// 	printf("%d\n", stack.head->next->next->value);
// 	printf("%d\n\n", stack.head->next->next->next->value);

// 	ft_rrotate(&stack);
// 	printf("%d\n", stack.head->value);
// 	printf("%d\n", stack.head->next->value);
// 	printf("%d\n", stack.head->next->next->value);
// 	printf("%d\n", stack.head->next->next->next->value);
// 	ft_free_stack(&stack);
// }
