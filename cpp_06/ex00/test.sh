#!/bin/bash

file_path="./convert"

if [ -f "$file_path" ]; then
	echo "File exists"
else
	echo "File does not exist"
	make
fi

echo "\nTest 1 : ./convert 33"
./convert 33

echo "\nTest 2 : ./convert a"
./convert a

echo "\nTest 3 : ./convert -42"
./convert -42

echo "\nTest 4 : ./convert 4.2f"
./convert 4.2f

echo "\nTest 5 : ./convert 4.2"
./convert 4.2

echo "\nTest 6 : ./convert nan"
./convert nan

echo "\nTest 7 : ./convert +nan"
./convert +nan

echo "\nTest 8 : ./convert -nan"
./convert -nan

echo "\nTest 9 : ./convert inf"
./convert inf

echo "\nTest 10 : ./convert +inf"
./convert +inf

echo "\nTest 11 : ./convert -inf"
./convert -inf

echo "\nTest 12 : ./convert inff"
./convert inff

echo "\nTest 13 : ./convert +inff"
./convert +inff

echo "\nTest 14 : ./convert -inff"
./convert -inff

echo "\nTest 15 : ./convert str"
./convert str