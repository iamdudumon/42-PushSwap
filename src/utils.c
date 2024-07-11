
#include "../inc/ft_push_swap.h"

static t_list	*get_max_node3(t_list *node1, t_list *node2, t_list *node3, t_size ts)
{
	int	v1;
	int	v2;
	int	v3;

	if (!ts.s1)
		v1 = -2147483648;
	else
		v1 = *((int *)(node1->content));
	if (!ts.s2)
		v2 = -2147483648;
	else
		v2 = *((int *)(node2->content));
	if (!ts.s3)
		v3 = -2147483648;
	else
		v3 = *((int *)(node3->content));
	if (v2 < v1 && v1 > v3)
		return (node1);
	if (v1 < v2 && v2 > v3)
		return (node2);
	return (node3);
}

static t_list	*get_min_node3(t_list *node1, t_list *node2, t_list *node3, t_size ts)
{
	int	v1;
	int	v2;
	int	v3;

	if (!ts.s1)
		v1 = 2147483647;
	else
		v1 = *((int *)(node1->content));
	if (!ts.s2)
		v2 = 2147483647;
	else
		v2 = *((int *)(node2->content));
	if (!ts.s3)
		v3 = 2147483647;
	else
		v3 = *((int *)(node3->content));
	if (v2 > v1 && v1 < v3)
		return (node1);
	if (v1 > v2 && v2 < v3)
		return (node2);
	return (node3);
}

t_list  *get_node3(t_list *node1, t_list *node2, t_list *node3, int is_max, t_size ts)
{
    if (is_max)
        return (get_max_node3(node1, node2, node3, ts));
    return (get_min_node3(node1, node2, node3, ts));
}

int		get_depth(int size)
{
	int	i;

	i = 0;
	while (size)
	{
		size /= 3;
		i++;
	}
	return (i);
}

int	is_swap(t_deque *stack, int is_max)
{
	int	head;
	int	head_next;

	head = *(int *)(stack->header->content);
	head_next = *(int *)(stack->header->next->content);
	if (is_max)
	{
		if (head_next < head)
			return (1);
		return (0);
	}
	if (head_next > head)
		return (1);
	return (0);
}

t_size	cal_size3(int size)
{
	t_size	ts;
	int		c;
	
	c = size % 3;
    if (c == 0)
        c = 0;
    else
        c -= 1;
    ts.s1 = size - (2 * (size / 3) + c);
    ts.s2 = size - ts.s1 - ((size - ts.s1) / 2);
    ts.s3 = size - ts.s1 - ts.s2;
	return (ts);
}