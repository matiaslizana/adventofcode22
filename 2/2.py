rounds = open("2/guide.txt", "r").read().splitlines()
''' 
X / A = Rock (0)
Y / B = Paper (1)
Z / C = Scisors (2)

[-1, 0, 1]
Rock - Scisors  0 - 2 = 1  (Guanya)
Paper - Rock    1 - 0 = 1  (Guanya)
Scisors - Paper 2 - 1 = 1  (Guanya)
Rock - Rock     0 - 0 = 0  (Empate)
Paper - Paper   1 - 1 = 0  (Empate)
Sisors - Sisors 2 - 2 = 0  (Empate)
Paper - Scisors 1 - 2 = 2  (Perd)
Scisors - Rock  2 - 0 = 2  (Perd)
Rock - Paper    0 - 1 = 2  (Perd)

2 (Perd) => (2 + 1) * 3 = 9 % 9 = 0
0 (Empate) => (0 + 1) * 3 = 3
1 (Guanya) => (1 + 1) * 3 = 6

'''
totalScore = 0
for r in rounds:
    moves = r.split(' ')
    scoreFirst = ord(moves[0]) - 64
    scoreSecond = ord(moves[1]) - 87
    roundScore = ((((scoreSecond - scoreFirst) % 3) + 1) * 3) % 9
    totalScore = totalScore + scoreSecond + roundScore
print(totalScore)
