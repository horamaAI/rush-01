/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 08:52:53 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 11:17:47 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

int		ft_read_input(char **grid, char *str);
void	print_grid(char **grid, int lim_inf, int lim_sup);
int		solve(char **grid, int *empty_line, int *empty_col);
int		find_first_solution(char **grid);

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
	int		empty_col;
	int		empty_line;
//printf("NOOOOO!!!\n");

	grid = init_grid();
//printf("arg is %d\n", argc);
	if (argc == 2)
	{
//printf("arg is == 2\n");
		i = ft_read_input(grid, argv[1]);
printf("%d before res\n", i);
		if (i == 0)
		{
			i = find_first_solution(grid);
printf("Value returned by find first solution %d\n", i);
			if (i != 0)
				write(1, &"Error\n", 6);
			else
			{
//printf("passed find first solution == 2\n");
//				print_grid(grid, 1, 5);
empty_line = 0;
empty_col = 0;
printf("should start solving\n");
				//i = solve(grid, &empty_line, &empty_col);
print_grid(grid, 1, 5);
printf("Result of i is %d\n", i);
				if (i != 0)
					return (-1);
				i = 0;
				while (i < 6)
				{
					free(grid[i]);
					i = i + 1;
				}
				free(grid);
			}
//printf("%d res\n", i);
		}
	}
	else
	{
		write(1, &"Error\n", 6);
	}
	return (0);
}
