rounds = open("2/guide.txt", "r").read().splitlines()
''' 
A = Rock (1)
B = Paper (2)
C = Scisors (3)
X = LOSE
Y = DRAW
Z = WIN

1 Rock - 1 Lose 3
1 Rock - 2 Draw 1
1 Rock - 3 Win 2
2 Paper - 1 Lose 1
2 Paper - 2 Draw 2
2 Paper - 3 Win 3
3 Scisors - 1 Lose 2
3 Scisors - 2 Draw 3
3 Scisors - 3 Win 1
'''

totalScore = 0
for r in rounds:
    moves = r.split(' ')
    scoreFirst = ord(moves[0]) - 64
    prediction = ord(moves[1]) - 87
    scoreSecond = (prediction + scoreFirst % 3) % 3 + 1
    roundScore = ((prediction - 1) * 3) % 9
    totalScore = totalScore + scoreSecond + roundScore
print(totalScore)
