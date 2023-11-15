# Question A

Your goal for this question is to write a program that accepts two lines (x1,x2) and (x3,x4) on the
x-axis and returns whether they overlap. As an example, (1,5) and (2,6) overlaps but not (1,5)
and (6,8).

## Solution

- [overlap.h](https://github.com/jfgauron/jeanfrederic_gauron_test/blob/main/question_a/src/overlap.h)

- [test_overlap.cc](https://github.com/jfgauron/jeanfrederic_gauron_test/blob/main/question_a/test/test_overlap.cc)

## Build and test
```
cmake -Bbuild
cd build
make
make test
```