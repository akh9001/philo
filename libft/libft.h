/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <akhalidy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 09:38:40 by akhalidy          #+#    #+#             */
/*   Updated: 2021/09/16 19:54:36 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# define BUFFER_SIZE 1000
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_cir_dlst
{
	int					id;
	int					data;
	struct s_cir_dlst	*prev;
	struct s_cir_dlst	*next;
}						t_cir_dlst;

char		**ft_split(char const *s, char c);
long long	ft_atoi(const char *str);
void		*ft_calloc(size_t count, size_t size);
int			ft_isalnum(int c);
int			ft_isdigit(int c);
char		*ft_strdup(const char *s1);
size_t		ft_strlcat(char *dst, const char *src, size_t size);
size_t		ft_strlcpy(char *dst, const char *src, size_t size);
size_t		ft_strlen(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_itoa(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
float		ft_atof(char **s, int i, float x, float signe);
char		**ft_free(char **ptr);
int			ft_split_num(char **s);
int			ft_isnumber(char *s, int *signe);
int			ft_char_frequency(char c, char *s);
int			ft_is_integer(char *s, int *signe);
int			ft_isinteger(char *str);
int			ft_check_int_range(char *str, int *number);
void		*ft_calloc(size_t count, size_t size);

/*
** Get next line function
*/

int			get_next_line(int fd, char **line);
int			ft_check_tmp(char *tmp, char **line, char **rest, char *buf);
char		*ft_strchr(const char *s, int c);
void		ft_bzero(void *s, size_t n);
char		*ft_strdup(const char *s1);
/*
** circular Doubly Linked List
*/

t_cir_dlst	*ft_cer_dlstnew(int data, int id);
t_cir_dlst	*ft_assign(t_cir_dlst **new);
void		ft_cer_dlstadd_back(t_cir_dlst **head, t_cir_dlst *new);
void		ft_cer_dlstdelone(t_cir_dlst *lst, void (*del)(void*));
void		ft_cer_dlstclear(t_cir_dlst **lst);
void		ft_cer_dlstprint(t_cir_dlst *lst);
int			ft_cer_dlst_size(t_cir_dlst *head);

#endif