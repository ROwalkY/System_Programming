#!/bin/bash


if [ $# != 2 ]; then
  echo "Correct call: $0 <name> <dataFile>"
  exit;
fi

echo `grep -i $1 $2`
