/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bregneau <bregneau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 20:28:17 by bregneau          #+#    #+#             */
/*   Updated: 2022/02/09 16:45:03 by bregneau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>


// void	aff(int *a)
// {
// 	while (a)
// 	{
// 		ft_printf("%d\n", *a++);
// 	}
// }

// int	main(int argc, char **argv)
// {
// 	int	*a;
// 	int	*b;

// 	if (argc > 1)
// 	{
// 		a = ft_parse_args(argc, argv);
// 		if (!a)
// 			return (ft_put_error());
// 		b = ft_calloc(argc, sizeof(*b));
// aff(a);
// 		free(a);
// 		free(b);
// 		return (0);
// 	}
// 	return (ft_put_error());
// }

int main()
{
	t_stack	stack;
	t_elem tmp;

	ft_init_stack(&stack);
	ft_add_new_elem(&stack, 5);
	ft_add_new_elem(&stack, 8);
	ft_add_new_elem(&stack, 1);
	// ft_add_new_elem(&stack, 4);
	// ft_add_new_elem(&stack, 9);
	
	printf("%d\n", stack.head->value);
	printf("%d\n", stack.head->next->value);
	printf("%d\n", stack.head->next->next->value);
	printf("%d\n\n", stack.head->next->next->next->value);

	tmp.value = 42;
	ft_add_front(&stack, &tmp);
	printf("%d\n", stack.head->value);
	printf("%d\n", stack.head->next->value);
	printf("%d\n", stack.head->next->next->value);
	printf("%d\n", stack.head->next->next->next->value);
	ft_free_stack(&stack);
}
