N, K = [int(x) for x in input().split()]

count = 0
for red in range(1, N + 1):
  for blue in range(1, N + 1):
    diff = K - red - blue
    if 1 <= diff and diff <= N:
      count += 1
      continue

print(count)
