import re
r = raw_input
o, p = r(), r()+'.*'+r()
x = re.compile(p)
f = x.search(o) > 0
b = x.search(o[::-1]) > 0
print ["fantasy","backward","forward","both"][b + (f << 1)]
