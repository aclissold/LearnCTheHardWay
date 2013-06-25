#!/usr/bin/env python3
import sys
from time import time
def main():
    start_time = time()
    # go through each string in argv
    # why am I skipping argv[0]
    if len(sys.argv) > 1:
        for i in range(1, len(sys.argv)):
            print('arg {0}: {1}'.format(i, sys.argv[i]))

    # let's make our own array of strings
    states = ['California', 'Oregon',
              'Washington', 'Texas']
    num_states = 4
    
    for i in range(num_states):
        print('state {0}: {1}'.format(i, states[i]))
    print(time() - start_time, "seconds")

if __name__ == '__main__':
    main()
