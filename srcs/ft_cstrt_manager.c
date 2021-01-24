/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cstrt_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:22:14 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 21:24:29 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		all_different_line(char **grid, int line)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
		j = i + 1;
		while (j <= 4)
		{
			if ((grid[line][i] >= '1' && grid[line][i] <= '4') &&
					(grid[line][j] >= '1' && grid[line][j] <= '4'))
			{
				if (grid[line][i] == grid[line][j])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		all_different_col(char **grid, int col)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
		j = i + 1;
		while (j <= 4)
		{
			if ((grid[i][col] >= '1' && grid[i][col] <= '4') &&
					(grid[j][col] >= '1' && grid[j][col] <= '4'))
			{
				if (grid[i][col] == grid[j][col])
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		no_line_cstrt_violated(char **grid, int line)
{
	int			i;
	char		count_vues;
	int			index_max;
	int			empty_cell;

	if (all_different_line(grid, line) != 0)
		return (1);
	i = 1;
	index_max = 1;
	empty_cell = 0;
	count_vues = '0';
	while (i <= 4)
	{
		if (grid[line][index_max] < grid[line][i])
		{
			count_vues = count_vues + 1;
			index_max = i;
		}
		if (grid[line][i] < '1' || grid[line][i] > '4')
			empty_cell = empty_cell + 1;
		i = i + 1;
	}
	if (count_vues < grid[line][0] || empty_cell != 0)
		return (0);
	return (-1);
}

int		no_col_cstrt_violated(char **grid, int col)
{
	int			i;
	char		count_vues;
	int			index_max;
	int			empty_cell;

	if (all_different_col(grid, col) != 0)
		return (1);
	i = 1;
	index_max = 1;
	empty_cell = 0;
	count_vues = '0';
	while (i <= 4)
	{
		if (grid[index_max][col] < grid[i][col])
		{
			count_vues = count_vues + 1;
			index_max = i;
		}
		if (grid[i][col] < '1' || grid[i][col] > '4')
			empty_cell = empty_cell + 1;
		i = i + 1;
	}
	if (count_vues < grid[0][col] || empty_cell != 0)
		return (0);
	return (1);
}

int		no_cstrt_violated(char **grid)
{
	int			i;
	int			check1;
	int			check2;
	int			res_cstrt;

	i = 1;
	check1 = 0;
	check2 = 0;
	while (i <= 4)
	{
		res_cstrt = no_line_cstrt_violated(grid, i);
		if (res_cstrt == 0)
			check1 = check1 + 1;
		res_cstrt = no_col_cstrt_violated(grid, i);
		if (res_cstrt == 0)
			check2 = check2 + 1;
		i = i + 1;
	}
	if (check1 == 4 && check2 == 4)
		return (0);
	return (-1);
}
