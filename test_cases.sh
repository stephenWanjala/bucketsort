#!/bin/bash

# Compile the code
make

# Define test cases
declare -a inputs=("This is a simple example with 8 words."
                   "This is a simple example with 8 words."
                   "This is a simple example with 8 words."
                   "I'd rather go shopping than go to the gym!")

declare -a args=("bucketsort"
                 "bucketsort strawberry blackberry"
                 "bucketsort apple carrot kiwi pineapple watermelon"
                 "bucketsort mango")

# Run test cases
for i in "${!inputs[@]}"; do
    echo "Test Case #$i:"
    echo "Input: ${inputs[$i]}"
    echo "Command: ${args[$i]}"
    echo -e "${inputs[$i]}" | ./${args[$i]}
    echo
done