/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_solution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 10:04:37 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 10:12:57 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>


#include <stdio.h>
void	print_grid(char **grid, int lim_inf, int lim_sup);

int		ft_init_col_if_possible(char **grid, int col)
{
//printf("in init col %d if possible\n", col);
	int		i;

	if ((grid[0][col] == '4' && grid[5][col] != '1') || (grid[0][col] == '1' && grid[5][col] != '4'))
		return (-1);
	else
	{
		if (grid[0][col] == '4')
		{
printf("In col == 4\n");
			i = 1;
			while (i <= 4)
			{
				if (grid[i][col] == '0' || grid[i][col] == '0' + i)
					grid[i][col] = '0' + i;
				else
				{
//printf("in init col %d,%d %c\n", i, col, grid[i][col]);
					return (-1);
				}
				i = i + 1;
			}
print_grid(grid, 1, 5);
		}
		else if (grid[0][col] == '1')
		{
			i = 4;
			while (i >= 1)
			{
				if (grid[5 - i][col] == '0' || grid[5 - i][col] == '0' + i)
					grid[5 - i][col] = '0' + i;
				else
				{
//printf("in init reverse col 5-%d,%d %c\n", i, col, grid[i][col]);
					return (-1);
				}
				i = i - 1;
			}
		}
		else
		{
			write(1, &"(col)\"NOOOO!\", Luke S.\n", 25);
		}
	}
	return (0);
}

int		ft_init_line_if_possible(char **grid, int line)
{
//printf("in init line %d if possible\n", line);
	int		i;

	if ((grid[line][0] == '4' && grid[line][5] != '1') || (grid[line][0] == '1' && grid[line][5] != '4'))
		return (-1);
	else
	{
		if (grid[line][0] == '4')
		{
printf("In line == 4\n");
			i = 1;
			while (i <= 4)
			{
				if (grid[line][i] != '0' || grid[line][i] != '0' + i)
					grid[line][i] = '0' + i;
				else
				{
//printf("in init line %d,%d %c\n", line, i, grid[line][i]);
					return (-1);
				}
				i = i + 1;
			}
print_grid(grid, 1, 5);
		}
		else if (grid[line][0] == '1')
		{
			i = 4;
			while (i >= 1)
			{
				if (grid[line][5 - i] != '0' || grid[line][5 - i] != '0' + i)
					grid[line][5 - i] = '0' + i;
				else
				{
//printf("in init line reverse %d,5-%d, %c\n", line, i, grid[line][5 - i]);
					return (-1);
				}
				i = i - 1;
			}
		}
		else
		{
			write(1, &"(line)\"NOOOO!\", Luke S.\n", 25);
		}
	}
	return (0);
}


int		find_first_solution(char **grid)
{
	int		i;
	int		res;
printf("Test init first solution\n");
print_grid(grid, 1, 6);
	i = 1;
	while (i <= 4)
	{
//printf("val i in first solution %d, test %c\n", i, grid[0][i]);
		if (grid[0][i] == '4' || grid[0][i] == '1')
		{
			res = ft_init_col_if_possible(grid, i);
printf("in if condition col %d, test [%c,%c] and res %d\n", i, grid[0][i], grid[5][i], res);
			if (res != 0)
				return (res);
		}
		if (grid[i][0] == '4' || grid[i][0] == '1')
		{
//printf("in if condition %d, test %c\n", i, grid[0][i]);
			res = ft_init_line_if_possible(grid, i);
printf("in if condition line %d, test %c and res %d\n", i, grid[i][0], res);
			if (res != 0)
				return (res);
		}
		if ((grid[0][i] == '3' && grid[5][i] > '2') || (grid[5][i] == '3' && grid[0][i] > '2'))
		{
printf("TOTO 1\n");
			return (-1);
		}
		if ((grid[0][i] == '2' && grid[5][i] > '3') || (grid[5][i] == '2' && grid[0][i] > '3'))
		{
printf("TOTO 2\n");
			return (-1);
		}
		if ((grid[i][0] == '3' && grid[i][5] > '2') || (grid[i][5] == '3' && grid[i][0] > '2'))
		{
printf("TOTO 3\n");
			return (-1);
		}
		if ((grid[i][0] == '2' && grid[i][5] > '3') || (grid[i][5] == '2' && grid[i][0] > '3'))
		{
printf("TOTO 4\n");
			return (-1);
		}
		i = i + 1;
	}
	return (0);
}
