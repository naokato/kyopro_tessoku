N = int(input())

result = list()

while N != 0:
  remainder = N % 2
  if remainder == 1:
    result.append(1)
  else:
    result.append(0)
  N = N // 2

result.reverse()
print("".join(str(x) for x in result).zfill(10))
