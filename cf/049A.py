def is_letter(x): return 'a' <= x <= 'z' or 'A' <= x <= 'Z'
def is_vowel(x): return x in ['A','E','I','O','U','Y']
s = raw_input()[::-1].upper()
for c in s:
	if is_letter(c):
		print "YES" if is_vowel(c) else "NO"
		break
