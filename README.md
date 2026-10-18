*This project has been created as part of the 42 curriculum by sfaraji.*

# Libft

## Description

Libft is my first C library. The goal is to understand how standard C
functions work by rewriting them, and to build reusable utilities for future
42 projects. It is compiled into the static library `libft.a` and follows the
42 Norm.

## Instructions

```sh
make          # builds libft.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean + all
```

Use it in a program with:

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lft
```

## Library description

`libft.a` is a static library: the `ar` command packs all the object files
into one archive, and the linker copies into a program only the functions
that the program uses. The library has 43 functions in three parts, declared
in `libft.h`:

1. **Libc functions:** my own versions of standard C functions, with the
   `ft_` prefix and the same prototypes and behavior as the originals.
2. **Additional functions:** string, conversion and output functions that are
   not in the libc, or that are a different version of one.
3. **Linked lists:** functions that work on the `t_list` structure
   (`content` and `next`).

Technical choices:

- The functions copied from the libc behave like the originals, including
  crashing on `NULL` where the original does (undefined behavior). The
  functions with no libc original check their pointers.
- `ft_memmove` copies forward or backward depending on the position of the
  two areas, so overlapping memory is handled correctly.
- `ft_calloc` returns `NULL` if `nmemb * size` overflows.
- `ft_split` and `ft_lstmap` free everything they allocated before a failure
  and return `NULL`, so a failed allocation does not leak.
- `ft_lstadd_front` and `ft_lstadd_back` accept an empty list: the new node
  becomes the head.

## Functions

### Part 1 - Libc functions

| Function | What it does |
|---|---|
| `ft_isalpha` | Returns 1 if `c` is a letter, 0 otherwise. |
| `ft_isdigit` | Returns 1 if `c` is a digit, 0 otherwise. |
| `ft_isalnum` | Returns 1 if `c` is a letter or a digit, 0 otherwise. |
| `ft_isascii` | Returns 1 if `c` is an ASCII character (0 to 127), 0 otherwise. |
| `ft_isprint` | Returns 1 if `c` is a printable character, 0 otherwise. |
| `ft_toupper` | Converts a lowercase letter to uppercase. |
| `ft_tolower` | Converts an uppercase letter to lowercase. |
| `ft_strlen` | Returns the length of a string. |
| `ft_strlcpy` | Copies a string into a buffer of a given size and always terminates it. |
| `ft_strlcat` | Appends a string to another, within a given buffer size. |
| `ft_strchr` | Returns a pointer to the first occurrence of a character in a string. |
| `ft_strrchr` | Returns a pointer to the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings, up to `n` characters. |
| `ft_strnstr` | Finds a substring inside a string, within the first `len` characters. |
| `ft_strdup` | Returns a newly allocated copy of a string. |
| `ft_memset` | Fills a memory area with a byte. |
| `ft_bzero` | Sets a memory area to zero. |
| `ft_memcpy` | Copies `n` bytes from one memory area to another. |
| `ft_memmove` | Copies `n` bytes, and works correctly when the areas overlap. |
| `ft_memchr` | Finds the first occurrence of a byte in a memory area. |
| `ft_memcmp` | Compares two memory areas byte by byte. |
| `ft_calloc` | Allocates memory for an array and sets it to zero. |
| `ft_atoi` | Converts the beginning of a string to an `int`. |

### Part 2 - Additional functions

| Function | What it does |
|---|---|
| `ft_substr` | Returns a new substring of `s`, from index `start`, of at most `len` characters. |
| `ft_strjoin` | Returns a new string made of `s1` followed by `s2`. |
| `ft_strtrim` | Returns a copy of `s1` without the characters of `set` at the start and at the end. |
| `ft_split` | Splits a string with a delimiter character and returns a `NULL`-terminated array of strings. |
| `ft_itoa` | Converts an integer to a new string. |
| `ft_strmapi` | Applies a function to each character (with its index) and returns the new string. |
| `ft_striteri` | Applies a function to each character (with its index), directly on the string. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline to a file descriptor. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

### Part 3 - Linked lists

| Function | What it does |
|---|---|
| `ft_lstnew` | Creates a new node with the given content. |
| `ft_lstadd_front` | Adds a node at the beginning of the list. |
| `ft_lstadd_back` | Adds a node at the end of the list. |
| `ft_lstsize` | Counts the nodes of the list. |
| `ft_lstlast` | Returns the last node of the list. |
| `ft_lstdelone` | Frees the content of a node with `del`, then frees the node. |
| `ft_lstclear` | Deletes a node and all the nodes after it, then sets the list to `NULL`. |
| `ft_lstiter` | Applies a function to the content of every node. |
| `ft_lstmap` | Builds a new list from the results of a function applied to each node. |

## Resources

- Linux man pages, section 3 (`man 3 strlen`, `man 3 memmove`, ...)
- The GNU C Library reference manual
- Kernighan and Ritchie, *The C Programming Language*
- The 42 Norm
- Stack Overflow, W3Schools and GeeksforGeeks, for C concepts and examples
- YouTube tutorials, for pointers, memory and linked lists
- AI assistant: used to understand new concepts and find learning resources
