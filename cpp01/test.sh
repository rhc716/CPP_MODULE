#!/bin/bash

color1=\\033[38\;5\;50m # light gr03333
color2=\\033[38\;5\;75m # b033ue
color3=\\033[38\;5\;214m # Orange

pause(){
	read -s -n 1 -p "Press any key to continue . . ."
	echo ""
}

# ex00 ~ ex06

cc="clang++ -Wall -Wextra -Werror "
for ((i=0; i<7; ++i));
do
	echo -e "$color1 # ex0${i}" 
	echo -e "$color2"
	$cc ex0${i}/*.cpp 
	./a.out
	echo -e "$color3"
	pause
	echo ""
done

# ex07

echo -e "$color1 # ex07" 
make -s -C ex07
echo -e "$color3"
echo "#####################################"
echo "              test.txt"
echo "#####################################"
echo -e "$color2"
cat ./ex07/test.txt
echo -e "$color3\n"
echo "#####################################"
echo "              and -> N"
echo "#####################################"
echo -e "$color2"
./ex07/replace ./ex07/test.txt and N
cat ./ex07/test.txt.replace
echo -e "$color3\n"
pause
echo ""
echo "#####################################"
echo "              and -> NNNNNNN"
echo "#####################################"
echo -e "$color2"
./ex07/replace ./ex07/test.txt and NNNNNNN
cat ./ex07/test.txt.replace
echo -e "$color3\n"
pause
echo ""
echo "#####################################"
echo "              Part -> PPPPPPPPPP"
echo "#####################################"
echo -e "$color2"
./ex07/replace ./ex07/test.txt Part PPPPPPPPPP
cat ./ex07/test.txt.replace
echo -e "$color3\n"
echo "#####################################"
echo "                 end"
echo "#####################################"
make fclean -s -C ex07
rm ./ex07/test.txt.replace a.out