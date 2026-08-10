#!/bin/bash
# Comprehensive edge case tests for push_swap
P="./push_swap"
C="./checker_linux"
PASS=0
FAIL=0

check_err() {
    local desc="$1"; shift
    $P "$@" 2>&1 | grep -q "Error" && { echo "  ✓ $desc"; PASS=$((PASS+1)); } || { echo "  ✗ $desc (expected Error)"; FAIL=$((FAIL+1)); }
}
check_ok() {
    local desc="$1"; shift
    $P "$@" 2>/dev/null | $C "$@" >/dev/null 2>&1 && { echo "  ✓ $desc"; PASS=$((PASS+1)); } || { echo "  ✗ $desc (sort failed)"; FAIL=$((FAIL+1)); }
}
check_ok_custom() {
    local desc="$1"; local checker_args="$2"; shift 2
    $P "$@" 2>/dev/null | $C $checker_args >/dev/null 2>&1 && { echo "  ✓ $desc"; PASS=$((PASS+1)); } || { echo "  ✗ $desc (sort failed)"; FAIL=$((FAIL+1)); }
}
check_silent() {
    local desc="$1"; shift
    out=$($P "$@" 2>&1)
    [ -z "$out" ] && { echo "  ✓ $desc"; PASS=$((PASS+1)); } || { echo "  ✗ $desc (got: '$out')"; FAIL=$((FAIL+1)); }
}

echo "════════════════════════════════════"
echo " PARSER — ERROR CASES"
echo "════════════════════════════════════"
check_err "non-integer" one 2 3
check_err "mixed non-int" 1 two 3
check_err "duplicate" 3 1 3
check_err "duplicate far" 1 2 3 4 5 6 7 8 9 10 3
check_err "overflow pos" 2147483648
check_err "overflow neg" -2147483649
check_err "zero string" ""
check_err "lone plus" +
check_err "lone minus" -
check_err "lone --" --
check_err "unknown flag" --banana 1 2
check_err "double dash" -- 1 2
check_err "trailing junk" 42a
check_err "mixed signs junk" -+42

echo ""
echo "════════════════════════════════════"
echo " PARSER — VALID INPUTS"
echo "════════════════════════════════════"
check_ok "INT_MAX" 2147483647
check_ok "INT_MIN" -2147483648
check_ok "leading spaces" "  42"
check_ok "trailing spaces" "42  "
check_ok "signed +42" +42
check_ok "zero" 0
check_ok "single digit" 7
check_silent "no args"
check_silent "--simple only" --simple
check_silent "--bench only" --bench
check_silent "--adaptive only" --adaptive

echo ""
echo "════════════════════════════════════"
echo " SORT — SMALL SIZES"
echo "════════════════════════════════════"
check_ok "size 1" 42
check_ok "size 2 sorted" 1 2
check_ok "size 2 unsorted" 2 1
check_ok "size 3 sorted" 1 2 3
check_ok "size 3 rev" 3 2 1
check_ok "size 3 mid" 2 1 3
check_ok "size 4 random" 3 1 4 2
check_ok "size 4 rev" 4 3 2 1
check_ok "size 5 random" 5 2 1 4 3
check_ok "size 5 rev" 5 4 3 2 1

echo ""
echo "════════════════════════════════════"
echo " SORT — NEGATIVES, ZERO, EDGES"
echo "════════════════════════════════════"
check_ok "negatives only" -1 -5 -3 -2 -4
check_ok "mixed signs" -5 3 0 -1 2 -4
check_ok "with zero" 0 3 -1 2 -2
check_ok "INT_MIN/MAX mix" 2147483647 -2147483648 0 1 -1 42
check_ok "all same sign neg" -10 -20 -5 -15

echo ""
echo "════════════════════════════════════"
echo " STRATEGY ROUTING"
echo "════════════════════════════════════"
for s in --simple --medium --complex --adaptive; do
    check_ok_custom "flag $s" "5 3 1 4 2 8 6 7" $s 5 3 1 4 2 8 6 7
done

echo ""
echo "════════════════════════════════════"
echo " FLAG POSITIONS (mixed)"
echo "════════════════════════════════════"
check_ok_custom "flag middle" "3 1 2" 3 1 --simple 2
check_ok_custom "flag start"  "3 1 2" --medium 3 1 2
check_ok_custom "flag end"    "3 1 2" 3 1 2 --complex
check_ok_custom "two flags"   "3 1 2" --bench --simple 3 1 2
check_ok_custom "sandwich"    "3 1 2" --simple 3 1 --bench 2

echo ""
echo "════════════════════════════════════"
echo " BENCH MODE"
echo "════════════════════════════════════"
($P --bench --simple 5 4 3 2 1 >/dev/null 2>&1) && { echo "  ✓ bench exits 0"; PASS=$((PASS+1)); } || { echo "  ✗ bench failed"; FAIL=$((FAIL+1)); }
benchout=$($P --bench --simple 3 1 2 2>&1)
echo "$benchout" | grep -q "Disorder:" && echo "$benchout" | grep -q "Total:" && echo "$benchout" | grep -q "sa:" && echo "  ✓ bench has required fields" && PASS=$((PASS+1)) || { echo "  ✗ bench missing fields"; FAIL=$((FAIL+1)); }

echo ""
echo "════════════════════════════════════"
echo " RANDOM BATCHES"
echo "════════════════════════════════════"
for n in 10 20 50; do
    ARG=$(shuf -i 0-9999 -n $n | tr '\n' ' ')
    check_ok "random $n" $ARG
done
for i in 1 2 3; do
    ARG=$(shuf -i 0-99999 -n 100 | tr '\n' ' ')
    check_ok "random 100 #$i" $ARG
done
ARG=$(shuf -i 0-99999 -n 500 | tr '\n' ' ')
check_ok "random 500" $ARG

echo ""
echo "════════════════════════════════════"
echo " RESULT: $PASS passed, $FAIL failed"
echo "════════════════════════════════════"
[ $FAIL -gt 0 ] && exit 1
exit 0
