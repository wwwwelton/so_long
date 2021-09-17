/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wleite <wleite@student.42sp.org.br>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/27 19:25:46 by wleite            #+#    #+#             */
/*   Updated: 2021/09/17 16:28:18 by wleite           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 128
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

//Part 1 - Libc functions

/**
 * @brief Converts the string argument nptr to an integer (type int).
 *
 * @param nptr This is the string representation of an integral number.
 * @return This function returns the converted integral number as an int value.
 * If no valid conversion could be performed, it returns zero.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Checks if the passed character is alphanumeric.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is a digit or a letter,
 * else it returns 0.
 */
int		ft_isalnum(int c);

/**
 * @brief Checks if the passed character is alphabetic.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is an alphabet, else it
 * returns 0.
 */
int		ft_isalpha(int c);

/**
 * @brief Checks if the passed character is ASCII.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is an ASCII, else it
 * returns 0.
 */
int		ft_isascii(int c);

/**
 * @brief Checks if the passed character is a decimal digit character. Decimal
 * digits are (numbers) − 0 1 2 3 4 5 6 7 8 9.
 *
 * @param c This is the character to be checked.
 * @return This function returns non-zero value if c is a digit, else it
 * returns 0.
 */
int		ft_isdigit(int c);

/**
 * @brief Checks whether the passed character is printable. A printable
 * character is a character that is not a control character. Printable
 * characters are >= SPACE and <= ~.
 *
 * @param c This is the character to be checked.
 * @return This function returns a non-zero value(true) if c is a printable
 * character else, zero (false).
 */
int		ft_isprint(int c);

/**
 * @brief Compares the first len bytes of memory area b1 and memory area b2.
 *
 * @param b1 This is the pointer to a block of memory.
 * @param b2 This is the pointer to a block of memory.
 * @param len This is the number of bytes to be compared.
 * @return if Return value < 0 then it indicates b1 is less than b2.
 * if Return value > 0 then it indicates b2 is less than b1.
 * if Return value = 0 then it indicates b1 is equal to b2.
 */
int		ft_memcmp(const void *b1, const void *b2, size_t len);

/**
 * @brief Compares at most the first len bytes of s1 and s2. Characters	that
 * appear after a \\0 character are not compared.
 *
 * @param s1 This is the first string to be compared.
 * @param s2 This is the second string to be compared.
 * @param len The maximum number of characters to be compared.
 * @return if Return value < 0 then it indicates s1 is less than s2.
 * if Return value > 0 then it indicates s2 is less than s1.
 * if Return value = 0 then it indicates s1 is equal to s2.
 */
int		ft_strncmp(const char *s1, const char *s2, size_t len);

/**
 * @brief Converts a given letter to lowercase. The argument must be
 * representable as an unsigned char.
 *
 * @param c This is the letter to be converted to lowercase.
 * @return This function returns lowercase equivalent to c, if such value
 * exists, else c remains unchanged. The value is returned as an int value
 * that can be implicitly casted to char.
 */
int		ft_tolower(int c);

/**
 * @brief Converts lowercase letter to uppercase. The argument must be
 * representable as an unsigned char.
 *
 * @param c This is the letter to be converted to uppercase.
 * @return This function returns uppercase equivalent to c, if such value
 * exists, else c remains unchanged. The value is returned as an int value
 * that can be implicitly casted to char.
 */
int		ft_toupper(int c);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param s This is the C string to be scanned.
 * @param c This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the first occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Searches for the last occurrence of the character c
 * (an unsigned char) in the string pointed to by the argument s. The
 * terminating null	character is considered	part of	the string; therefore
 * if c is \\0, the functions locate the terminating \\0.
 *
 * @param s This is the C string to be scanned.
 * @param c This is the character to be located. It is passed as int,
 * but it is internally converted back to char.
 * @return This returns a pointer to the last occurrence of the character c
 * in the string s, or NULL if the character is not found.
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Returns a pointer to a null-terminated byte string, which is a
 * duplicate of the string pointed to by str. The returned pointer must be
 * passed to free to avoid a memory leak. If an error occurs, a null pointer
 * is returned and errno may be set.
 *
 * @param s Pointer to the null-terminated byte string to duplicate.
 * @return A pointer to the newly allocated string, or a null pointer
 * if an error occurred.
 */
