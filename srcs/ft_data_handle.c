/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_handle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 23:01:27 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 10:39:49 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include <stdio.h>

void	print_grid(char **grid, int lim_inf, int lim_sup)
{
printf("print grid\n");
	int		i;
	int		j;

	i = lim_inf;
	while (i < lim_sup)
	{
		j = lim_inf;
		while (j < lim_sup)
		{
			if (grid[i][j] >= '1' && grid[i][j] <= '4')
			{
//				write(1, &grid[i][j], 1);
printf("%c", grid[i][j]);
			}
			else
			{
//				write(1, &"x", 1);
printf("x");
			}
			j = j + 1;
		}
printf("\n");
//		write(1, &"\n", 1);
		i = i + 1;
	}
}

int		ft_read_input(char **grid, char *str)
{
//printf("In read input\n");
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[count] != '\0')
	{
//if (str[count] != ' ')
//printf("char : %c and index = %d\n", str[count], index);
		if (str[count] >= '1' && str[count] <= '4')
		{
			index = index + 1;
			if (index >= 1 && index <= 4)
				grid[0][index] = str[count];
			if (index >= 5 && index <= 8)
				grid[5][index - 4] = str[count];
			if (index >= 9 && index <= 12)
				grid[index - 8][0] = str[count];
			if (index >= 13 && index <= 16)
				grid[index - 12][5] = str[count];
		}
		count = count + 1;
	}
//print_grid(grid, 1, 5);
//printf("in read input : index == %d\n", index);
	if (index != 16)
		return (-1);
	else
		return (0);
}
