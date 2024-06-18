#!/bin/bash

echo './RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"'
./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"

echo '\n./RPN "7 7 * 7 -"'
./RPN "7 7 * 7 -"

echo '\n./RPN "1 2 * 2 / 2 * 2 4 - +"'
./RPN "1 2 * 2 / 2 * 2 4 - +"

echo '\n./RPN "(1 + 1)"'
./RPN "(1 + 1)"
