/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:38 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 21:25:02 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

int		find_empty(char **grid, int *empty_i, int *empty_j)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
		j = 1;
		while (j <= 4)
		{
			if (grid[i][j] < '1' || grid[i][j] > '4')
			{
				*empty_i = i;
				*empty_j = j;
				return (0);
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (-1);
}

int		solve(char **grid, int *empty_line, int *empty_col)
{
	int		i;

	if (find_empty(grid, empty_line, empty_col) != 0)
		return (-1);
	i = 1;
	while (i <= 4)
	{
		grid[*empty_line][*empty_col] = i + '0';
		if (no_cstrt_violated(grid) != 0)
		{
			grid[*empty_line][*empty_col] = '0';
		}
		else
		{
			if (find_empty(grid, empty_line, empty_col) != 0
				&& no_cstrt_violated(grid) == 0)
				return (0);
			if (solve(grid, empty_line, empty_col) == 0)
				return (0);
		}
		i = i + 1;
	}
	return (0);
}
