/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:52:53 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 21:15:53 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.h"

char	**init_grid(void)
{
	int		i;
	int		j;
	char	**grid;

	grid = malloc(6 * sizeof(char *));
	i = 0;
	while (i < 6)
	{
		grid[i] = malloc(6 * sizeof(char));
		j = 0;
		while (j < 6)
		{
			grid[i][j] = '0';
			j = j + 1;
		}
		i = i + 1;
	}
	return (grid);
}

void	free_grid(char **grid)
{
	int		i;

	i = 0;
	while (i < 6)
	{
		free(grid[i]);
		i = i + 1;
	}
	free(grid);
}

int		main(int argc, char *argv[])
{
	char	**grid;
	int		empty_col;
	int		empty_line;

	grid = init_grid();
	if (argc == 2)
	{
		if (ft_read_input(grid, argv[1]) == 0)
		{
			if (find_first_solution(grid) != 0)
				write(1, &"Error\n", 6);
			else
			{
				empty_line = 0;
				empty_col = 0;
				if (solve(grid, &empty_line, &empty_col) != 0)
					write(1, &"Error\n", 6);
				print_grid(grid, 1, 5);
				free_grid(grid);
			}
		}
	}
	else
		write(1, &"Error\n", 6);
	return (0);
}
