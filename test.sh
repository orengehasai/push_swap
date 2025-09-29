#!/bin/bash

NUMBER=100
COUNT=6
ARG=$(python3 -c "import random; print(' '.join(map(str, random.sample(range(-${NUMBER}, ${NUMBER} + 1), ${COUNT}))))")

PUSH_SWAP="./push_swap/push_swap"
CHECKER="./checker_Mac"

RED='\033[0;31m'
GREEN='\033[0;32m'
NC='\033[0m'

echo "Testing with: $ARG"

MOVES=$($PUSH_SWAP $ARG | wc -l)

RESULT=$($PUSH_SWAP $ARG | $CHECKER $ARG)

if [ "$RESULT" = "OK" ]; then
    echo -e "${GREEN}Result: $RESULT${NC}"
else
    echo -e "${RED}Result: $RESULT${NC}"
fi

echo "Number of moves: $MOVES"