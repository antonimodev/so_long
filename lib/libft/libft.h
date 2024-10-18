/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonimo <antonimo@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 15:22:19 by antonimo          #+#    #+#             */
/*   Updated: 2024/09/24 13:14:20 by antonimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <ctype.h>
# include <stdlib.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
#  endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_pipe
{
	int				read_pipe;
	int				write_pipe;
}	t_pipe;

/**
 * @brief Verifies if the given value is an alphabetic character.
 * 
 * @param c The character to be checked.
 * @return int Returns non-zero if the character is an alphabetic character,
 *  and zero otherwise.
 */
int		ft_isalpha(int c);

/**
 * @brief Verifies if the given value is a digit.
 * 
 * @param c The character to be checked.
 * @return int Returns non-zero if the character is a digit, and zero otherwise.
 */
int		ft_isdigit(int c);

/**
 * @brief Verifies if the given value is an alphabetic character or a digit.
 * 
 * @param c The character to be checked.
 * @return int Returns non-zero if the character is an alphabetic 
 * character or a digit, and zero otherwise.
 */
int		ft_isalnum(int c);

/**
 * @brief Verifies if the given value is a valid ASCII character.
 * 
 * @param c The character to be checked.
 * @return int Returns non-zero if the character is a valid ASCII character,
 *  and zero otherwise.
 */
int		ft_isascii(int c);

/**
 * @brief Verifies if the given value is a printable character.
 * 
 * @param c The character to be checked.
 * @return int Returns non-zero if the character is a printable character,
 *  and zero otherwise.
 */
int		ft_isprint(int c);

/**
 * @brief Returns the length of the string.
 * 
 * @param s The string to be measured.
 * @return size_t Returns the length of the string.
 */
int		ft_strlen(const char *s);

/**
 * @brief Fills the first 'n' bytes of the memory area pointed to by
 *  'ptr' with the constant byte 'value'.
 * @param ptr A pointer to the memory area to be filled.
 * @param value The constant byte to fill the memory area.
 * @param n The number of bytes to be filled.
 * @return void* Returns a pointer to the memory area 'ptr'.
 */
void	*ft_memset(void *ptr, int value, size_t n);

/**
 * @brief Fills the first 'n' bytes of the memory area pointed
 *  to by 'ptr' with zeros.
 * @param ptr A pointer to the memory area to be filled.
 * @param n The number of bytes to be filled.
 */
void	ft_bzero(void *ptr, size_t n);

/**
 * @brief Copies 'n' bytes from memory area 'src' to memory area 'dst'.
 * 
 * @param dst The destination where the content is to be copied.
 * @param src The source from where the content is to be copied.
 * @param n The number of bytes to be copied.
 * @return void* Returns a pointer to 'dst'.
 */
void	*ft_memcpy(void *dst, const void *src, size_t n);

/**
 * @brief Copies 'n' bytes from memory area 'src' to memory area 'dst', 
 * even if the memory areas overlap.
 * @param dst The destination where the content is to be copied.
 * @param src The source from where the content is to be copied.
 * @param n The number of bytes to be copied.
 * @return void* Returns a pointer to 'dst'.
 */
void	*ft_memmove(void *dst, const void *src, size_t n);

/**
 * @brief Copies up to 'n' characters from the string 'src' to 'dst'.
 * 
 * @param dst The destination where the content is to be copied.
 * @param src The source from where the content is to be copied.
 * @param n The number of characters to be copied.
 * @return size_t Returns the total length of 'src'.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t n);

/**
 * @brief Appends the string 'src' to the end of 'dst', 
 * but not more than 'n' characters in total are written to 'dst',
 *  including the NULL terminator.
 * @param dst The destination string.
 * @param src The source string.
 * @param n The total number of characters to be written to 'dst', 
 * including the NULL terminator.
 * @return size_t Returns the total length of 'dst' after the concatenation.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t n);

/**
 * @brief Converts a given letter to uppercase.
 * 
 * @param c The character to be converted.
 * @return int Returns the converted character, or the original 
 * character if it was not a lowercase letter.
 */
int		ft_toupper(int c);

/**
 * @brief Converts a given letter to lowercase.
 * 
 * @param c The character to be converted.
 * @return int Returns the converted character,
 * or the original character if it was not an uppercase letter.
 */
int		ft_tolower(int c);

/**
 * @brief Locates the first occurrence of 'chr' in the string
 *  pointed to by 'str'.
 * @param str The string to be scanned.
 * @param chr The character to be located.
 * @return char* Returns a pointer to the located character, or NULL
 *  if the character does not appear in the string.
 */
