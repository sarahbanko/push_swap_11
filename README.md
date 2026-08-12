*This project has been created as part of the 42 curriculum by adrperei, sbanko.*

# push_swap

## Description

Push_swap is a sorting algorithm project that uses two stacks (a and b) and a limited set of operations to sort integers in ascending order. The goal is to generate the shortest possible sequence of Push_swap instructions.

The program implements four sorting strategies selectable at runtime:

- **Simple** (`--simple`) — O(n²), selection sort
- **Medium** (`--medium`) — O(n√n), chunk-based sort
- **Complex** (`--complex`) — O(n log n), binary radix sort
- **Adaptive** (`--adaptive`) — auto-selects strategy based on input disorder

## Instructions

```
make
./push_swap [--simple|--medium|--complex|--adaptive] [--bench] <numbers...>
```

Examples:
```
./push_swap 2 1 3 6 5 8
./push_swap --complex 4 67 3 87 23 | ./checker_linux 4 67 3 87 23
./push_swap --adaptive --bench "5 3 1 2 4" 2>bench.txt
```

## Resources

- Binary radix sort: sorting by bit position using stack operations
- Selection sort: repeatedly extracting the minimum element
- Chunk-based sort: partitioning by value ranges (√n chunks)
- Kendall tau distance (disorder metric): normalized inversion count

### AI usage

AI tools were used for debugging the radix sort parameter ordering and for generating the benchmark operation counter infrastructure.

## Algorithm Justification

### Simple — Selection Sort (O(n²))
Repeatedly finds the minimum-index element in stack A, rotates it to the top, and pushes it to B. Once A is empty, everything is pushed back sorted. Suitable for nearly-sorted or small inputs.

### Medium — Chunk Sort (O(n√n))
Divides the index range into √n chunks. For each chunk, elements within the range are pushed from A to B in optimal rotation order. Phase two moves the largest remaining elements from B back to A.

### Complex — Radix Sort (O(n log n))
Binary LSD radix sort. For each bit position (0 to log₂(n)-1), elements with bit 0 are pushed to B and elements with bit 1 are rotated to A's bottom. B is then pushed back. After all bits are processed, the stack is sorted.

### Adaptive
Computes the input disorder (normalized inversion count):
- **disorder < 0.2**: near-sorted → Simple O(n²)
- **0.2 ≤ disorder < 0.5**: moderate entropy → Medium O(n√n)
- **disorder ≥ 0.5**: high entropy → Complex O(n log n)
