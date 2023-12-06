import re
f = open("input.txt","r")

lines = f.readlines()
total = 0

for line in lines:
    if not line.strip():
        break
    numbers = [int(i) for i in re.findall(r'[0-9]+', line.split(':')[1])]
    d = {i:numbers.count(i) for i in numbers}
    winners = len([k for k in d if d[k]>1])
    if winners>0:
        total = total + pow(2,winners-1)

print(total)
f.close()

