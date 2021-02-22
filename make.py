import os, sys
from shutil import copyfile

ARGS=sys.argv

CONTEST_FOLDER_PATH='C:/Users/wangg/OneDrive/Documents/GitHub/CP/contest/'
TEMPLATES_PATH='C:/Users/wangg/OneDrive/Documents/GitHub/CP/templates/'

print(f'Arguments{str(sys.argv)}')

FLAGS=['-f', '-l']

FILES=[]
LENGTHS=[] # s m l g

for i in range(0, len(ARGS)):
    ARGS[i] = ARGS[i].lower()
    if ARGS[i] == '-f':
        if i + 1 < len(ARGS):
            FILES=ARGS[i+1].split(',')
        else:
            print("Error in parsing arguments")
    if ARGS[i] == '-l':
        if i +1 < len(ARGS):
            LENGTHS=ARGS[i+1].split(',')
        else:
            print("Error in parsing arguments")
    if ARGS[i] == '-cf':
        FILES='A,B,C,D,E,F,G'.split(",")
        LENGTHS='v,s'.split(',')
    if ARGS[i] == '-usaco':
        FILES='problem1,problem2,problem3'.split(',')
        LENGTHS='v,v,v'.split(',')

while len(LENGTHS) < len(FILES):
    LENGTHS.append('l')

if len(FILES) < len(LENGTHS):
    LENGTHS = LENGTHS[0:len(FILES)]

for i in range(0, len(LENGTHS)):
    if(LENGTHS[i] == 'l'):
        LENGTHS[i] = 'LONG'
    if(LENGTHS[i] == 's'):
        LENGTHS[i] = 'SHORT'
    if(LENGTHS[i] == 'v'):
        LENGTHS[i] = 'VERYSHORT'
    if(LENGTHS[i] == 'g'):
        LENGTHS[i] = 'GUIDE'

# print(FILES)
# print(LENGTHS)

for i in range(0,len(FILES)):
    copyfile(TEMPLATES_PATH+LENGTHS[i]+".cpp", CONTEST_FOLDER_PATH + FILES[i] + ".cpp")