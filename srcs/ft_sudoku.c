/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:38 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/23 15:36:56 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

void	print_grid(char **grid)
{
	int		i;
	int		j;

	i = 0;
	while (i < 6)
	{
		j = 0;
		while (j < 6)
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

void	ft_write_input(char **grid, int index, char value)
{
	if (index >= 1 && index <= 4)
		grid[0][index] = value;
	if (index >= 5 && index <= 8)
		grid[5][index - 4] = value;
	if (index >= 9 && index <= 12)
		grid[index - 8][0] = value;
	if (index >= 13 && index <= 16)
		grid[index - 12][5] = value;
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
			ft_write_input(grid, index, str[count]);
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

