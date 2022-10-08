from random import shuffle


letters = ['h','o','o','p']

cnt = 0
for i in range(0, 1000000):
    shuffle(letters)
    if(''.join(letters) == "hoop"):
        cnt += 1

print(cnt / 1000000)