char	*ft_strdup(const char *str);

/**
 * @brief Locates the first occurrence of the null-terminated string little
 * in the string big, where not more than len characters are searched.
 * Characters that appear after a \\0 character are not searched.
 *
 * @param big This is the C string to be scanned.
 * @param little This is the C string to be searched inside big.
 * @param len The maximum number of characters to be searched.
 * @return If little is an empty string, big is returned; if little occurs
 * nowhere in big, NULL is returned; otherwise a pointer to the first
 * character of the first occurrence of little is returned.
 */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Appends string src to the end of dst. It will append at most dstsize
 * - strlen(dst) - 1 characters. It will then NUL-terminate, unless dstsize is
 * 0 or the original dst string was longer than dstsize. If the src and dst
 * strings overlap, the behavior is undefined.
 *
 * @param dst This is pointer to the destination array, which should contain
 * a C string, and should be large enough to contain the concatenated
 * resulting string.
 * @param src This is the string to be appended.
 * @param dstsize Full size of the destination buffer.
 * @return The total length of the string they tried to create. That means the
 * initial length of dst + the length of src.
 */
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/**
 * @brief Copies up to dstsize - 1 characters from the string src to dst,
 * NUL-terminating the result if dstsize is not 0.
 *
 * @param dst This is the pointer to the destination array where the content
 * is to be copied.
 * @param src This is the string to be copied.
 * @param dstsize Full size of the destination buffer.
 * @return The total length of the string they tried to create. That means the
 * length of src.
 */
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/**
 * @brief Computes the length of the string s up to, but not including the
 * terminating null character. Example: ft_strlen("1234") => 4
 *
 * @param s This is the string whose length is to be found.
 * @return This function returns the length of string.
 */
size_t	ft_strlen(const char *s);

/**
 * @brief Writes len zero bytes to the buffer b. If len is zero, bzero()
 * does nothing.
 *
 * @param b Points to a buffer that zeros are copied into.
 * @param len The number of zeros to be copied into the buffer.
 */
void	ft_bzero(void *b, size_t len);

/**
 * @brief Allocates space for number objects, each size bytes in length.
 * The result is identical to calling malloc with an argument of number * size,
 * with the exception that the allocated memory is explicitly initialized
 * to zero bytes.
 *
 * @param number This is the number of elements to be allocated.
 * @param size This is the size of elements. ( sizeof(type) )
 * @return Returns a pointer to the allocated memory, or NULL if the request
 * fails.
 */
void	*ft_calloc(size_t number, size_t size);

/**
 * @brief Searches for the first occurrence of the character c
 * (an unsigned char) in the first len bytes of the string pointed to, by
 * the argument b.
 *
 * @param b This is the pointer to the block of memory where the search
 * is performed.
 * @param c This is the value to be passed as an int, but the function
 * performs a byte per byte search using the unsigned char conversion of this
 * value.
 * @param len This is the number of bytes to be analyzed.
 * @return This function returns a pointer to the matching byte or NULL if the
 * character does not occur in the given memory area.
 */
void	*ft_memchr(const void *b, int c, size_t len);

/**
 * @brief Copies len bytes from memory area src to memory area dst.
 *If src and dst overlap, the results are not defined.

 * @param dst This is pointer to the destination array where the content is
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is pointer to the source of data to be copied, type-casted
 * to a pointer of type void*.
 * @param len This is the number of bytes to be copied.
 * @return This function returns a pointer to destination, which is dst.
 */
void	*ft_memcpy(void *dst, const void *src, size_t len);

