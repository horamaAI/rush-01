/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:52:53 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/23 20:44:07 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_sudoku.c"

char	**init_grid(void)
{
	int		i;
	int		j;
	char	**grid;
   
	grid = malloc(6 * sizeof(char * ));
	i = 0;
	while (i < 6)
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
	return (grid);
}

int		main(int argc, char *argv[])
{
	char	**grid;
	int		i;

printf("argc == %d\n", argc);
	grid = init_grid();
	if (argc == 2)
	{
//printf("arg is == 2\n");
		i = ft_read_input(grid, argv[1]);
//printf("%d before res\n", i);
		if (i == 0)
		{
			i = find_first_solution(grid);
//printf("%d res\n", i);
		}
	}
	if (argc != 2 || i != 0)
		write(1, &"Error\n", 6);
	else
	{
		print_grid(grid, 1, 5);
	}
	if (argc == 2)
	{
		i = 0;
		while (i < 6)
		{
			free(grid[i]);
			i = i + 1;
		}
		free(grid);
	}
	return (0);
}