char	*ft_strchr(const char *str, int chr);
/**
 * @brief Locates the last occurrence of `chr` in the string pointed to by `str`.
 * 
 * @param str The string to be scanned.
 * @param chr The character to be located. It is passed as its int promotion,
 *  but it is internally converted back to char.
 * @return char* Returns a pointer to the located character,
 *  or NULL if the character does not appear in the string.
 */
char	*ft_strrchr(const char *str, int chr);

/**
 * @brief Compares at most the first `n` bytes of `s1` and `s2`.
 * 
 * @param s1 The first string to be compared.
 * @param s2 The second string to be compared.
 * @param n The maximum number of characters to be compared.
 * @return int Returns an integer less than, equal to, or greater than
 *  zero if `s1` is found, respectively, to be less than, to match,
 *  or be greater than `s2`.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Scans the initial `n` bytes of the memory area pointed to by 
 * `str` for the first occurrence of `c`.
 * @param str The memory area to be scanned.
 * @param c The value to be searched. It is passed as its int promotion, 
 * but it is internally converted back to unsigned char.
 * @param n The number of bytes to be scanned.
 * @return void* Returns a pointer to the matching byte, 
 * or NULL if the character does not occur in the given memory area.
 */
void	*ft_memchr(const void *str, int c, size_t n);

/**
 * @brief Compares the first `n` bytes of the memory areas `s1` and `s2`.
 * 
 * @param s1 The first memory area.
 * @param s2 The second memory area.
 * @param n The number of bytes to be compared.
 * @return int Returns an integer less than, equal to, or greater than zero if
 * `s1`
 * is found, respectively, to be less than, to match, or be greater than `s2`.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Locates the first occurrence of the null-terminated string `needle`
 *   in the string `haystack`, where not more than `n` characters are searched.
 * @param haystack The string to be scanned.
 * @param needle The string to be searched within `haystack`.
 * @param n The maximum number of characters to be searched.
 * @return char* Returns a pointer to the first character of 
 * the first occurrence of `needle`, or NULL if `needle` is not found.
 */
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);

/**
 * @brief Converts the initial portion of the string
 * pointed to by `str` to int representation.
 * @param str The string to be converted.
 * @return int Returns the converted integral number as an int value.
 * If no valid conversion could be performed, it returns zero.
 */
int		ft_atoi(const char *str);

/**
 * @brief Allocates memory for an array of `n` elements,
 *  each of them `size` bytes long, and initializes all its bits to zero.
 * @param n The number of elements to be allocated.
 * @param size The size of elements.
 * @return void* Returns a pointer to the allocated memory,
 *  or NULL if the allocation fails.
 */
void	*ft_calloc(size_t n, size_t size);
/**
 * @brief Allocates memory and copies the string 's' into that memory, 
 * returning a pointer to it.
 * @param s The string to be duplicated.
 * @return char* Returns a pointer to the newly allocated string,
 *  or NULL if the allocation failed.
 */
char	*ft_strdup(const char *s1);

/**
 * @brief Allocates memory and copies a substring from the string 's'
 *  into that memory, starting at 'start' and of maximum size 'len'.
 * The substring is also NULL-terminated.
 * @param s The string from which to create the substring.
 * @param start The index in 's' where the substring starts.
 * @param len The maximum length of the substring.
 * @return char* Returns a pointer to the newly allocated substring,
 * or NULL if the allocation failed.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);
/**
 * @brief Joins two strings 's1' and 's2' into a new string.
 * 
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return char* Returns a new string which is the result of the concatenation,
 *  or NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Trims the beginning and end of 's1'
 * with the characters contained in 'set'.
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return char* Returns the trimmed string, or NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Splits 's' into an array of strings according to the delimiter 'c'.
 * 
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return char** Returns an array of the substrings,
 * or NULL if the allocation fails.
 * */
char	**ft_split(char const *s, char c);

/**
 * @brief Converts an integer 'n' to a string.
 * 
 * @param n The integer to be converted.
 * @return char* Returns the string representing the integer,
 * or NULL if the allocation fails.
 * */
char	*ft_itoa(int n);

/**
 * @brief Applies the function 'f' to each character of the string 's'
 * to create a new string resulting from successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character of 's'.
 * @return char* Returns the string created from the successive applications
 *  of 'f', or NULL if the allocation fails.
 **/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Applies the function 'f' to each character of the string 's'.
 * 
 * @param s The string on which to iterate.
 * @param f The function to apply to each character of 's'.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

