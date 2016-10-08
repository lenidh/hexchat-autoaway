#!/bin/sh
mkdir -p obj
cd obj
gcc -Wall -Os -DWIN32 -c ../src/*.c

mkdir -p ../bin
cd ../bin
dllwrap.exe --def ../plugin.def --dllname autoaway.dll ../obj/*.o -lwtsapi32
