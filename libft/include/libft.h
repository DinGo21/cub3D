/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: disantam <disantam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 19:10:53 by disantam          #+#    #+#             */
/*   Updated: 2024/06/12 17:16:20 by disantam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <strings.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

/*Checks if a character is alphabetic.*/
int		ft_isalpha(int c);

/*Checks if a character is decimal digit.*/
int		ft_isdigit(int c);

/*Checks if a character is alphanumeric.*/
int		ft_isalnum(int c);
/*Checks if a character is ASCII.*/
int		ft_isascii(int c);

/*Checks if a character is printable.*/
int		ft_isprint(int c);

/*Computes the length of a string.*/
size_t	ft_strlen(const char *s);

/**
 * Writes `len` bytes of value `c` (converted to an
 * unsigned char) to the string `b`.
 * 
 * @param b
 * @param c
 * @param len
*/
void	*ft_memset(void *b, int c, size_t len);

/**
 * Copies up to `dstsize` - 1 characters from the string
 * `src` to `dst`, NUL-terminating the result if `dstsize` is not 0.
 * 
 * @param dst
 * @param src
 * @param dstsize
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * Appends string `src` to the end of `dst`. It will append at most
 * dstsize - strlen(dst) - 1 characters. It will then NUL-
 * terminate, unless `size` is 0 or the original `dst` string 
 * was longer than `size`.
 * 
 * @param dst
 * @param src
 * @param size
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/**
 * locates the first occurrence of `c` (converted to a
 * char) in the string pointed to by `s`.  The terminating null character is
 * considered to be part of the string; therefore if `c` is '\0', the func-
 * tions locate the terminating '\0'.
 * 
 * @param s
 * @param c
*/
char	*ft_strchr(const char *s, int c);

/**
 * Identical to strchr(), except it locates the
 * last occurrence of c.
 * 
 * @param s
 * @param c
*/
char	*ft_strrchr(const char *s, int c);

/*Compares not more than `n` characters.*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * Returns a pointer to the byte located, or NULL if
 * no such byte exists within `n` bytes.
 * 
 * @param s
 * @param c
 * @param n
*/
void	*ft_memchr(const void *s, int c, size_t n);

/**
 * Returns zero if the two strings are identical, otherwise
 * returns the difference between the first two differing bytes
 * (treated as unsigned char values, so that '\200' is greater than '\0',
 * for example).
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * locates the first occurrence of the null-terminated string `needle` in
 * the string `haystack`, where not more than `len` characters are searched.
 * Characters that appear after a `\0' character are not searched.
 * 
 * @param haystack
 * @param needle
 * @param len
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/**
 * Converts the initial portion of the string pointed to by `str` to int rep-
 * resentation.
 * 
 * @param str
*/
int		ft_atoi(const char *str);

/**
 * Contiguously allocates enough space for `count` objects that are `size`
 * bytes of memory each and returns a pointer to the allocated memory. 
 * The allocated memory is filled with bytes of value zero.
 * 
 * @param count
 * @param size
*/
void	*ft_calloc(size_t count, size_t size);

/**
 * Allocates sufficient memory for a copy of the string `s1`, does the
 * copy, and returns a pointer to it.
 * 
 * @param s1
*/
char	*ft_strdup(const char *s1);

/**
 * Allocates and returns a substring from string `s`. The substring starts
 * from the index `start`and has a maximum length `len`.
 * 
 * @param s
 * @param start
 * @param len
*/
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * Allocates and returns a new string, formd by the concatenation of `s1`
 * and `s2`.
 * 
 * @param s1
 * @param s2
*/
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * Writes `n` zeroed bytes to the string `s`.  If `n` is zero, bzero() does
 * nothing.
 * 
 * @param s
 * @param n
*/
void	ft_bzero(void *s, size_t n);

/**
 * Copies `n` bytes from memory area `src` to memory area `dst`. If dst and
 * `src` overlap, behavior is undefined. Applications in which `dst` 
 * and `src` might overlap should use memmove() instead.
 * 
 * @param dst
 * @param src
 * @param n
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * Copies `len` bytes from string `src` to string `dst`. The two strings may
 * overlap; the copy is always done in a non-destructive manner.
 * 
 * @param dst
 * @param src
 * @param len
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * Converts a lower-case letter to the corresponding upper-case letter. 
 * The argument must be representable as an unsigned char or the value of EOF.
*/
int		ft_toupper(int c);

/**
 * Converts an upper-case letter to the corresponding lower-case letter.
 * The argument must be representable as an unsigned char or the value of EOF.
*/
int		ft_tolower(int c);

/**
 * Removes all `set` characters from the beginning and the end of `s1`, until
 * it finds a character not belonging to `set`.
 * 
 * @param s1
 * @param set
*/
char	*ft_strtrim(char const *s1, char const *set);

/**
 * Allocates an array resulting from splitting `s` into substrings, divided
 * by `c` character as a delimiter.
 * 
 * @param s
 * @param c
*/
char	**ft_split(char	const *s, char c);

/**
 * Converts `n` int value to string resentation.
 * 
 * @param n
*/
char	*ft_itoa(int n);

/**
 * To each character from `s`, applies `f` function giving as parameters the
 * index of each character and the character itself. Returns a new string
 * resulting from the successive use of `f`.
 * 
 * @param s
 * @param f
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * To each character from `s`, applies `f` function giving as parameters the
 * index of each character including the address, which could be modified if 
 * necessary.
 * 
 * @param s
 * @param f
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/**
 * Sends a character to the specified file descriptor.
 * 
 * @param c
 * @param fd 
*/
void	ft_putchar_fd(char c, int fd);

/**
 * Sends a string to the specified file descriptor.
 * 
 * @param s
 * @param fd
*/
void	ft_putstr_fd(char *s, int fd);

/**
 * Sends a string to the specified file descriptor, followed
 * by a newline.
 * 
 * @param s
 * @param fd
*/
void	ft_putendl_fd(char *s, int fd);

/**
 * Sends a number to the specified file descriptor.
 * 
 * @param n
 * @param fd
*/
void	ft_putnbr_fd(int n, int fd);

#endif
