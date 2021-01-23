/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:52:53 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/23 15:37:22 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.c"

int	main(int argc, char *argv[])
{
	char	**grid = malloc(6*sizeof(char*));
	int		i;
	int		j;

	i = 0;
	grid = malloc(6*sizeof(char*));
	while (i< 6)
	{
		grid[i] = malloc(6*sizeof(char));
		j = 0;
		while (j < 6)
		{
			grid[i][j] = '0';
			j = j + 1;
		}
		i = i + 1;
	}

	if (argc != 2)
	{
		write(1, &"Error\n", 6);
	}
	else
	{
		ft_read_input(grid, argv[1]);
		print_grid(grid);
	}

	i = 0;
	while (i < 6)
	{
		free(grid[i]);
		i = i + 1;
	}
	free(grid);

	return (0);
}
