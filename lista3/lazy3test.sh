#!/bin/bash
g++ 1944.cpp -o a
sleep 0.5
cd tests
echo 'teste 1'
sleep 0.2
../a < test1.txt
echo 'teste 2'
sleep 0.2
../a < test2.txt
echo 'teste 3'
sleep 0.2
../a < test3.txt
cd ..