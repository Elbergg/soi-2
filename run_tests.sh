#!/bin/sh

echo "Running tests"

for test_x in test test2 test3 test4 test5
do
    echo "Running $test_x..."
    ./$test_x
    if [ $? -ne 0 ]; then
        echo "$test_x failed with $?"
    fi
    echo "$test_x completed"
    sleep 5
done

echo "Finished running tests"
