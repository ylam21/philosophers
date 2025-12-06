#!/bin/bash

FILENAME=$1
TOTAL_PHILOS=$2

if [ -z "$FILENAME" ] || [ -z "$TOTAL_PHILOS" ]; then
    echo "Usage: ./checker.sh <logfile> <number_of_philos>"
    exit 1
fi

for (( i=1; i<=TOTAL_PHILOS; i++ ))
do
    TIMES=$(grep -E "^[0-9]+ $i is eating" "$FILENAME" | wc -l)
    echo "Philo $i has eaten $TIMES times."
done
