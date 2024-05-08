#!/bin/bash
g++ 3139-2.cpp -o a
sleep 0.5
cd tests
echo 'teste 1'
sleep 0.2
../a < test1.txt