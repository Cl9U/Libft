*This project has been created as part of the 42 curriculum by sfaraji.*

# Libft

## Description

Libft is my first own C library. The goal of the project is to understand how
the standard C functions work by rewriting them, and to build a set of
general-purpose utilities (strings, memory, output, linked lists) that I can
reuse in all my future 42 projects.

The library is compiled into a static archive, `libft.a`, and is written in C
following the 42 Norm. It is made of three parts:

1. **Libc functions** that behave exactly like the originals (same prototypes
   and behavior as described in the man pages), with the `ft_` prefix.
2. **Additional functions** that are not in the libc or are a different
   version of them.
3. **Linked list functions** built around the `t_list` structure.

The rules from the subject that shape the code:

- Written in C, in accordance with the Norm.
- No global variables.
- Helper functions are `static`.
- No unexpected crash (segfault, double free, ...) except on undefined behavior.
- Every allocated block is freed when needed (no leaks).
- Compiled with `cc -Wall -Wextra -Werror`, without `-std=c99`, and the
  `restrict` qualifier is not used in prototypes.
- The library is created with `ar` (never `libtool`) at the root of the repo.
- The Makefile has the rules `$(NAME)`, `all`, `clean`, `fclean` and `re`,
  and does not relink when nothing changed.
- Only the allowed external functions are used (`malloc`, `free`, `write`).

## Instructions

### Compilation

```sh
make          # builds libft.a at the root of the repository
make clean    # removes the object files
make fclean   # removes the object files and libft.a
make re       # fclean + all
```

### Use in a project

Include the header and link the library:

```c
#include "libft.h"
```

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lft
```

### Testing

Test programs are not part of the repository. I compile my own `main.c`
against the library with the sanitizers to detect memory errors and leaks:

```sh
cc -Wall -Wextra -Werror -fsanitize=address,undefined main.c libft.a -I.
```

To compare `ft_strlcpy`, `ft_strlcat` and `ft_bzero` with the system versions
on glibc, include `<bsd/string.h>` and add `-lbsd`.

## Library description

### Part 1 - Libc functions

| Category | Functions |
|---|---|
| Character tests (return 1 or 0) | `ft_isalpha`, `ft_isdigit`, `ft_isalnum`, `ft_isascii`, `ft_isprint` |
| Case conversion | `ft_toupper`, `ft_tolower` |
| String | `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strrchr`, `ft_strncmp`, `ft_strnstr`, `ft_strdup` |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Conversion | `ft_atoi` |

### Part 2 - Additional functions

| Function | Description |
|---|---|
| `ft_substr` | Allocates and returns a substring of `s`, starting at `start`, of at most `len` characters. |
| `ft_strjoin` | Allocates and returns the concatenation of `s1` and `s2`. |
| `ft_strtrim` | Allocates and returns a copy of `s1` without the characters of `set` at the beginning and at the end. |
| `ft_split` | Splits `s` with the character `c` as delimiter and returns a `NULL`-terminated array of strings. |
| `ft_itoa` | Allocates and returns the string representing an integer (negative numbers included). |
| `ft_strmapi` | Applies `f` to each character (with its index) and returns the new string. |
| `ft_striteri` | Applies `f` to each character (with its index) of the string, in place. |
| `ft_putchar_fd`, `ft_putstr_fd`, `ft_putendl_fd`, `ft_putnbr_fd` | Write a character, a string, a string plus a newline, or an integer on a file descriptor. |

### Part 3 - Linked lists

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node holding `content`. |
| `ft_lstadd_front` / `ft_lstadd_back` | Add a node at the beginning / at the end of the list. |
| `ft_lstsize` | Counts the nodes of the list. |
| `ft_lstlast` | Returns the last node. |
| `ft_lstdelone` | Applies `del` to the content of a node and frees the node. |
| `ft_lstclear` | Deletes and frees a node and all the nodes after it, then sets the list pointer to `NULL`. |
| `ft_lstiter` | Applies `f` to the content of each node. |
| `ft_lstmap` | Builds a new list from the results of `f`; if an allocation fails, everything already allocated is freed. |

### Technical choices

- **Libc clones keep the libc behavior**, including crashing on `NULL`
  arguments where the original does (undefined behavior). Functions with no
  libc original (`ft_substr`, `ft_strjoin`, `ft_split`, ...) check their
  pointers and return `NULL` or do nothing.
- **`ft_memmove`** copies forward when the destination is before the source
  and backward otherwise, so overlapping areas are handled correctly.
- **`ft_calloc`** returns a unique pointer that can be freed when `nmemb` or
  `size` is 0 (rule from the subject), and `NULL` if `nmemb * size` overflows.
- **`ft_strlcat`** returns the length of the string it tried to create, so a
  return value greater than or equal to `dsize` means truncation.
- **`ft_split` and `ft_lstmap`** free every block allocated before a failure
  and return `NULL`, so a failed allocation never leaks.
- **`ft_lstadd_front` and `ft_lstadd_back`** accept an empty list
  (`*lst == NULL`): the new node becomes the head.

## Resources

### References

- Linux man pages, section 3 (`man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, ...)
- The GNU C Library reference manual: https://www.gnu.org/software/libc/manual/
- ISO C standard (C99/C11) for the behavior of `size_t`, `unsigned char` conversions and undefined behavior
- The 42 Norm (Norminette)
- Brian W. Kernighan and Dennis M. Ritchie, *The C Programming Language*
- AddressSanitizer and Valgrind documentation for memory error and leak detection
- GNU Make manual: https://www.gnu.org/software/make/manual/

### Use of AI

I used Claude (Anthropic) as a study and review tool during this project, for
the following tasks:

- **Code review:** I pasted functions I had written and it pointed out bugs and
  edge cases (for example off-by-one errors, unsigned underflow with `size_t`,
  the missing terminator in `ft_strdup`, the empty-list case in
  `ft_lstadd_front`, the use-after-free in `ft_lstclear`).
- **Explanations:** how `memmove` handles overlap, why `ft_calloc` needs an
  overflow check, what `(*lst)->next` means, which libc behaviors to keep for
  `NULL` arguments.
- **Norm and warnings:** formatting issues reported by Norminette and compiler
  warnings.
- **Makefile and tests:** the structure of the Makefile rules and ideas for
  edge-case tests against the libc.
- **Corrected code:** for several functions, it suggested corrected versions
  that I then used (in particular `ft_split`, `ft_itoa`, `ft_lstmap` and parts
  of `ft_strtrim`, `ft_substr` and `ft_strlcat`).
- **README:** this file was drafted with its help from the subject's
  requirements.

I compiled the library and checked every file with Norminette myself.