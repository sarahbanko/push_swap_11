#!/bin/bash
P=./push_swap
C=./checker_linux
CH=./checker
PASS=0
FAIL=0
TOTAL=0

ok() { PASS=$((PASS+1)); TOTAL=$((TOTAL+1)); printf "  \033[32m✓\033[0m %s\n" "$1"; }
bad() { FAIL=$((FAIL+1)); TOTAL=$((TOTAL+1)); printf "  \033[31m✗\033[0m %s\n" "$1"; }

# sort with checker_linux (numbers only, no flags)
sort_ok() {
    local desc="$1"; shift
    $P "$@" 2>/dev/null | $C "$@" >/dev/null 2>&1 && ok "$desc" || bad "$desc (sort fail)"
}
# sort with flag + numbers (flag removed for checker)
sort_flag_ok() {
    local desc="$1"; local flag="$2"; shift 2
    $P $flag "$@" 2>/dev/null | $C "$@" >/dev/null 2>&1 && ok "$flag $desc" || bad "$flag $desc (sort fail)"
}
# op count test (returns op count in global OPS)
count_ops() { OPS=$($P "$@" 2>/dev/null | wc -l); }
# error expected
err() { local d="$1"; shift; $P "$@" 2>&1 | grep -q "Error" && ok "$d" || bad "$d (no Error)"; }
# checker self-test
chk() { local d="$1"; local e="$2"; shift 2; r=$($CH "$@" 2>&1); echo "$r" | grep -q "$e" && ok "$d=$e" || bad "$d (got '$r', wanted '$e')"; }

echo "══════════════════════════════"
echo " WEIRD SYNTAX"
echo "══════════════════════════════"
sort_ok 'quoted + unquoted' "1 5 123 -4" 7 "4"
sort_ok 'multi quoted groups' "3 1" "4 2" "5"
sort_ok 'multi spaces in quotes' "  3    1   4  2  "
sort_flag_ok 'flag before quoted' --complex "5 3 1 2 4"
sort_flag_ok 'flag between groups' --simple "1 2" "3 4"
err 'triple dash' ---simple 1 2
err 'single dash flag' -simple 1 2
err 'dash only' -- 1 2
err 'dash-dash-word' -- banana
err 'flag typo simple' --simmple 1 2
err 'flag typo bench' --benc 1 2
err 'flag typo complex' --complexx 1 2
err 'empty quoted' ""
err 'spaces only' "   "
err 'tab separator' "3	1	2"

echo ""
echo "══════════════════════════════"
echo " ALL 4 ALGOS — SMALL"
echo "══════════════════════════════"
for f in --simple --medium --complex --adaptive; do
    sort_flag_ok '1 elem'    $f 42
    sort_flag_ok '2 sorted'  $f 1 2
    sort_flag_ok '2 reverse' $f 2 1
    sort_flag_ok '3 sorted'  $f 1 2 3
    sort_flag_ok '3 reverse' $f 3 2 1
    sort_flag_ok '3 random'  $f 2 1 3
    sort_flag_ok '4 random'  $f 3 1 4 2
    sort_flag_ok '5 reverse' $f 5 4 3 2 1
done

echo ""
echo "══════════════════════════════"
echo " OPERATION BENCHMARKS"
echo "══════════════════════════════"
count_ops --simple $(python3 -c "import random; r=list(range(1,4)); random.shuffle(r); print(*r)")
[ "$OPS" -le 8 ] && ok "simple 3 rnd ≤8 ($OPS)" || bad "simple 3 rnd ($OPS)"
count_ops --simple 1 2 3
[ "$OPS" -eq 0 ] && ok "simple 3 sorted→0 ($OPS)" || bad "simple 3 sorted ($OPS)"
count_ops --simple 3 1 2
[ "$OPS" -le 8 ] && ok "simple 3 1 2 ≤8 ($OPS)" || bad "simple 3 1 2 ($OPS)"
count_ops --complex $(python3 -c "import random; r=list(range(100)); random.shuffle(r); print(*r)")
[ "$OPS" -le 1500 ] && ok "complex 100 ≤1500 ($OPS)" || bad "complex 100 ($OPS)"
count_ops --complex $(python3 -c "import random; r=list(range(500)); random.shuffle(r); print(*r)")
[ "$OPS" -le 12000 ] && ok "complex 500 ≤12000 ($OPS)" || bad "complex 500 ($OPS)"

echo ""
echo "══════════════════════════════"
echo " BOUNDARY VALUES"
echo "══════════════════════════════"
sort_ok 'INT_MAX in mix' 2147483647 1 -1 0
sort_ok 'INT_MIN in mix' -2147483648 1 -1 0
sort_ok 'both extremes' 2147483647 -2147483648 0
sort_ok 'all negatives' -5 -4 -3 -2 -1
sort_ok 'all positives' 1 2 3 4 5
sort_ok 'zero only' 0
sort_ok 'consecutive negative' 5 4 3 2 1 0 -1 -2 -3 -4 -5

echo ""
echo "══════════════════════════════"
echo " RANDOM — ALL ALGOS × 100"
echo "══════════════════════════════"
ARG100=$(python3 -c "import random; r=list(range(100)); random.shuffle(r); print(*r)")
for f in --simple --medium --complex --adaptive; do
    sort_flag_ok '100' $f $ARG100
done

echo ""
echo "══════════════════════════════"
echo " OUR CHECKER vs REFERENCE"
echo "══════════════════════════════"
for i in 1 2 3; do
    ARG=$(python3 -c "import random; r=list(range(1,31)); random.shuffle(r); print(*r)")
    ops=$($P $ARG 2>/dev/null)
    r1=$(echo "$ops" | $C $ARG 2>&1)
    r2=$(echo "$ops" | $CH $ARG 2>&1)
    [ "$r1" = "$r2" ] && ok "checker match #$i ($r1==$r2)" || bad "checker match #$i ($r1 vs $r2)"
done
chk 'bad op → Error' Error ran dom
chk 'empty arg → Err' Error "" 1
chk 'dup → Error' Error 3 3 1
chk 'correct → OK' OK 3 1 2 <<< "$($P 3 1 2 2>/dev/null)"
echo "sa" | $CH 1 2 2>&1 | grep -q "KO" && ok 'wrong op → KO' || bad 'wrong op not KO'

echo ""
echo "══════════════════════════════"
echo " RESULT: $PASS/$TOTAL passed"
echo "══════════════════════════════"
[ $FAIL -gt 0 ] && exit 1
exit 0
