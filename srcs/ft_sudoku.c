/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:38 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/23 20:38:00 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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

int		ft_fill_if_possible(char **grid, int col)
{
	int		i;

	if ((grid[0][col] == 4 && grid[5][col] != 1) || (grid[5][col] == 4 && grid[0][col] != 1))
		return (-1);
	else
	{
		if (grid[0][col] == 4)
		{
			i = 1;
			while (i <= 4)
			{
				grid[i][col] = '0' + i;
				i = i + 1;
			}
		}
		else if (grid[0][col] == 1)
		{
			i = 4;
			while (i >= 1)
			{
				grid[5 - i][col] = '0' + i;
				i = i - 1;
			}
		}
		else
		{
			write(1, &"\"NOOOO!\", Luke S.\n", 25);
		}
	}
	return (0);
}

int		ft_read_input(char **grid, char *str)
{
printf("In read input\n");
	int	count;
	int	index;

	count = 0;
	index = 0;
	while (str[count] != '\0')
	{
//printf("char : %c\n", str[count]);
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
//printf("in read input : count == %d\n", count);
	if (index != 16)
		return (-1);
	else
		return (0);
}

int		find_first_solution(char **grid)
{
	int		i;
	int		res;

	i = 1;
	while (i <= 4)
	{
		if (grid[0][i] == 4 || grid[0][i] == 1)
		{
			res = ft_fill_if_possible(grid, i);
			if (res != 0)
				return (res);
		}
		if ((grid[0][i] == 3 && grid[5][i] > 2) || (grid[5][i] == 3 && grid[0][i] > 2))
			return (-1);
		if ((grid[0][i] == 2 && grid[5][i] > 3) || (grid[5][i] == 2 && grid[0][i] > 3))
			return (-1);
	}
	return (0);
}

void	solve(char **grid)
{
	grid[0][0] = 1;
}
