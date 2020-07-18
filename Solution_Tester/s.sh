#!/bin/bash

# to color the output text in different colours
green=$(tput setaf 71);
red=$(tput setaf 1);
blue=$(tput setaf 32);
orange=$(tput setaf 178);
bold=$(tput bold);
reset=$(tput sgr0);

# You can change the version of C++ or add the compiler flags you wish
g++ -std=c++17 testcase_generator.cpp -o generator || { echo ${bold}${orange}Compilation Error in ${reset} testcase_generator.cpp; exit 1; }
g++ -std=c++17 subject.cpp -o original || { echo ${bold}${orange}Compilation Error${reset} in subject.cpp; exit 1; }
g++ -std=c++17 brute.cpp -o brute || { echo ${bold}${orange}Compilation Error${reset} in brute.cpp; exit 1; }

if [ $# -ne 1 ]
	then
		max_tests=30
	else
		max_tests=$1
fi

diff_found=0
i=1

while [ $i -le $max_tests ]
do
	# Generate test_case and save it in input1.txt
	./generator > input1.txt

	# run original solution, take input from above generated test case i.e. from input1.txt
	# and save it in original_output.txt
	./original < input1.txt > original_output.txt

	# run brute force solution, take input from above generated test case i.e. from input1.txt
	# and save it in brute_output.txt
	./brute < input1.txt > brute_output.txt

	# check if files original_output and brute_output
	# differs(we are ignoring spaces and then comparing files)
    if diff --tabsize=1 -F --label --side-by-side --ignore-space-change original_output.txt brute_output.txt > dont_show_on_terminal.txt; then
	    echo "${orange}test_case #$i: ${bold}${green}passed${reset}"
	else
		echo "${orange}test_case #$i: ${bold}${red}failed${reset}"
		diff_found=1
		break
	fi
	i=$((i+1))
done

if [ $diff_found -eq 1 ]
then
	echo "${blue}Input: ${reset}"
	cat input1.txt
	echo ""

	echo "${blue}Output: ${reset}"
	cat original_output.txt
	echo ""

	echo "${blue}Expected: ${reset}"
	cat brute_output.txt
	echo ""
fi

rm input1.txt
rm generator
rm original
rm brute
rm original_output.txt
rm brute_output.txt
rm dont_show_on_terminal.txt

