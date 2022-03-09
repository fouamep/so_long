/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbouanan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 14:48:22 by fbouanan          #+#    #+#             */
/*   Updated: 2022/02/20 14:48:24 by fbouanan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_len(char const *s, char c)
{	
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static void	ft_free(char **ar, int k)
{
	int	i;

	i = 0;
	while (i < k)
	{
		free(ar[i]);
		i++;
	}
	free(ar);
}

static void	ft_size(char **ar, const char *s, char c)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c)
			j = i;
		while (s[i] != c && s[i])
			i++;
		if (i != j)
		{
			ar[k] = ft_substr(s, j, i - j);
			if (!ar[k])
				ft_free(ar, k);
			k++;
		}
	}
}

char	**ft_split(char const *s, char c)
{
	char	**ar;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	j = ft_len(s, c);
	ar = malloc(sizeof(char *) * (j + 1));
	if (!ar)
		return (NULL);
	ft_size(ar, s, c);
	ar[j] = NULL;
	return (ar);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putchar('-');
		ft_putchar('2');
		n = 147483648;
	}
	if (n >= 0 && n <= 9)
		ft_putchar(n + '0');
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(n * (-1));
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}
