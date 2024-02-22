#!/bin/bash
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m'

g++ $1.cpp -o ./exe/$1-app
cd ./exe

counter=1
echo -e "${YELLOW}Questão: $1${NC}"
while [ $counter -le $2 ]; do
    output_file="../output/$1/output$counter.txt"
    input_file="../input/$1/test$counter.txt"
    if [ ! -e "$output_file" ]; then
        touch "$output_file"
    fi


    ./$1-app $counter < "$input_file"
    if [ "$3" == "show" ]; then
        echo -e "${GREEN}teste $counter${NC}:"
        ./show < "$output_file";
    fi
    ((counter++))
done

