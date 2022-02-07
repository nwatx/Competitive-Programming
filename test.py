l = """3 693
10 196
12 182
14 22
15 587
31 773
38 458
39 58
40 583
41 992
84 565
86 897
92 197
96 146
99 785"""


for line in l.splitlines():
	splt = line.split()
	print(f'({splt[0]}, {splt[1]}),', end="")