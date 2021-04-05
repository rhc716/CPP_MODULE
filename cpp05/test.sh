#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange
color4=\\033[1\;31m # red

if [ -f "00" ] && [ -f "01" ] && [ -f "02" ] && [ -f "03" ] ; then
	echo ""
else
	make -s
fi

make -s clean

echo -en "$color1"
echo -e "ex00"
echo -en "$color2"
./00

echo -en "$color1"
echo -e "\nex01"
echo -en "$color2"
./01

echo -en "$color1"
echo -e "\nex02"
echo -en "$color2"
./02

echo -en "$color1"
echo -e "\nex03"
echo -en "$color2"
./03

rm 0{0..3} 2>/dev/null