/**
 * @brief Copies len characters from src to dst, the copy is always done
 * in a non-destructive manner.
 *
 * @param dst This is a pointer to the destination array where the content is
 * to be copied, type-casted to a pointer of type void*.
 * @param src This is a pointer to the source of data to be copied,
 * type-casted to a pointer of type void*.
 * @param len This is the number of bytes to be copied.
 * @return This function returns a pointer to the destination, which is dst.
 */
void	*ft_memmove(void *dst, const void *src, size_t len);

/**
 * @brief Copies the character c (an unsigned char) to the first len characters
 * of the string pointed to, by the argument dest.
 *
 * @param dest This is a pointer to the block of memory to fill.
 * @param c This is the value to be set. The value is passed as an int, but
 * the function fills the block of memory using the unsigned char conversion
 * of this value.
 * @param len This is the number of bytes to be set to the value.
 * @return This function returns a pointer to the memory area dest.
 */
void	*ft_memset(void *dest, int c, size_t len);

//Part 2 - Additional functions

/**
 * @brief Allocates (with malloc(3)) and returns a string representing the
 * integer received as an argument including negative numbers.
 *
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if the allocation fails.
 */
char	*ft_itoa(int n);

/**
 * @brief Allocates (with malloc(3)) and returns a new string, which is the
 * result of the concatenation of ’s1’ and ’s2’.
 *
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if the allocation fails.
 */
char	*ft_strjoin(char const *s1, char const *s2);

/**
 * @brief Applies the function ’f’ to each character of the string ’s’ to
 * create a new string (with malloc(3)) resulting from successive applications
 * of ’f’.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the successive applications of ’f’. Returns
 * NULL if the allocation fails.
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/**
 * @brief Allocates (with malloc(3)) and returns a copy of ’s1’ with the
 * characters specified in ’set’ removed from the beginning and the end of
 * the string.
 *
 * @param s1 The string to be trimmed.
 * @param set The reference set of characters to trim.
 * @return The trimmed string. NULL if the allocation fails.
 */
char	*ft_strtrim(char const *s1, char const *set);

/**
 * @brief Allocates (with malloc(3)) and returns a substring from the string
 * ’s’. The substring begins at index ’start’ and is of maximum size ’len’.
 *
 * @param s The string from which to create the substring.
 * @param start The start index of the substring in the string ’s’.
 * @param len The maximum length of the substring.
 * @return The substring. NULL if the allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/**
 * @brief Allocates (with malloc(3)) and returns an array of strings obtained
 * by splitting ’s’ using the character ’c’ as a delimiter. The array must be
 * ended by a NULL pointer.
 *
 * @param s The string to be split.
 * @param c The delimiter character.
 * @return The array of new strings resulting from the split. NULL if the
 * allocation fails.
 */
char	**ft_split(char const *s, char c);

/**
 * @brief Outputs the character ’c’ to the given file descriptor.
 *
 * @param c The character to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putchar_fd(char c, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor, followed by
 * a newline.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putendl_fd(char *s, int fd);

/**
 * @brief Outputs the integer ’n’ to the given file descriptor.
 *
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putnbr_fd(int n, int fd);

/**
 * @brief Outputs the string ’s’ to the given file descriptor.
 *
 * @param s The string to output.
 * @param fd The file descriptor on which to write.
 */
void	ft_putstr_fd(char *s, int fd);

/**
 * @brief Applies the function f to each character of the string passed as
 * argument, and passing its index as first argument. Each character is
 * passed by address to f to be modified if necessary.
 *
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*));

//Bonus part

/**
 * @brief Counts the number of elements in a list.
 *
 * @param lst The beginning of the list.
 * @return Length of the list.
 */
int		ft_lstsize(t_list *lst);

/**
 * @brief Returns the last element of the list.
 *
 * @param lst The beginning of the list.
 * @return Returns the last element of the list.
 */
