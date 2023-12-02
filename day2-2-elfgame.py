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

    red=green=blue=0

    for game in games: 

        g = game.strip()
        cubes = g.split(',')
        for cube in cubes:
            c = cube.strip().split(' ')
            
            if (int(c[0])>red and c[1]=='red'):
                red = int(c[0])
            elif (int(c[0])>green and c[1]=='green'):
                green = int(c[0])
            elif (int(c[0])>blue and c[1]=='blue'):
                blue = int(c[0])

    total = total + red*green*blue

    # print("game",id,"  result:", ok)

print(total)
f.close()

