#!/bin/bash

echo "A tester for seeing how a new shell increases its shell level at creation"

rm -f tester_output.txt
touch tester_output.txt

>>tester_output.txt echo "Basic, simple numbers--------------------------------"
VAR=0
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=2
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Positive, signed numbers-----------------------------"

VAR=+7
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=" + 7"
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Negative, simple numbers-----------------------------"
VAR=-1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=-2
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Multiple Signs with numbers--------------------------"
VAR=++1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=+-1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=-+1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=--1
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Complex numbers--------------------------------------"
VAR="  0    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  -0    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  +0    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  997    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  998    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  999   "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  +1000   "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  +999999   "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Overflow numbers--------------------------------------"
>>tester_output.txt echo "Parent Number -> Raw Child Number"
>>tester_output.txt echo "	INT_MAX - 1 -> INT_MAX"
VAR="  2147483646    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MAX -> INT_MIN"
VAR="  2147483647    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MAX + 1 -> INT_MIN + 1"
VAR="  2147483648    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MIN + 1 -> INT_MIN + 2"
VAR="  -2147483647    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MIN -> INT_MIN + 1"
VAR="  -2147483648    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MIN - 1 -> INT_MIN"
VAR="  -2147483649    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MIN - 2 -> INT_MAX"
VAR="  -2147483650    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "	INT_MIN - INT_MAX + 40 -> 42"
VAR="  -4294967255    "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Strings and letters----------------------------------"
VAR=a
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=-a
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR=+a
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Whitespace tests, simple numbers---------------------"
VAR="  +7  "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  -7  "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Whitespace tests, simple numbers with chars----------"
VAR="  7  a"
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="a  7  "
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

VAR="  7  a 5"
>>tester_output.txt echo -n $VAR
export SHLVL=$VAR
>>tester_output.txt bash << 'EOF'
echo "->$SHLVL"
EOF

>>tester_output.txt echo "Conclusions:-----------------------------------------"
>>tester_output.txt echo "Numbers MAY have whitespaces at the start"
>>tester_output.txt echo "After that, there MAY be one + or - sing, which will influence the number"
>>tester_output.txt echo "Then there MUST be at least one digit"
>>tester_output.txt echo "All digits after and with it another are taken as a number"
>>tester_output.txt echo "That number MAY freely over/underflow, without protection"
>>tester_output.txt echo "The next non digit MAY be another pair of whitespaces"
>>tester_output.txt echo "Then the string MUST be a '\0'"
>>tester_output.txt echo "Interpetation:---------------------------------------"
>>tester_output.txt echo "If any of the above MUST statements are broken, the <new value> is 1"
>>tester_output.txt echo "If the <atoied value> + 1 is negative, the <new value> is 0"
>>tester_output.txt echo "If the <atoied value> + 1 is (positive and) bigger then 999,"
>>tester_output.txt echo "an error is given to stderr, displaying the <atoied value> + 1 and"
>>tester_output.txt echo "the <new value> is 1"
>>tester_output.txt echo "Otherwise, the number is valid, and the <new value> is <atoied value> + 1"

cat tester_output.txt