
#include "../inc/ft_push_swap.h"

static t_list	*get_max_node3(t_list *node1, t_list *node2, t_list *node3, int c1, int c2, int c3)
{
	int	v1;
	int	v2;
	int	v3;

	if (!c1)
		v1 = -2147483648;
	else
		v1 = *((int *)(node1->content));
	if (!c2)
		v2 = -2147483648;
	else
		v2 = *((int *)(node2->content));
	if (!c3)
		v3 = -2147483648;
	else
		v3 = *((int *)(node3->content));
	// printf("max: %d, %d, %d\n", v1, v2, v3);
	if (v2 < v1 && v1 > v3)
		return (node1);
	if (v1 < v2 && v2 > v3)
		return (node2);
	return (node3);
}

static t_list	*get_min_node3(t_list *node1, t_list *node2, t_list *node3, int c1, int c2, int c3)
{
	int	v1;
	int	v2;
	int	v3;

	if (!c1)
		v1 = 2147483647;
	else
		v1 = *((int *)(node1->content));
	if (!c2)
		v2 = 2147483647;
	else
		v2 = *((int *)(node2->content));
	if (!c3)
		v3 = 2147483647;
	else
		v3 = *((int *)(node3->content));
	// printf("min: %d, %d, %d\n", v1, v2, v3);
	if (v2 > v1 && v1 < v3)
		return (node1);
	if (v1 > v2 && v2 < v3)
		return (node2);
	return (node3);
}

t_list  *get_node3(t_list *node1, t_list *node2, t_list *node3, int is_max, int c1, int c2, int c3)
{
    if (is_max)
        return (get_max_node3(node1, node2, node3, c1, c2, c3));
    return (get_min_node3(node1, node2, node3, c1, c2, c3));
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
	return (i - 1);
}