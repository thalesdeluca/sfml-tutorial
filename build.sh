FILE=$1
OUT=$2

g++ -c $FILE.cpp
g++ $FILE.o -o $OUT -lsfml-graphics -lsfml-window -lsfml-system
./$OUT