t_list	*ft_lstlast(t_list *lst);

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content
 * of each element. Creates a new list resulting of the successive
 * applications of the function ’f’. The ’del’ function is used to delete the
 * content of an element if needed.
 *
 * @param lst The adress of a pointer to an element.
 * @param f The adress of the function used to iterate on the list.
 * @param del The adress of the function used to delete the content of an
 * element if needed.
 * @return The new list. NULL if the allocation fails.
 */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Allocates (with malloc(3)) and returns a new element. The variable
 * ’content’ is initialized with the value of the parameter ’content’. The
 * variable ’next’ is initialized to NULL.
 *
 * @param content The content to create the new element with.
 * @return The new element.
 */
t_list	*ft_lstnew(void *content);

/**
 * @brief Adds the element ’new’ at the end of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Adds the element ’new’ at the beginning of the list.
 *
 * @param lst The address of a pointer to the first link of a list.
 * @param new The address of a pointer to the element to be added to the list.
 */
void	ft_lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Deletes and frees the given element and every successor of that
 * element, using the function ’del’ and free(3). Finally, the pointer to
 * the list must be set to NULL.
 *
 * @param lst The adress of a pointer to an element.
 * @param del The adress of the function used to delete the content of the
 * element.
 */
void	ft_lstclear(t_list **lst, void (*del)(void*));

/**
 * @brief Takes as a parameter an element and frees the memory of the
 * element’s content using the function ’del’ given as a parameter and free
 * the element. The memory of ’next’ must not be freed.
 *
 * @param lst The element to free.
 * @param del The address of the function used to delete the content.
 */
void	ft_lstdelone(t_list *lst, void (*del)(void*));

/**
 * @brief Iterates the list ’lst’ and applies the function ’f’ to the content
 * of each element.
 *
 * @param lst The adress of a pointer to an element.
 * @param f  The adress of the function used to iterate on the list.
 */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Deallocates the pointer memory address previously allocated
 * by a call to calloc, malloc, or realloc.
 *
 * @param ptr This is the pointer address to a memory block previously
 * allocated with malloc, calloc or realloc to be deallocated.
 * If a null pointer is passed as argument, no action occurs.
 */
void	ft_free_ptr(void **ptr);

/**
 * @brief Searches for the first occurrence of the string
 * old_word in the string str and replaces with the string new_word.
 *
 * @param str This is the C string to be scanned.
 * @param old_word This is the string to be located inside str.
 * @param new_word This is the string to be replaced inside str.
 * @return Returns a new string with old_word replaced by new_word
 * or a duplicate of the string pointed to by str in case old_word
 * not found. If an error occurs, a null pointer is returned.
 */
char	*ft_str_replace(const char *str,
			const char *old_word, const char *new_word);

/**
 * @brief Converts lowercase letters of the string to uppercase.
 *
 * @param str This is the string to be converted to uppercase.
 * @return Returns the number of characters changed. Returns -1
 * if the string is NULL.
 */
int		ft_str_toupper(char *str);

/**
 * @brief Converts an unsigned char to a string allocated with malloc.
 *
 * @param c This is the unsigned char to be converted.
 * @return Returns a string, allocated with malloc with the character
 * passed to the parameter in the first position and '\\0' in the
 * second position.
 */
char	*ft_char_tostr(unsigned char c);

/**
 * @brief Allocates with malloc and returns a string representing the
 * unsigned integer in the base received as an argument.
 *
 * @param n The unsigned integer to convert.
 * @param base This is the string representing which base the
 * unsigned integer will be converted to. Example "0123456789" for base 10.
 * @return The string representing the unsigned integer in the base passed as an
 * argument. NULL if the allocation fails.
 */
char	*ft_uitoa_base(size_t n, const char *base);

/**
 * @brief Reads a line from a file descriptor
 *
 * @param fd File descriptor to read.
 * @return Return a string including \\n if is a line. In case of the file
 * dont have \\n return a string without \\n, NULL if the file is empty
 * or error occurred.
 */
char	*ft_get_next_line(int fd);

#endif
