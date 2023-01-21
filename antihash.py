"""
size_t get_hash(const struct Slice *s)
{
	size_t out = 5381;
	for (size_t i = 0; i < s->len; i++)
	{
		char const c = s->start[i];
		out = out * 33 + c;
	}
	return out;
}
"""

import numpy as np
import warnings
import random

warnings.filterwarnings('ignore')


def get_hash(s: str):
    ret = np.uint(5381)
    # ret = np.uint(0)
    for c in s:
        ret = ret * np.uint(33) + np.uint(ord(c))
    return ret

# generate 50,000 strings
# solved recurrence equation solution
# a(n) = 1/32c(33^n - 1) + 5381 * 33 ^ n


variable_list = []


def print_vars():
    for v in variable_list:
        print(f'print {v}')


for q in range(8, 17):
    n = 1 << q
    # print(f'len: {n}')

    s = ""
    t = ""

    for i in range(n):
        s += chr(ord('A') + i.bit_count() % 2)
        t += chr(ord('B') - i.bit_count() % 2)

    # print(get_hash(s))
    # print(get_hash(t))
    assert get_hash(s) == get_hash(t)

    print(f'{s}={random.getrandbits(5)}')
    print(f'print {s}')
    print(f'{t}={random.getrandbits(5)}')
    print(f'print {s}')
    print(f'print {t}')
