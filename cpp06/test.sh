#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange
color4=\\033[1\;31m # red

make -s -C ./ex00
make -s -C ./ex01
make -s -C ./ex02

mv ./ex00/convert .
mv ./ex01/serialization .

make clean -s -C ./ex00
make clean -s -C ./ex01
make clean -s -C ./ex02

echo -en "$color1"
echo -e "ex00"
echo -en "$color2"

echo -en "$color3"
echo -e "./convert 42"
echo -en "$color2"
./convert 42

echo -en "$color3"
echo -e "./convert 50"
echo -en "$color2"
./convert 50

echo -en "$color3"
echo -e "./convert 127"
echo -en "$color2"
./convert 127

echo -en "$color3"
echo -e "./convert 128"
echo -en "$color2"
./convert 128

echo -en "$color3"
echo -e "./convert -128"
echo -en "$color2"
./convert -128

echo -en "$color3"
echo -e "./convert -129"
echo -en "$color2"
./convert -129

echo -en "$color3"
echo -e "./convert nan"
echo -en "$color2"
./convert nan

echo -en "$color3"
echo -e "./convert Nan"
echo -en "$color2"
./convert Nan

echo -en "$color3"
echo -e "./convert inf"
echo -en "$color2"
./convert inf

echo -en "$color3"
echo -e "./convert -inf"
echo -en "$color2"
./convert -inf

echo -en "$color3"
echo -e "./convert inff"
echo -en "$color2"
./convert inff

echo -en "$color3"
echo -e "./convert -inff"
echo -en "$color2"
./convert -inff

echo -en "$color3"
echo -e "./convert 0.1"
echo -en "$color2"
./convert 0.1

echo -en "$color3"
echo -e "./convert 0.12345f"
echo -en "$color2"
./convert 0.12345f

echo -en "$color3"
echo -e "./convert 1.79769e+308"
echo -en "$color2"
./convert 1.79769e+308

echo -en "$color3"
echo -e "./convert -1.79769e+308"
echo -en "$color2"
./convert -1.79769e+308

echo -en "$color3"
echo -e "./convert abc"
echo -en "$color2"
./convert abc

echo ""
echo -en "$color1"
echo -e "ex01"
echo -en "$color2"

for ((j=0; j<3; ++j));
do
	echo -en "$color3"
	echo -e "./serialization"
	echo -en "$color2"
	./serialization
done
rm ./convert
rm ./serialization