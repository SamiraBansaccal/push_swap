# push_swap (42 School)

## 📋 Description
The goal of this project is to sort a random list of integers using two stacks (`stack_a` and `stack_b`) with a restricted set of operations. The challenge lies in minimizing the number of moves while maintaining efficiency.

## 🧠 Implementation Logic: The "Maison" Algo (90/100)
Rather than following a standard tutorial (like the Turk Algorithm), I chose to develop a custom sorting logic based on an **optimized Double Radix**.

- **Preprocessing (map_to_ranks)**: Before sorting, I normalize the data. By mapping each number to its rank (from 0 to N-1), I eliminate issues with negative numbers and large gaps between values. This ensures that the algorithm only processes the minimum number of bits required.
- **Radix Foundation**: Sorting is performed by analyzing the bits of each ranked number. This is highly efficient for linked lists as it avoids complex comparisons and is purely deterministic.
- **Double Radix Optimization**: My implementation of `double_radix` doesn't just push from A to B. It analyzes the bits on both stacks to decide whether to `pa` (push to A) or `rb` (rotate B), significantly reducing the total number of operations compared to a basic Radix.
- **Hybrid Strategy**:
  - **Small sets (n <= 5)**: Handled by `mini_sort` for perfect efficiency.
  - **Large sets**: Handled by my custom optimized Radix.
- **Command Post-Optimization**: After the sort, the `optimised_cmd` function parses the instruction list to remove redundant moves (like a `ra` followed by a `rra`) before displaying them.

## 📂 Project Structure (mains files)
- `src/main.c`: Entry point and stack initialization.
- `src/map_to_ranks.c`: Normalizes input numbers into relative ranks to optimize bitwise sorting.
- `src/double_radix.c`: Core logic for bitwise sorting between two stacks.
- `src/optimised_cmd.c`: Cleans up the final output for better performance.

## 🛠️ Usage & Compilation
To compile the program (includes `-fsanitize=address` for safety):
```bash
make
To execute the program, run the program with a list of unique integers:
```bash
./push_swap 42 1 3 1337 5
The Makefile is configured with -g and fsanitize, making it easy to track any memory issues during development.
