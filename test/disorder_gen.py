#!/usr/bin/env python3
"""Construct then randomize sequences with exact target disorder."""

import random
import sys

def inversions(arr):
    n = len(arr)
    mistakes = 0
    i = 0
    while i < n:
        j = i + 1
        while j < n:
            if arr[i] > arr[j]:
                mistakes += 1
            j += 1
        i += 1
    return mistakes

def disorder(arr):
    n = len(arr)
    total = n * (n - 1) // 2
    return inversions(arr) / total if total > 0 else 0.0

def build_sequence(n, target_inv):
    """Lehmer code: exact inversion count, deterministic pattern."""
    lehmer = [0] * n
    remaining = target_inv
    i = 0
    while i < n - 1:
        mx = n - 1 - i
        if remaining > mx:
            lehmer[i] = mx
            remaining -= mx
        else:
            lehmer[i] = remaining
            remaining = 0
        i += 1
    remaining_nums = list(range(1, n + 1))
    result = []
    i = 0
    while i < n:
        result.append(remaining_nums.pop(lehmer[i]))
        i += 1
    return result

def randomize(arr, target_inv, tol_pct=0.05):
    """Apply random swaps, undoing any that stray outside tolerance."""
    n = len(arr)
    margin = max(int(target_inv * tol_pct), 5)
    lo = target_inv - margin
    hi = target_inv + margin
    inv = inversions(arr)
    for _ in range(n * 20):
        a = random.randrange(n)
        b = random.randrange(n)
        if a == b:
            continue
        arr[a], arr[b] = arr[b], arr[a]
        new_inv = inversions(arr)
        if lo <= new_inv <= hi:
            inv = new_inv
        else:
            arr[a], arr[b] = arr[b], arr[a]
    return arr

if __name__ == "__main__":
    if len(sys.argv) < 2:
        print("Usage: disorder_gen.py <n> [target_disorder]", file=sys.stderr)
        sys.exit(1)
    n = int(sys.argv[1])
    target = float(sys.argv[2]) if len(sys.argv) > 2 else 0.5
    total_pairs = n * (n - 1) // 2
    target_inv = int(target * total_pairs)
    seq = build_sequence(n, target_inv)
    randomize(seq, target_inv)
    d = disorder(seq)
    print(" ".join(str(x) for x in seq))
    print(f"# disorder={d:.4f} target={target:.4f}", file=sys.stderr)