/**
 * @brief Outputs the character 'c' to the given file descriptor.
 * 
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor.
 * 
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Outputs the string 's' to the given file descriptor,
 * followed by a newline.
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer 'n' to the given file descriptor.
 * 
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Creates a new list element with the provided content.
 *
 * This function allocates (with malloc(3)) and returns a new
 * element. The variable 'content' is initialized with the value 
 * of the parameter 'content'. The variable 'next' is initialized to NULL.
 *
 * @param content The content to be included in the new list element.
 * @return The newly created list element.
 */

t_list	*ft_lstnew(void *content);
/**
 * @brief Adds the element 'new' at the beginning of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Counts the number of elements in a list.
 * @param lst The beginning of the list.
 * @return Size of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Finds the last element of the list.
 * @param lst The beginning of the list.
 * @return Last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Adds the element 'new' at the end of the list.
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Takes as a parameter an element and frees the memory of
 * the element’s content using
 * the function 'del' given as a parameter and free the element.
 * @param lst The element to free.
 * @param del Address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Deletes and frees the given element and every successor of that
 *  element, using the function 'del' and free.
 * @param lst The address of a pointer to an element.
 * @param del Address of the function used to delete the content.
 */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Iterates the list 'lst' and applies the function 
 * 'f' to the content of each element.
 * @param lst The address of a pointer to an element.
 * @param f The address of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));
/**
 * @brief Transforms a linked list by applying function 'f' to each element.
 * 
 * @param lst The original linked list.
 * @param f The function to apply to each element of 'lst'. This function 
 * should take a pointer to an element and return a pointer to a new element.
 * @param del The function to delete an element if needed. This function 
 * should take a pointer to an element.
 * @return t_list* A new linked list with each element transformed by 'f'.
 *  If an error occurs, NULL is returned.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a matrix with 'n' rows.
 *
 * This function allocates memory for a matrix with 'n' rows, initializing
 * all elements to NULL.
 *
 * @param n The number of rows in the matrix.
 * @return A pointer to the newly created matrix, or NULL if an error occurs.
 */
char	**create_matrix(int n);

/**
 * @brief Frees the memory allocated for a matrix.
 *
 * This function frees the memory of each row in the matrix and then frees
 * the matrix itself.
 *
 * @param matrix The matrix to be freed.
 */
void	free_matrix(char **matrix);

/**
 * @brief Calculates the number of rows in a matrix.
 *
 * This function counts the number of non-NULL rows in the matrix.
 *
 * @param matrix The matrix whose rows are to be counted.
 * @return The number of rows in the matrix.
 */
int		ft_matrixlen(char **matrix);
/**
 * @brief Creates a pipe and returns a structure containing the file descriptors.
 *
 * This function creates a pipe using the `pipe` system call and stores the
 * read and write file descriptors in a `t_pipe` structure. If the pipe creation
 * fails, it prints an error message and exits the program.
 *
 * @return A `t_pipe` structure containing the read and write file descriptors.
 */
t_pipe	create_pipe(void);
/**
 * @brief Extracts the remaining part of the line from the static buffer.
 *
 * @param stat_buff The static buffer containing the line.
 * @return A pointer to the remaining part of the line.
 */
char	*ft_line_remaining(char *stat_buff);

/**
 * @brief Extracts the line from the static buffer.
 *
 * @param stat_buff The static buffer containing the line.
 * @return A pointer to the extracted line.
 */
char	*ft_line(char *stat_buff);

/**
 * @brief Reads a specified buffer size from the file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @param stat_buff The static buffer to store the read data.
 * @return A pointer to the updated static buffer.
 */
char	*ft_read_buffersize(int fd, char *stat_buff);

/**
 * @brief Gets the next line from the file descriptor.
 *
 * @param fd The file descriptor to read from.
 * @return A pointer to the next line read from the file descriptor.
 */
char	*get_next_line(int fd);

/**
 * @brief Checks if a character is present in a string.
 *
 * This function searches for the first occurrence of the character `chr`
 * in the string `str`.
 *
 * @param str The string to be searched.
 * @param chr The character to search for.
 * @return int Returns 1 if the character is found, 0 otherwise.
 */
int		check_strchr(char *str, char chr);

/**
 * @brief Joins two strings into a new string.
 *
 * This function concatenates the strings `s1` and `s2` into a new string.
 * The new string is dynamically allocated and should be freed by the caller.
 *
 * @param s1 The first string.
 * @param s2 The second string.
 * @return char* Returns a pointer to the newly allocated string, or NULL if
 *  the allocation fails.
 */
char	*ft_strjoin_gnl(char *s1, char *s2);
#endif
