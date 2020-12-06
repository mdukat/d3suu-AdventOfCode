# Advent of Code 2020

## Files
 - `day*.c` - source for each day
 - `day*.txt` - input data for each day

## Compile
Good old `gcc day1.c -o day1` should do it, except when stated otherwise (`head -n1 day5.c`).

## Why input in array
It's quicker and more convenient for me to do build array in vim, than to read file in C.
```
When vim buffer is only input data:
:%s/^/"/
:%s/$/",/
gg0ichar* datain[] = {<ESC>
G$dlA};<ESC>
```
