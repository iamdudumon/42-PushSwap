#include "../inc/ft_push_swap.h"

static void    print_stack(t_list *sa, t_list *sb)
{
    printf("--------------------------------\n");
    while (sa || sb)
    {
        if (!sa)
            printf(" \t\t%d\n", *(int *)(sb->content));
        else if (!sb)
            printf("%d\t\t \n", *(int *)(sa->content));
        else
            printf("%d\t\t%d\n", *(int *)(sa->content), *(int *)(sb->content));
        if (sa)
            sa = sa->next;
        if (sb)
            sb = sb->next;
    }
    printf("stack a\t\tstack b\n\n");
}

void    start_sorting(t_list *sa, t_list *sb)
{
    char	cmd[4];
	
	cmd[0] = ' ';
	cmd[1] = '\0';
	while (1)
	{
		print_stack(sa, sb);
		scanf("%s", cmd);
		if (!ft_strncmp(cmd, "q!", 2))
			break ;
		if (!ft_strncmp(cmd, "sa", 2))
		{
			swap(sa);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "sb", 2))
		{
			swap(sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "ss", 2))
		{
			swap_twin(sa, sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "pa", 2))
		{
			push(&sa, &sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "pb", 2))
		{
			push(&sb, &sa);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "ra", 2))
		{
			rotate(sa);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "rb", 2))
		{
			rotate(sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "rr", 3))
		{
			rotate_twin(sa, sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "rra", 3))
		{
			reverse_rotate(sa);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "rrb", 3))
		{
			reverse_rotate(sb);
			continue ;
		}
			
		if (!ft_strncmp(cmd, "rrr", 3))
		{
			reverse_rotate_twin(sa, sb);
			continue;
		}
	
	}
}