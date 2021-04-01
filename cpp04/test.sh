#!/bin/bash

if [ -f "00" ] && [ -f "01" ] && [ -f "02" ] && [ -f "03" ] ; then
	echo ""
else
	make -s
fi

./00 | cat -e > ex00_out
./01 | cat -e > ex01_out

diff -s ./test_srcs/ex00 ex00_out
diff -s ./test_srcs/ex01 ex01_out

make -s fclean
rm ex0{0..3}_out 2>/dev/null