f = open("input.txt","r")

lines = f.readlines()
maxred = 12
maxgreen = 13
maxblue = 14

total = 0

for line in lines:
    if line.strip()=='':
        break

    # print(line)
    g = line.split(':')
    id = int(g[0].split(' ')[1])
    games = g[1].split(';') 

    ok = True

    for game in games: 

        g = game.strip()
        cubes = g.split(',')
        for cube in cubes:
            c = cube.strip().split(' ')
            if (int(c[0])>maxred and c[1]=='red') or (int(c[0])>maxgreen and c[1]=='green') or (int(c[0])>maxblue and c[1]=='blue'):
                ok = False
                break
    if ok:
        total = total + id

    # print("game",id,"  result:", ok)

print(total)
f.close()

