r = (1 + 8*input())**.5
print ["NO","YES"][int(r) == r and not ((int(r)-1) & 1)]
