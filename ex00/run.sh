#!/bin/bash

# Test cases
test_cases=(
    "123"           # Integer
    "123.45"        # Double
    "123.45f"       # Float
    "a"             # Char
    "+inf"          # Positive infinity
    "-inf"          # Negative infinity
    "nan"           # NaN
    "123abc"        # Invalid (falls back to char/int)
    "123.456.789"   # Invalid (multiple dots)
    "42"            # Another integer
)

# Run each test case
for test in "${test_cases[@]}"; do
    echo -e "\nTesting: '$test'"
    ./Program "$test"
done

echo -e "\nAll tests completed."
