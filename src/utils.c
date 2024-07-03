
#include "../inc/ft_push_swap.h"

static t_list	*get_max_node3(t_list *node1, t_list *node2, t_list *node3)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = *((int *)(node1->content));
	v2 = *((int *)(node2->content));
	v3 = *((int *)(node3->content));
	if (v2 < v1 && v1 > v3)
		return (node1);
	if (v1 < v2 && v2 > v3)
		return (node2);
	return (node3);
}

static t_list	*get_min_node3(t_list *node1, t_list *node2, t_list *node3)
{
	int	v1;
	int	v2;
	int	v3;

	v1 = *((int *)(node1->content));
	v2 = *((int *)(node2->content));
	v3 = *((int *)(node3->content));
	if (v2 > v1 && v1 < v3)
		return (node1);
	if (v1 > v2 && v2 < v3)
		return (node2);
	return (node3);
}

t_list  *get_node3(t_list *node1, t_list *node2, t_list *node3, int is_max)
{
    if (is_max % 4 <= 1)
        return (get_max_node3(node1, node2, node3));
    return (get_min_node3(node1, node2, node3));
}