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

## Library

- **Part 1 - Libc:** `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`,
  `ft_isprint`, `ft_toupper`, `ft_tolower`, `ft_strlen`, `ft_strlcpy`,
  `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`,
  `ft_strdup`, `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`,
  `ft_memchr`, `ft_memcmp`, `ft_calloc`, `ft_atoi`
- **Part 2 - Additional:** `ft_substr`, `ft_strjoin`, `ft_strtrim`,
  `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, `ft_putchar_fd`,
  `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd`
- **Part 3 - Linked lists:** `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`,
  `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`,
  `ft_lstiter`, `ft_lstmap`

## Resources

- Linux man pages, section 3 (`man 3 strlen`, `man 3 memmove`, ...)
- The GNU C Library reference manual
- Kernighan and Ritchie, *The C Programming Language*
- The 42 Norm
- Stack Overflow, W3Schools and GeeksforGeeks, to look up C concepts and examples
- YouTube tutorials, to understand pointers, memory and linked lists

**Use of AI:** I used AI to help me understand concepts that
were new to me and to learn how to find and fix problems in my code.