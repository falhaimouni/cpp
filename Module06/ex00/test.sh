#!/bin/bash

EXE=./converter

function run_tests() {
    echo -e "\n\033[1;34m$1\033[0m"
    shift
    for arg in "$@"; do
        echo -e "\n\033[1;33m> $EXE \"$arg\"\033[0m"
        $EXE "$arg"
    done
}

run_tests "🧩 CHAR TESTS" \
    "a" "Z" "0" " " "~"

run_tests "🔢 INT TESTS" \
    "0" "42" "-42" "2147483647" "-2147483648" "9999999999999999"

run_tests "🌊 FLOAT TESTS" \
    "0.0f" "4.2f" "-4.2f" "42.0f" "4.242424f" "1e10f" "9999999999999999999999999f"

run_tests "💧 DOUBLE TESTS" \
    "0.0" "4.2" "-4.2" "42.0" "4.242424" "1e100"

run_tests "♾️ SPECIAL FLOATING LITERALS" \
    "nan" "nanf" "+inf" "-inf" "+inff" "-inff"

run_tests "🧨 INVALID CASES" \
    "" "   " "abc" "4.2ff" "f" "+42.42.42" "--" "+--" "++inf"

run_tests "�� NON-PRINTABLE CHAR TESTS" \
    "10" "31" "32" "126"

run_tests "🧪 EXTREME RANGE TESTS" \
    "3.40282e+38f" "-3.40282e+38f" "1.79769e+308" "-1.79769e+308" "1e309"

run_tests "✅ DECIMAL PRECISION TESTS" \
    "42.000" "42.9999" "42.5" "0.0000001" "-0.0000001"

