/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmarcu <cmarcu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/05 15:21:08 by cmarcu            #+#    #+#             */
/*   Updated: 2021/07/20 16:29:36 by cmarcu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap_checker.h"

/*void	ft_bzero(char *s, size_t n)
{
	unsigned char	*p;
	size_t			a;

	p = (unsigned char *)s;
	a = 0;
	while (a < n)
	{
		p[a] = '\0';
		a++;
	}
}

int	delmem(char **p)
{
	if (p)
	{
		if (*p)
		{
			ft_bzero(*p, ft_strlen(*p));
			free(*p);
			*p = NULL;
			return (1);
		}
	}
	return (0);
}

int	mount_next_line(int re, char **re_acu, char **line)
{
	int		aux;
	char	*temp;

	if (re > 0)
		aux = 1;
	else
		aux = 0;
	temp = ft_substr(*re_acu, ft_strlen(*line) + aux, ft_strlen(*re_acu));
	delmem(re_acu);
	*re_acu = temp;
	if (re == 0)
	{
		delmem(re_acu);
		return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	int			re;
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	static char	*re_acu;

	re = 1;
	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!re_acu)
		re_acu = ft_strdup("");
	re = read(fd, buf, BUFFER_SIZE);
	while (re > 0 && !ft_strchr(re_acu, '\n'))
	{
		buf[re] = '\0';
		temp = ft_strjoin(re_acu, buf);
		delmem(&re_acu);
		re_acu = temp;
		//printf("Line inside gnl: %s\n", re_acu);
		re = read(fd, buf, BUFFER_SIZE);
	}
	if (re == 0)
		*line = ft_strdup(re_acu);
	else if (re > 0)
		*line = ft_substr(re_acu, 0, (ft_strchr(re_acu, '\n') - re_acu));
	else
		return (-1 * delmem(&re_acu));
	return (mount_next_line(re, &re_acu, line));
}*/

int	ft_negative(char **x, char **line)
{
	if (ft_strchr(*x, '\0'))
	{
		*line = ft_strdup(*x);
		free(*x);
		*x = NULL;
		return (0);
	}
	return (0);
}

int	ft_nbytesnegativo(ssize_t *nbytes, char **x)
{
	if (*nbytes < 0)
	{
		if (*x != NULL)
		{
			free(*x);
			*x = NULL;
		}
		return (-1);
	}
	return (0);
}

int	ft_aux(ssize_t nbytes, char **x, char **line)
{
	char	*tmp;
	char	*tmp2;

	if (!nbytes && !*x)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (ft_nbytesnegativo(&nbytes, &*x))
		return (-1);
	tmp = ft_strchr(*x, '\n');
	if (tmp)
	{
		*tmp = '\0';
		*line = ft_strdup(*x);
		tmp2 = ft_strdup(tmp + 1);
		free(*x);
		*x = tmp2;
		return (1);
	}
	else if (ft_negative(&*x, &*line))
		return (0);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	char		*buff;
	static char	*x[4096];
	ssize_t		nbytes;
	char		*tmp;

	buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	nbytes = read(fd, buff, BUFFER_SIZE);
	while (nbytes)
	{
		buff[nbytes] = '\0';
		if (!x[fd])
			x[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(x[fd], buff);
			free(x[fd]);
			x[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
		nbytes = read(fd, buff, BUFFER_SIZE);
	}
	free(buff);
	buff = NULL;
	return (ft_aux(nbytes, &x[fd], &*line));
}
