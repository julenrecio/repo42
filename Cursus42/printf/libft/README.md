*This project has been created as part of the 42 curriculum by jrecio-t.*

# Libft

## Description

Libft is a custom C library developed as part of the curriculum at :contentReference[oaicite:0]{index=0}.  
The main objective of the project is to recreate essential functions from the standard C library, as well as implement additional utility functions for string manipulation, memory management, data conversion, and linked lists.

This project serves as a foundation for future projects in the cursus, allowing the reuse of custom-built functions while strengthening the understanding of core C programming concepts such as:
- Manual memory management
- String and array manipulation
- Pointer usage
- Dynamic data structures
- Modular programming
- Static library creation and usage

---

## Project Structure

The library is divided into several categories of functions:

### Character and checking functions

| Function | Description |
|---|---|
| `ft_isalpha` | Checks whether a character is alphabetic. |
| `ft_isdigit` | Checks whether a character is numeric. |
| `ft_isalnum` | Checks whether a character is alphanumeric. |
| `ft_isascii` | Checks whether a character belongs to the ASCII table. |
| `ft_isprint` | Checks whether a character is printable. |
| `ft_tolower` | Converts a character to lowercase. |
| `ft_toupper` | Converts a character to uppercase. |

---

### Memory functions

| Function | Description |
|---|---|
| `ft_memset` | Fills a block of memory with a value. |
| `ft_bzero` | Sets a block of memory to zero. |
| `ft_memcpy` | Copies memory from one block to another. |
| `ft_memmove` | Copies memory safely even with overlapping regions. |
| `ft_memchr` | Searches for a byte inside a memory block. |
| `ft_memcmp` | Compares two memory blocks. |
| `ft_calloc` | Allocates memory and initializes it to zero. |

---

### String functions

| Function | Description |
|---|---|
| `ft_strlen` | Calculates the length of a string. |
| `ft_strchr` | Finds the first occurrence of a character in a string. |
| `ft_strrchr` | Finds the last occurrence of a character in a string. |
| `ft_strncmp` | Compares two strings up to a given number of characters. |
| `ft_strlcpy` | Copies a string with size limitation. |
| `ft_strlcat` | Concatenates strings with size limitation. |
| `ft_strdup` | Duplicates a string using dynamic memory allocation. |
| `ft_strnstr` | Searches for a substring within another string. |
| `ft_substr` | Extracts a substring from a string. |
| `ft_strjoin` | Joins two strings into a new one. |
| `ft_strtrim` | Removes specified characters from the beginning and end of a string. |
| `ft_split` | Splits a string using a delimiter. |
| `ft_strmapi` | Applies a function to each character, creating a new string. |
| `ft_striteri` | Applies a function to each character of the original string. |

---

### Conversion and output functions

| Function | Description |
|---|---|
| `ft_atoi` | Converts a string to an integer. |
| `ft_itoa` | Converts an integer to a string. |
| `ft_putchar_fd` | Writes a character to a file descriptor. |
| `ft_putstr_fd` | Writes a string to a file descriptor. |
| `ft_putendl_fd` | Writes a string followed by a newline. |
| `ft_putnbr_fd` | Writes an integer to a file descriptor. |

---

### Linked list functions

| Function | Description |
|---|---|
| `ft_lstnew` | Creates a new node. |
| `ft_lstadd_front` | Adds a node to the beginning of the list. |
| `ft_lstsize` | Counts the number of nodes in a list. |
| `ft_lstlast` | Returns the last node of a list. |
| `ft_lstadd_back` | Adds a node to the end of the list. |
| `ft_lstdelone` | Deletes a node. |
| `ft_lstclear` | Deletes and frees an entire list. |
| `ft_lstiter` | Iterates through a list applying a function to each node. |
| `ft_lstmap` | Creates a new list by applying a function to each node. |

---

## Instructions

### Compilation

To compile the library:

```bash
make
```

This will generate the following file:

```bash
libft.a
```

### Available rules

| Command | Action |
|---|---|
| `make` | Compiles the library. |
| `make bonus` | Compiles the bonus functions. |
| `make clean` | Removes object files. |
| `make fclean` | Removes object files and the library. |
| `make re` | Rebuilds the entire project. |

---

## Usage

To use the library in another project:

```bash
gcc main.c libft.a
```

You must also include the header file:

```c
#include "libft.h"
```

---

## Resources

### Documentation and references

- [Linux man-pages project](https://man7.org/linux/man-pages/man3/strlen.3.html)
- [Python/C tutor](https://pythontutor.com/index.html)
- [String functions in C](https://www.geeksforgeeks.org/c/string-functions-in-c/)

### AI Usage

AI tools were used during the development of this project as educational support for:
- Solving conceptual questions related to memory management and pointers
- Assisting with debugging and error analysis