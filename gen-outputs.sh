#!/bin/sh

./a.out < test1-youlost > output1
./a.out < test2-uncover1 | head -n 25 > output2
./a.out < test3-uncover-rec | head -n 25 > output3
./a.out < test4-youwin > output4

