#!/usr/bin/python
# Usage: echo 10 | ./generator.py | ./a.out

N = eval(raw_input())

import os
import random
print random.randrange(1, N/2)
for i in range(N):
	print random.randrange(1, N/2),

