#!/bin/bash

# Test cases
test_cases=(
    # Standard cases
    "123"            # INT
    "123.45"         # DOUBLE
    "123.45f"        # FLOAT
    "a"              # CHAR (ASCII)
    "A"              # CHAR (ASCII uppercase)
    " "              # CHAR (whitespace)
    "~"              # CHAR (ASCII boundary)
    
    # Special values
    "+inf"           # POSINF (double)
    "+inff"          # POSINF (float)
    "-inf"           # NEGINF (double)
    "-inff"          # NEGINF (float)
    "nan"            # NAN (double)
    "nanf"           # NAN (float)
    
    # Edge cases for numbers
    "0"              # Zero (INT)
    "0.0"            # Zero (DOUBLE)
    "0.0f"           # Zero (FLOAT)
    "-0"             # Negative zero (INT)
    "-0.0"           # Negative zero (DOUBLE)
    "-0.0f"          # Negative zero (FLOAT)
    "2147483647"     # INT_MAX
    "-2147483648"    # INT_MIN
    "3.40282e+38f"   # FLOAT_MAX (~3.4e38)
    "1.17549e-38f"   # FLOAT_MIN (~1.2e-38)
    "1.79769e+308"   # DOUBLE_MAX (~1.8e308)
    "2.22507e-308"   # DOUBLE_MIN (~2.2e-308)
    
    # Invalid/ambiguous cases
    "123abc"         # Trailing chars → CHAR/INT?
    "123.456.789"    # Multiple dots → CHAR
    "."              # Only dot → CHAR
    "f"              # Only 'f' → CHAR
    ".f"             # Dot + 'f' → CHAR
    "1.23ff"         # Multiple 'f's → CHAR
    ""               # Empty string → Error
    "+"              # Only sign → CHAR
    "-"              # Only negative sign → CHAR
    "1e3"            # Scientific notation (valid if supported)
    "1e3f"           # Scientific notation + 'f' (valid if supported)
    
    # Non-ASCII/Unicode (if applicable)
    "é"              # Non-ASCII → CHAR?
    "字"             # Non-ASCII → CHAR?
    
    # Extreme values (beyond limits)
    "1e309"          # >DOUBLE_MAX → INF
    "-1e309"         # <DOUBLE_MIN → -INF
    "1e39f"          # >FLOAT_MAX → INF
    "-1e39f"         # <FLOAT_MIN → -INF
)

# Run each test case
for test in "${test_cases[@]}"; do
    echo -e "\nTesting: '$test'"
    ./Program "$test"
done

echo -e "\nAll tests completed."
