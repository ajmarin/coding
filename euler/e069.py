primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
ans = 1
for i in primes:
	if ans * i > 1000000:
		print('Answer is', ans)
		break
	else: 
		ans *= i
