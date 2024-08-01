#include "../../inc/ft_push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_deque	*sa;
	t_deque	*sb;

	if (argc <= 1)
		return (0);
	sa = generate_stack(argc, argv);
	sb = generate_stack(0, 0);
	if (!sa || !sa->len || !sb)
	{
		ft_putstr_fd("Error\n", 1);
		free_stack(sa, sb);
		return (0);
	}
	sa->name = 'A';
	sb->name = 'B';
	check_sorted(sa, sb);
	free_stack(sa, sb);
}