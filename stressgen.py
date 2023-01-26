import uuid
import random

max_len = (int)(1e5)

prefix = """x = 0
y = 0
print x / y
z = x / y
print x / y / z
print x / (y / z)

x = 0
y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1 = 0
print x / y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1
z = x / y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1
print x / y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1 / z
print x / (y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1y1 / z)
"""

print(prefix)

suffix = """a = x * z + 5 ++ y
print a"""

values = []

for _ in range(max_len):
	id = 'a' + uuid.uuid4().hex[:4]
	large_num = random.getrandbits(3)


	print(f'{id} = {large_num}')
	values.append(id)

	# print(f'{id}++')
	# print(f'{id}--')
	# print(f'{random.choice(values)}++')
	# print(f'{random.choice(values)}--')

	# print(f'print {random.choice(values)} + ({random.choice(values)} * {random.choice(values)} / ( {random.choice(values)} * {random.choice(values)} ) + {random.choice(values)} % {random.choice(values)})')
	
print(suffix)