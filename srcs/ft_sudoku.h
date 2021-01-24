/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sudoku.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmahoro- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 21:02:00 by dmahoro-          #+#    #+#             */
/*   Updated: 2021/01/24 21:15:22 by dmahoro-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SUDOKU_H
# define FT_SUDOKU_H

# include <unistd.h>
# include <stdlib.h>

int		ft_read_input(char **grid, char *str);
void	print_grid(char **grid, int lim_inf, int lim_sup);
int		solve(char **grid, int *empty_line, int *empty_col);
int		find_first_solution(char **grid);
int		all_different_line(char **grid, int line);
int		all_different_col(char **grid, int col);
int		no_line_cstrt_violated(char **grid, int line);
int		no_col_cstrt_violated(char **grid, int col);
int		no_cstrt_violated(char **grid);

#endif
