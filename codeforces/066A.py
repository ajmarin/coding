n = int(input())
if n < -9223372036854775808 or n > 9223372036854775807:
	print("BigInteger")
elif n < -2147483648 or n > 2147483647:
	print("long")
elif n < -32768 or n > 32767:
	print("int")
elif n < -128 or n > 127:
	print("short")
else:
	print("byte")
