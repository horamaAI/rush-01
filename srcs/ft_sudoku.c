/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:34:38 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 11:17:40 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <unistd.h>

#include <stdio.h>

void	print_grid(char **grid, int lim_inf, int lim_sup);

int		find_empty(char **grid, int *empty_i, int *empty_j)
{
	int		i;
	int		j;

	i = 1;
	while (i <= 4)
	{
//printf("and one more tour, one (find empty)\n");
		j = 1;
		while (j <= 4)
		{
printf("where i,j are %d,%d test in find empty current value %c\n", i, j, grid[i][j]);
			if (grid[i][j] < '1' || grid[i][j] > '4')
			{
//printf("in if, (j)\n");
				*empty_i = i;
				*empty_j = j;
printf("finished in if, (j) i,j is %d,%d\n", i, j);
				return (0);
			}
			j = j + 1;
		}
		i = i + 1;
	}
	return (-1);
}

void	fill_existing_on_line(char **grid, char *vals, int line)
{
	int		i;
	int		value;

	i = 1;
	while(i <= 4)
	{
		if (grid[line][i] != '0')
		{
			value = (int) (grid[line][i]-'0');
			vals[value] = '-';
		}
		i = i + 1;
	}
}

void	fill_existing_on_col(char **grid, char *vals, int col)
{
	int		i;
	int		value;

	i = 1;
	while(i <= 4)
	{
		if (grid[i][col] != '0')
		{
			value = (int) (grid[i][col]-'0');
			vals[value] = '-';
		}
		i = i + 1;
	}
}

void	reset_val_table(char *vals)
{
	int		i;

	i = 1;
	while (i <= 4)
	{
		vals[i] = i + '0';
		i = i + 1;
	}
}

int		no_line_cstrt_violated(char **grid, char *vals, int line)
{
	int			i;
	int			count_vues;
	int			count_val_remaining;
	int			index_max;

	i = 1;
	index_max = 1;
	count_val_remaining = 4;
	count_vues = 0;
printf("in line %d cstrt test:", line);
	while (i <= 4)
	{
printf("%c", vals[i]);
		if (vals[i] == '-')
			count_val_remaining = count_val_remaining - 1;
		if (grid[line][index_max] < grid[line][i])
		{
printf("in if index_max = %d, i = %d, grid[line][index_max] = %c, grid[line][i] = %c\n", index_max, i, grid[line][index_max], grid[line][i]);
			count_vues = count_vues + 1;
			index_max = i;
		}
		i = i + 1;
	}
printf("count vues = %d, grid[%d][0] = %c and val remaining %d\n", count_vues, line, grid[line][0], count_val_remaining);
printf("Test %d and %d\n", (count_vues == grid[line][0] - '1'), (count_val_remaining == 0));
	if ((count_vues == grid[line][0] - '1') && (count_val_remaining >= 0))
		return (0);
	return (-1);
}

int		no_col_cstrt_violated(char **grid, char *vals, int col)
{
	int			i;
	int			count_vues;
	int			count_val_remaining;
	int			index_max;

	i = 1;
	index_max = 1;
	count_val_remaining = 4;
	count_vues = 0;
	while (i <= 4)
	{
		if (vals[i] == '-')
			count_val_remaining = count_val_remaining - 1;
		if (grid[index_max][col] < grid[i][col])
		{
			count_vues = count_vues + 1;
			index_max = i;
		}
		i = i + 1;
	}
printf("COL!!! count vues = %d, grid[0][%d] = %c and val remaining %d\n", count_vues, col, grid[0][col], count_val_remaining);
printf("COL!!! Test %d and %d\n", (count_vues == grid[0][col] - '1'), (count_val_remaining == 0));
	if ((count_vues == grid[0][col] - '1') && (count_val_remaining >= 0))
		return (0);
	return (-1);
}

int		no_cstrt_violated(char **grid)
{
	int			i;
	int			check1;
	int			check2;
	char		vals[5];
	int			res_cstrt;
print_grid(grid, 1, 5);
	i = 1;
	check1 = 0;
	check2 = 0;
	while (i <= 4)
	{
		reset_val_table(vals);
		fill_existing_on_line(grid, vals, i);
		res_cstrt = no_line_cstrt_violated(grid, vals, i);
printf("test line cstrt %d\n", res_cstrt);
		if (res_cstrt == 0)
			check1 = check1 + 1;
		reset_val_table(vals);
		fill_existing_on_col(grid, vals, i);
		res_cstrt = no_col_cstrt_violated(grid, vals, i);  
printf("test col cstrt %d\n", res_cstrt);
		if (res_cstrt == 0)
			check2 = check2 + 1;
		i = i + 1;
	}
printf("Values of check respectively %d,%d\n", check1, check2);
	if (check1 == 4 && check2 == 4)
		return (0);
	return (-1);
}

int		solve(char **grid, int *empty_line, int *empty_col)
{
//write(1, &"Into solve\n", 11);
printf("Inro solve\n");
print_grid(grid, 1, 5);
	int		i;
	int		has_empty;

	has_empty = find_empty(grid, empty_line, empty_col);
printf("Has empty has value %d and empty line/col are respectively %d,%d\n", has_empty, *empty_line, *empty_col);
	if (has_empty != 0)
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
printf("In while %d, %d == %c\n", *empty_line, *empty_col, grid[*empty_line][*empty_col]);
			has_empty = find_empty(grid, empty_line, empty_col);
//printf("Finished has empty of value %d, and no_cstrt_violated(grid) is %d\n", has_empty, no_cstrt_violated(grid));
			if (!has_empty && no_cstrt_violated(grid) == 0)
				return (0);
//printf("Does it get here?\n");
			if (solve(grid, empty_line, empty_col) != 0)
			{
				*empty_line = '0';
				*empty_col = '0';
			}
		}
//printf("One more tour of while\n");
		i = i + 1;
	}

	return (0);
}
