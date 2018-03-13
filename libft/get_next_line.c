/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpilotto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:55:23 by lpilotto          #+#    #+#             */
/*   Updated: 2016/01/12 12:28:29 by lpilotto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int		set_line(char **line, t_file *file)
{
	ssize_t		length;
	ssize_t		a;
	char		*i;

	if ((i = ft_strchr(file->buf, '\n')) == NULL)
	{
		*line = (ft_strlen(file->buf) == 0) ? NULL : ft_strdup(file->buf);
		return (0);
	}
	length = ft_strlen(file->buf) - ft_strlen(i);
	if ((*line = ft_strnew(length)) == NULL)
		return (-1);
	a = -1;
	if ((i = ft_strdup(i + 1)) == NULL)
		return (-1);
	while (++a < length)
		(*line)[a] = file->buf[a];
	free(file->buf);
	file->buf = i;
	return (1);
}

static int		process_on_t_file(char **line, char *buf, t_file *file)
{
	ssize_t			length;
	char			*i;

	length = 0;
	while (ft_strchr(file->buf, '\n') == NULL &&
		(length = read(file->fd, buf, BUFF_SIZE)) > 0)
	{
		i = file->buf;
		if ((file->buf = ft_strjoin(file->buf, buf)) == NULL)
			return (-1);
		free(i);
		ft_bzero(buf, BUFF_SIZE);
	}
	if (length == -1)
		return (-1);
	return (set_line(line, file));
}

static void		remove_file(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	if ((t_file *)(tmp->content) != NULL && ((t_file *)tmp->content)->fd == fd)
	{
		free(((t_file *)tmp->content)->buf);
		*list = tmp->next;
		free(tmp->content);
		free(tmp);
		return ;
	}
	while (tmp->next)
	{
		if (tmp->next->content != NULL &&
			((t_file *)tmp->next->content)->fd == fd)
		{
			free(((t_file *)tmp->next->content)->buf);
			tmp2 = tmp->next;
			tmp->next = tmp->next->next;
			free(tmp2);
			return ;
		}
	}
}

static t_file	*find_file(t_list **list, int fd)
{
	t_list	*tmp;
	t_list	*tmpnew;
	t_file	*tmpfile;

	tmp = *list;
	while (tmp)
	{
		if (tmp->content != NULL)
		{
			if (((t_file *)tmp->content)->fd == fd)
				return ((t_file *)tmp->content);
		}
		tmp = tmp->next;
	}
	if ((tmpfile = (t_file *)malloc(sizeof(t_file))) == NULL)
		return (NULL);
	tmpfile->fd = fd;
	if ((tmpnew = ft_lstnew(tmpfile, sizeof(tmpfile))) == NULL)
		return (NULL);
	free(tmpfile);
	if ((((t_file *)tmpnew->content)->buf = ft_strnew(0)) == NULL)
		return (NULL);
	ft_lstadd(list, tmpnew);
	return ((t_file *)tmpnew->content);
}

int				get_next_line(int const fd, char **line)
{
	static t_list	*list = NULL;
	char			*buf;
	t_file			*tmp;
	int				tmp2;

	if (line == NULL || fd < 0)
		return (-1);
	if ((buf = ft_strnew(BUFF_SIZE)) == NULL)
		return (-1);
	if (list == NULL)
	{
		if ((list = ft_lstnew(NULL, 0)) == NULL)
			return (-1);
		if ((list->content = (t_file *)malloc(sizeof(t_file))) == NULL)
			return (-1);
		((t_file *)list->content)->fd = fd;
		((t_file *)list->content)->buf = ft_strnew(0);
	}
	if ((tmp = find_file(&list, fd)) == NULL)
		return (-1);
	tmp2 = process_on_t_file(line, buf, tmp);
	if (tmp2 <= 0)
		remove_file(&list, fd);
	free(buf);
	return (tmp2);
}
