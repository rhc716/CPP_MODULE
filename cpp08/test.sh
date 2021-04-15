#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange
color4=\\033[1\;31m # red


make
make clean

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


rm 00 01 02