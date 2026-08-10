#!/bin/bash
# Test push_swap --simple performance at various disorder levels
# Usage: ./test/run_disorder_tests.sh

PROG=./push_swap
GEN=./test/disorder_gen.py
N=100
DISORDERS="0.10 0.20 0.30 0.50 0.70 0.90"

echo "=== Simple O(n²) at n=$N ==="
printf "%-16s %-16s %-10s\n" "Target disorder" "Actual disorder" "Ops"
echo "--------------------------------------------------"

for d in $DISORDERS; do
    output=$($GEN $N $d 2>&1)
    seq=$(echo "$output" | grep -v "^#")
    actual_d=$(echo "$output" | grep "^#" | sed 's/# disorder=//;s/ .*//')
    ops=$(echo "$seq" | xargs $PROG --simple 2>/dev/null | wc -l)
    printf "%-16s %-16s %-10s\n" "$d" "$actual_d" "$ops"
done
