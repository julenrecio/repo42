# *This project has been created as part of the 42 curriculum by jrecio-t.*

# get_next_line

## Description

**get_next_line** is a C library function whose purpose is to read and return the next line from a file descriptor every time it is called. The function must preserve any unread data between calls, allowing it to handle files of any size while reading only a fixed number of bytes at a time.

The main objective of this project is to gain a deeper understanding of:

* File descriptors and the `read()` system call.
* Dynamic memory allocation and management.
* Static variables and persistent state across function calls.
* String manipulation and buffer management.
* Robust handling of edge cases such as empty files, files without a trailing newline, and different buffer sizes.

The function returns one line per call, including the newline character (`'\n'`) when present, and returns `NULL` when there is no more data to read or when an error occurs.

---

## Instructions

### Compilation

Compile the project together with your program:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c main.c
```

The value of `BUFFER_SIZE` can be modified during compilation.

---

## Algorithm and Design Choices

The implementation is based on the idea that a single call to `read()` does not necessarily contain an entire line, and a single `read()` may also contain multiple lines. Therefore, the function needs a mechanism to preserve unread data between successive calls.

A **static pointer**, called `stash`, is used for this purpose.

The algorithm follows these steps:

1. Before reading from the file, the function checks whether `stash` already contains a newline character.

   * If it does, the next line is extracted and returned immediately.
   * The remaining characters stay in `stash` for future calls.

2. If no complete line exists, the function reads up to `BUFFER_SIZE` bytes from the file descriptor.

3. The newly read data is concatenated to `stash`.

4. The process repeats until either:

   * A newline character is found, or
   * The end of the file is reached.

5. When a newline is found:

   * A new string containing the complete line is allocated.
   * The unread remainder is stored back into `stash`.
   * The extracted line is returned.

6. If the end of the file is reached and `stash` still contains characters, those characters are returned as the last line.

7. If no data remains, the function returns `NULL`.

This approach guarantees that:

* No information is lost between calls.
* Files larger than `BUFFER_SIZE` are handled correctly.
* Multiple lines contained in the same read operation are processed correctly.
* Memory usage remains proportional to the amount of unread data.

The use of a static variable is justified because the function must remember data that belongs to future calls while exposing only a simple interface to the user.

---

## Features

* Reads one line at a time from any valid file descriptor.
* Supports arbitrary `BUFFER_SIZE` values.
* Correctly handles:

  * Empty files.
  * Files containing only newline characters.
  * Files without a final newline.
  * Very long lines.
  * Multiple consecutive newline characters.
* Uses dynamic memory allocation for returned lines.
* Preserves unread data between calls using a static buffer.

---

## Resources

### Documentation

* The POSIX `read()` system call manual (`man 2 read`).
* The POSIX `open()` system call manual (`man 2 open`).
* The POSIX `close()` system call manual (`man 2 close`).
* The C Standard Library documentation for dynamic memory functions (`malloc`, `free`).
* Video tutorials on YouTube. 

### Use of Artificial Intelligence

Artificial Intelligence tools were used exclusively as a learning aid during the development of this project. Specifically, they were used to:

* Clarify the behavior of the `read()` system call.
* Understand edge cases involving buffers and file descriptors.
* Explain memory management concepts and debugging techniques.
* Review and improve the readability of the documentation.