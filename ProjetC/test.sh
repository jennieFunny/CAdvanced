#!/bin/bash
make
for i in ./test/*.c
do
make clean
BASENAME="${i%.*}"
gcc "$i" -Wall -ansi -lrt
./a.out
mv ./test/profile.log "$BASENAME".log
make clean
done

for j in ./test/*.log
do
./bin/myprofiler "$j"
done