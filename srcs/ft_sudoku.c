/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:38 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/23 15:51:10 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_grid(char **grid, int lim_inf, int lim_sup)
{
	int		i;
	int		j;

	i = lim_inf;
	while (i < lim_sup)
	{
		j = lim_inf;
		while (j < lim_sup)
		{
			if (grid[i][j] >= '1' && grid[i][j] <= '4')
				write(1, &grid[i][j], 1);
			else
			{
				write(1, &"x", 1);
			}
			j = j + 1;
		}
		write(1, &"\n", 1);
		i = i + 1;
	}
}

void	ft_read_input(char **grid, char *str)
{
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[count] != '\0')
	{
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
}

int		find_f_solution(char **grid)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		if (grid[0][i] == 4 || grid[5][i] == 4)
		{
			if ((grid[0][i] == 4 && grid[5][i] != 1) || (grid[5][i] == 4 && grid[0][i] != 1))
				i = i + 1;
			else
			{
			}
		}
		if ((grid[0][i] == 3 && grid[5][i] > 2) || (grid[5][i] == 3 && grid[0][i] != 1))
			i = i + 1;
	}
	return (0);
}

void	solve(char **grid)
{
	grid[0][0] = 1;
}

