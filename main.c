/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mspinnet <mspinnet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 12:56:14 by mspinnet          #+#    #+#             */
/*   Updated: 2021/02/17 17:04:00 by mspinnet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);
int		ft_strcmp(const char *s1, const char *s2);
ssize_t	ft_write(int fd, const void *buf, int len);
ssize_t	ft_read(int fd, void *buf, int len);
char	*ft_strdup(const char *str);

int		main(void)
{
	printf("---------------------------ft_strlen---------------------------\n\n");
	printf("ft_strlen: |%lu|\n", ft_strlen("hello world!!!"));
	printf("___strlen: |%lu|\n", strlen("hello world!!!"));
	printf("\n---------------------------ft_strcpy---------------------------\n\n");
	char	str_cpy[] = "hello world!!!";
	char	str_cpy2[] = "hello world!!!";
	char	cpy1[100];
	char	cpy2[100];
	// char	*cpy1;
	// char	*cpy2;
	// cpy1 = malloc(sizeof(char) * ft_strlen(str_cpy) + 1);
	// cpy2 = malloc(sizeof(char) * ft_strlen(str_cpy2) + 1);
	printf("ft_strcpy: |%s|\n", ft_strcpy(cpy1, str_cpy));
	printf("___strcpy: |%s|\n", strcpy(cpy2, str_cpy2));
	printf("\n---------------------------ft_strcmp---------------------------\n\n");
	char	dst[] = "abcd";
	char	src[] = "abcd";
	printf("ft_strcmp: |%d|\n", ft_strcmp(dst, src));
	printf("___strcmp: |%d|\n", strcmp(dst, src));
	printf("\n---------------------------ft_write----------------------------\n\n");
	char	ft_w[] = "ft_write\n";
	char	w[] = "sistem write\n";
	ft_write(1, &ft_w, ft_strlen(ft_w));
	write(1, &w, strlen(w));
	errno = 0;
	ft_write(1, NULL, 1);
	printf("ft_write errno: %d - %s\n", errno, strerror(errno));
	errno = 0;
	write(1, NULL, 1);
	printf("___write errno: %d - %s\n", errno, strerror(errno));
	printf("\n---------------------------ft_read-----------------------------\n\n");
	int		ft_fd = open("./main.c", O_RDONLY);
	int		fd = open("./main.c", O_RDONLY);
	char	str[10000];
	printf("ft_read: |%zd|\n", ft_read(ft_fd, &str, 10000));
	printf("___read: |%zd|\n", read(fd, &str, 10000));
	errno = 0;
	ft_read(-5, &str, 10000);
	printf("ft_read errno: %d - %s\n", errno, strerror(errno));
	errno = 0;
	read(-5, &str, 10000);
	printf("___read errno: %d - %s\n", errno, strerror(errno));
	printf("\n---------------------------ft_strdup---------------------------\n\n");
	char	str_dup[] = "alsdljglkajsdlgjkhasldjbgnalkjsfnglkjngljSDGLKJsdlgjaslgjk";
	char	*ft_dup;
	char	*dup;
	ft_dup = ft_strdup(str_dup);
	dup = strdup(str_dup);
	printf("ft_strdup: |%s|\n", ft_dup);
	printf("___strdup: |%s|\n", dup);
	return (0);
}