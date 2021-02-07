import os, sys

ARGS=sys.argv

print(f'Arguments{str(sys.argv)}')

OUTPUT="-u"

if '-cf' in sys.argv:
    OUTPUT = '-cf'

if '-cses' in sys.argv:
    OUTPUT = '-cses'

if OUTPUT == 'cf':
    