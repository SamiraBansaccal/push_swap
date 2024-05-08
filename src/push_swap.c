/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbansacc <sbansacc@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 03:11:53 by sbansacc          #+#    #+#             */
/*   Updated: 2024/05/01 23:02:15 by sbansacc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_list **stack_1, t_list **stack_2)
{
	t_list	*stack_1_head;
	t_list	*stack_1_next;

	if (!*stack_1)
		return (-1);
	stack_1_head = *stack_1;
	*stack_1 = (*stack_1)->next;
	ft_lstadd_front(stack_2, stack_1_head);
	return (0);
}

int	swap(t_list **stack)
{
	void	*stack_tmp;

	if (!*stack || !(*stack)->next)
		return (-1);
	stack_tmp = ((*stack)->content);
	(*stack)->content = (*stack)->next->content;
	(*stack)->next->content = stack_tmp;
	return (0);
}

int	rotate(t_list **stack)
{
	t_list	*newlast;

	if (!*stack || !(*stack)->next)
		return (-1);
	newlast = *stack;
	*stack = (*stack)->next;
	ft_lstadd_back(stack, newlast);
	return (0);
}

int	reverse_rotate(t_list **stack)
{
	t_list	*newfirst;
	t_list	*newlast;

	if (!*stack || !(*stack)->next)
		return (-1);
	newfirst = *stack;
	newlast = *stack;
	while (newfirst->next)
		newfirst = newfirst->next;
	while (newlast->next != newfirst)
		newlast = newlast->next;
	newlast->next = NULL;
	ft_lstadd_front(stack, newfirst);
	return (0);
}

int	push_swap(char *cmd, t_list **stack_a, t_list **stack_b)
{
	if (ft_strncmp(cmd, "pa", 2) == 0)
		push(&stack_a, &stack_b);
	else if (ft_strncmp(cmd, "pb", 2) == 0)
		push(&stack_b, &stack_a);
	else if (ft_strncmp(cmd, "sa", 2) == 0 || ft_strncmp(cmd, "ss", 2) == 0)
		swap(&stack_a);
	if (ft_strncmp(cmd, "sb", 2) == 0 || ft_strncmp(cmd, "ss", 2) == 0)
		swap(&stack_b);
	else if (ft_strncmp(cmd, "rra", 3) == 0 || ft_strncmp(cmd, "rrr", 3) == 0)
		reverse_rotate(&stack_a);
	if (ft_strncmp(cmd, "rrb", 3) == 0 || ft_strncmp(cmd, "rrr", 3) == 0)
		reverse_rotate(&stack_b);
	else if (ft_strncmp(cmd, "ra", 2) == 0 || ft_strncmp(cmd, "rr", 2) == 0)
		rotate(&stack_a);
	if (ft_strncmp(cmd, "rb", 2) == 0 || ft_strncmp(cmd, "rr", 2) == 0)
		rotate(&stack_b);
	return (ft_printf("%s\n", cmd));
}
