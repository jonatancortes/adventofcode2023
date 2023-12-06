import re
f = open("input2.txt","r")
lines = f.readlines()
f.close()

score = {i:1 for i in range(0,len(lines))}

for index in score:
    line = lines[index]

    numbers = [int(i) for i in re.findall(r'[0-9]+', line.split(':')[1])]
    d = {i:numbers.count(i) for i in numbers}
    winners = len([k for k in d if d[k]>1])
    if winners>0:
        k = score[index]
        for i in range(index + 1, index + winners + 1):
            score[i] = score[i] + k

print(sum([score[k] for k in score]))

