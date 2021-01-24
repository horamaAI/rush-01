/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:04:37 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 21:17:18 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		ft_init_col_if_possible(char **grid, int col)
{
	int		i;

	if (grid[0][col] == '4' && grid[5][col] != '1')
		return (-1);
	else
	{
		i = 1;
		while (i <= 4)
		{
			if (grid[i][col] == '0' || grid[i][col] == '0' + i)
				grid[i][col] = '0' + i;
			else
			{
				return (-1);
			}
			i = i + 1;
		}
	}
	return (0);
}

int		ft_init_line_if_possible(char **grid, int line)
{
	int		i;

	if (grid[line][0] == '4' && grid[line][5] != '1')
		return (-1);
	else
	{
		i = 1;
		while (i <= 4)
		{
			if (grid[line][i] != '0' || grid[line][i] != '0' + i)
				grid[line][i] = '0' + i;
			else
			{
				return (-1);
			}
			i = i + 1;
		}
	}
	return (0);
}

int		check_last_condition(char **grid, int i)
{
	if ((grid[0][i] == '3' && grid[5][i] > '2')
		|| (grid[0][i] == '2' && grid[5][i] > '3')
		|| (grid[i][0] == '3' && grid[i][5] > '2')
		|| (grid[i][0] == '2' && grid[i][5] > '3')
		|| (grid[i][0] == '1' && grid[i][5] == '1')
		|| (grid[0][i] == '1' && grid[5][i] == '1'))
	{
		return (-1);
	}
	return (0);
}

int		find_first_solution(char **grid)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		if (grid[0][i] == '4')
		{
			if (ft_init_col_if_possible(grid, i) != 0)
				return (-1);
		}
		if (grid[i][0] == '4')
		{
			if (ft_init_line_if_possible(grid, i) != 0)
				return (-1);
		}
		if (check_last_condition(grid, i) == -1)
			return (-1);
		i = i + 1;
	}
	return (0);
}
