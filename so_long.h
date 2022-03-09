/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 21:45:16 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/19 21:46:05 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_wind;
	char	**map;
	int		x;
	int		y;
	int		i;
	int		j;
	int		len;
	int		c;
	int		count;

}	t_data;

typedef struct s_element
{
	void	*wall;
	void	*floor;
	void	*mario;
	void	*col;
	void	*door;
	int		mashroom;
	int		player;
	int		exit;
	int		a;
	int		b;
}	t_element;

void	render_map(void *mlx, void *mlx_wind, t_data *dt);
void	rest_check_walls(int len, int i, char **map);
void	rest_elem_vld(int m, int p, int e);
void	check_new_line(char *map);
void	find_player(t_data *pd);
void	check_map(char **map);
void	ft_putchar(char c);
void	ft_putnbr(int n);
char	*ft_substr(char const *s, int start, int len);
char	*ft_strrchr(const char *str, int c);
char	**ft_split(char const *s, char c);
char	*ft_strjoin2(char *s1, char *s2);
char	*ft_strjoin(char *s, char c);
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	**read_map(int fd);
int		check_exit(t_data *pd, int key);
int		moveplayer(int key, t_data *pd);
int		ft_strcmp(char *s1, char *s2);
int		right(t_data *pd, int key);
int		down(t_data *pd, int key);
int		left(t_data *pd, int key);
int		ft_strlen(const char *s);
int		up(t_data *pd, int key);
int		destroynotify(int des);
#endif
