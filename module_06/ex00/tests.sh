# to print the executed command
set -x

# non print char 
./converter 0
echo

# printeable char
./converter 97
echo

# int 
./converter 128
echo

# int min 
./converter $((-2**31))
echo

# int max 
./converter $((2**31-1))
echo

# int min overflow
./converter $((-2**31-1))
echo

# int max 
./converter $((2**31))
echo

# double
./converter 97.999134
echo

# float
./converter 97.999134f
echo

# float scientific notations
./converter -inff
echo
./converter +inff
echo
./converter nanf
echo

# double scientific notations
./converter -inf
echo
./converter +inf
echo
./converter nan
echo