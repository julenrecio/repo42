*This project has been created as part of the 42 curriculum by azahino-, jrecio-t.*

# push_swap

## Description

`push_swap` is a sorting algorithm project developed as part of the curriculum at 42.

The objective is to sort a stack of integers using the smallest possible number of operations while respecting a restricted set of stack instructions. The project focuses on algorithm design, data structures, optimization, and complexity analysis.

The program receives a list of integers as input and outputs the sequence of operations required to sort them.

---

## Features

- Input validation and error handling
- Detection of already sorted stacks
- Three specialized sorting algorithms depending on the selected mode or according to the disorder level.
- optional bench mode, to print fuctions usefull data
- Circular doubly linked list implementation for efficient stack operations
- Support for all mandatory push_swap operations

## Contributions

The project was developed collaboratively, with both authors participating in the design, implementation, testing, and optimization of the application.

### azahino-

- Designed and implemented the **Selection Sort** algorithm for small inputs.
- Contributed to the development and optimization of the **Chunk-Based Sort** algorithm.
- Implemented and refactored stack operations.
- Improved parsing, input validation, and error handling.
- Performed code refactoring, normalization, debugging, and memory leak fixes.

### jrecio-t

- Designed and implemented the **Radix Sort** algorithm for large inputs.
- Developed the adaptive algorithm selection mechanism.
- Implemented the **checker** bonus program and integrated `get_next_line`.
- Contributed to benchmarking, performance analysis, and project organization.
- Participated in testing, debugging, refactoring, and documentation.

### Shared Contributions

The following components were developed collaboratively:

- Circular linked list data structure.
- Stack operations (`sa`, `pb`, `ra`, etc.).
- Index assignment and preprocessing.
- Makefile and project structure.
- Performance optimization and algorithm tuning.
- Testing, code reviews, and final validation.

## Supported Operations

| Operation | Description |
|-----------|-------------|
| `sa` | Swap the first two elements of **stack A**. Does nothing if the stack contains fewer than two elements. |
| `sb` | Swap the first two elements of **stack B**. Does nothing if the stack contains fewer than two elements. |
| `ss` | Perform `sa` and `sb` simultaneously. |
| `pa` | Push the top element from **stack B** onto **stack A**. Does nothing if stack B is empty. |
| `pb` | Push the top element from **stack A** onto **stack B**. Does nothing if stack A is empty. |
| `ra` | Rotate **stack A** upwards, moving the first element to the bottom of the stack. |
| `rb` | Rotate **stack B** upwards, moving the first element to the bottom of the stack. |
| `rr` | Perform `ra` and `rb` simultaneously. |
| `rra` | Reverse rotate **stack A**, moving the last element to the top of the stack. |
| `rrb` | Reverse rotate **stack B**, moving the last element to the top of the stack. |
| `rrr` | Perform `rra` and `rrb` simultaneously. |

## Project Structure

The project is organized into several modules responsible for:

- Argument parsing and validation
- algorithm and bench option selection
- Stack initialization
- Stack operations
- Sorting algorithms
- Utility functions
- Checker (bonus)

---

## Algorithm and Data Structure Choices

The project uses a **circular linked list** to represent both stacks. This structure allows efficient rotations, reverse rotations, pushes, and swaps without moving large amounts of data.

Instead of relying on a single sorting algorithm, the program let us selects the strategy we want ussing the next flags:

- `--simple` to choose **Selection Sort**
- `--medium` to choose **Chunk_Based Sort**
- `--complex` to choose **Radix Sort**
- `--adaptive` to choose according to `disorder`

Like we said, **adative**, is default and selectable mode that selects the best strategy according to the disorder of input number list:

- **Selection Sort** for a disorder level of `0 <= disorder < 0.2`, producing an optimal or near-optimal number of operations.
- **Chunk-Based Sort** for for a disorder level of `0'2 <= disorder < 0.5`. Elements are divided into ranges (chunks), pushed to the auxiliary stack, and reassembled efficiently.
- **Radix Sort** for a disorder level of `0'5 <= disorder <= 1`. After assigning each value a normalized index, the algorithm sorts elements bit by bit, achieving predictable performance with a low operation count.

This hybrid approach provides better overall performance than using a single algorithm for every case.

---

## Instructions

### Compilation

Compile the project with:

```bash
make
```

This generates:

```text
push_swap
```

Compile the bonus program with:

```bash
make bonus
```

which generates:

```text
checker
```

### Available Rules

| Command | Description |
|---------|-------------|
| `make` | Compile push_swap |
| `make bonus` | Compile checker |
| `make clean` | Remove object files |
| `make fclean` | Remove object files and executables |
| `make re` | Rebuild the project |

---

### Available Flags

| Flag | Description|
|---|---|
| `--bench` | Allow `push_swap` to print level of disorder,used strategy, total moves and each move count |
| `--simple` | Use **Selection Sort** to sort the stack |
| `--medium` | Use **Chunk-Based Sort** to sort the stack |
| `--complex` | Use **Radix Sort** to sort the stack |
| `--adaptive` | Use `disorder` to select the optimal algorithm |

## Usage

Sort a stack:

```bash
./push_swap 4 67 3 87 23
```

Select bench:

```bash
./push_swap --bench 4 67 3 87 23
```

Select sort mode:

```bash
./push_swap --simple 4 67 3 87 23
```

**Both flags can be used simultaneously, but the benchmark flag must be used first**

Validate the output with the checker:

```bash
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

If the generated instructions correctly sort the stack, the checker prints:

```text
OK
```

---

## Bonus

The bonus part of the project includes a program named `checker`, which verifies whether a sequence of operations correctly sorts a given stack.

The `checker` program:
- Receives the initial stack as command-line arguments.
- Reads instructions from the standard input.
- Executes each operation on the stacks.
- Prints `OK` if the stack is correctly sorted and `KO` otherwise.
- Handles invalid instructions by printing `Error`.

### Compilation

Compile the bonus program with:

```bash
make bonus
```

### Usage

```bash
./push_swap 3 2 1 | ./checker 3 2 1
```

You can also test instructions manually:

```bash
./checker 3 2 1
```

Then enter one instruction per line, for example:

```text
sa
ra
```

Finish the input with **Ctrl+D** (EOF). The program will output either `OK` or `KO`.

## Resources

### Documentation and References

- [Repository](https://github.com/azahino-code/Push-Swap)
- [Circular Doubly Linked List](https://www.geeksforgeeks.org/dsa/introduction-to-circular-doubly-linked-list/)
- [Random number generator](https://pinetools.com/es/generador-numeros-aleatorios)
- [Push-Swap Visualizer](https://nmannage.github.io/showcase/push_swap_visualizer/)

### AI Usage

AI tools were used as educational support for:
- Discussing optimization strategies.
- Reviewing edge cases and debugging.
- Improving project documentation.

## Authors

- azahino-
- jrecio-t