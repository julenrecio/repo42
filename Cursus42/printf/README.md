*This project has been created as part of the 42 curriculum by jrecio-t.*

# ft_printf

## Description

`ft_printf` is a custom implementation of the standard C `printf` function, developed as part of the 42 curriculum.

The objective of this project is to reproduce the behavior of the original `printf` function while gaining a deeper understanding of:
- Variadic functions
- Format specifiers
- Low-level output handling
- Number conversion
- Memory and string manipulation
- Modular C programming

The project focuses on parsing format strings and printing formatted output to the standard output using a custom implementation.

---

## Features

This implementation supports the following format specifiers:

| Specifier | Description |
|---|---|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%d` / `%i` | Prints a signed integer |
| `%u` | Prints an unsigned integer |
| `%x` | Prints a hexadecimal number in lowercase |
| `%X` | Prints a hexadecimal number in uppercase |
| `%p` | Prints a pointer address |
| `%%` | Prints a percent sign |

---

## Project Structure

The project is organized into several source files:

| File | Purpose |
|---|---|
| `ft_printf.c` | Main `ft_printf` function and format parsing logic |
| `ft_printf_number.c` | Integer and unsigned integer printing |
| `ft_printf_hex.c` | Lowercase and uppercase hexadecimal conversion |
| `ft_printf_pointer.c` | Pointer address formatting |
| `ft_printf.h` | Header file containing prototypes and includes |
| `Makefile` | Compilation rules |

### Internal Functions

#### `ft_printf.c`
- `ft_printf` → Main function handling variadic arguments
- `ft_check_specifier` → Detects and dispatches format specifiers
- `ft_printf_character` → Prints characters
- `ft_printf_string` → Prints strings

#### `ft_printf_number.c`
- Function for signed integer conversion (`%d` / `%i`)
- Function for unsigned integer conversion (`%u`)

#### `ft_printf_hex.c`
- Function handling hexadecimal output (`%x` / `%X`)

#### `ft_printf_pointer.c`
- Function handling pointer formatting (`%p`)
- Auxiliary helper function for hexadecimal pointer conversion

---

## Instructions

### Compilation

To compile the project:

```bash
make
```

This generates the static library:

```bash
libftprintf.a
```

---

### Available Rules

| Command | Action |
|---|---|
| `make` | Compiles the project |
| `make clean` | Removes object files |
| `make fclean` | Removes object files and the library |
| `make re` | Rebuilds the entire project |

---

## Usage

Include the header in your source file:

```c
#include "ft_printf.h"
```

Compile your program together with the library:

```bash
gcc main.c libftprintf.a
```

Example usage:

```c
ft_printf("Hello %s!\n", "world");
ft_printf("Number: %d\n", 42);
ft_printf("Hexadecimal: %x\n", 255);
ft_printf("Pointer: %p\n", ptr);
```

## Resources

### Documentation and References

- [Linux man-pages project](https://man7.org/linux/man-pages/man1/printf.1.html)
- [Variadic functions in C](https://www.geeksforgeeks.org/c/variadic-functions-in-c/)

### AI Usage

AI tools were used during the development of this project as educational support for:
- Understanding variadic functions (`stdarg.h`)
- Clarifying the behavior of format specifiers
- Assisting with debugging and memory-related issues

## Algorithm and Structure Choices

The project is based on a linear parsing algorithm that reads the format string character by character.

The `ft_printf` function detects `%` symbols and delegates the corresponding conversion to `ft_check_especifier`, which acts as a dispatcher for each supported format specifier (`%c`, `%d`, `%x`, `%p`, etc.).

This modular design was chosen to:
- Keep the code organized and readable
- Separate each conversion type into independent functions
- Simplify maintenance and debugging
- Make the project easier to extend

The implementation uses:
- Variadic arguments through `va_list`
- Sequential string traversal
- Recursive number conversion for numeric formats
- Low-level output using `write`

No complex data structures were required for the project.