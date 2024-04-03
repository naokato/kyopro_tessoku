N = input()

keta = 0
answer = 0
for c in [int(x) for x in reversed(N)]:
  if c == 1:
    answer += 1 << keta
  keta += 1
print(answer)
