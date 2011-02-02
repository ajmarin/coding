score = [0, 1]
n = input();
team1, team2 = raw_input(), ""
for i in range(n-1):
	s = raw_input()
	score[s == team1] += 1
	if s != team1: team2 = s
print team1 if score[1] > score[0] else team2

