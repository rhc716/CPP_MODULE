#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange
color4=\\033[1\;31m # red

#-std=c++98
if [[ "$OSTYPE" == *"gnu"* ]]; then
	sed -i "s/#-std=c++98/-std=c++98/g" ./ex00/Makefile ./ex01/Makefile ./ex02/Makefile
else
	# BSD
	sed -i '' "s/#-std=c++98/-std=c++98/g" ./ex00/Makefile ./ex01/Makefile ./ex02/Makefile
fi

make -s -C ./ex00
make -s -C ./ex01
make -s -C ./ex02

if [[ "$OSTYPE" == *"gnu"* ]]; then
	sed -i "s/-std=c++98/#-std=c++98/g" ./ex00/Makefile ./ex01/Makefile ./ex02/Makefile
else
	# BSD
	sed -i '' "s/-std=c++98/#-std=c++98/g" ./ex00/Makefile ./ex01/Makefile ./ex02/Makefile
fi

mv ./ex00/00 .
mv ./ex01/01 .
mv ./ex02/02 .


make clean -s -C ./ex00
make clean -s -C ./ex01
make clean -s -C ./ex02

echo -en "$color1"
echo -e "ex00"
echo -en "$color2"
./00 

echo ""
echo -en "$color1"
echo -e "ex01"
echo -en "$color2"
./01

echo ""
echo -en "$color1"
echo -e "ex02"
echo -en "$color2"
./02

rm 00 01 02