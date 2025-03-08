#include "../includes/push_swap.h"

static int find_min_position(t_list *stack)
{
    t_list  *current = stack;
    int     min_val = current->content;
    int     min_pos = 0;
    int     i = 0;

    while (current)
    {
        if (current->content < min_val)
        {
            min_val = current->content;
            min_pos = i;
        }
        current = current->next;
        i++;
    }
    return (min_pos);
}

static void ft_rotate_to_top(t_list **stack, int pos)
{
    int size = ft_lstsize(*stack);

    if (pos <= size / 2)
    {
        while (pos > 0)
        {
            ra(stack);
            pos--;
        }
    }
    else
    {
        while (pos < size)
        {
            rra(stack);
            pos++;
        }
    }
}

/*
** pop_min_to_b:
**   A'daki en küçük elemanı bul, tepeye getir, B'ye push et.
*/
static void pop_min_to_b(t_list **stack_a, t_list **stack_b)
{
    int pos = find_min_position(*stack_a);
    ft_rotate_to_top(stack_a, pos);
    pb(stack_a, stack_b);
}

/*
** sort_3:
**   3 elemanlı listeyi en fazla 3-4 hamleyle sıralar.
**   (Klasik push_swap "sort_3" mantığı, if-else bloklarıyla yazılabilir.)
*/
static void sort_3(t_list **stack)
{
    t_list *a = *stack;
    int x = a->content;
    int y = a->next->content;
    int z = a->next->next->content;

    if (x > y && x < z)
        sa(stack);
    else if (x > y && y > z)
    {
        sa(stack);
        rra(stack);
    }
    else if (x > z && y < z)
        ra(stack);
    else if (x < y && x > z)
        rra(stack);
    else if (x < y && y > z)
    {
        sa(stack);
        ra(stack);
    }
}

void pop_min_sort(t_list **stack_a, t_list **stack_b)
{
    while (ft_lstsize(*stack_a) > 3)
        pop_min_to_b(stack_a, stack_b);

    if (ft_lstsize(*stack_a) == 3 && !is_sorted(*stack_a))
        sort_3(stack_a);
    else if (ft_lstsize(*stack_a) == 2)
    {
        if ((*stack_a)->content > (*stack_a)->next->content)
            sa(stack_a);
    }
    while (*stack_b)
        pa(stack_a, stack_b);
}
