N = int(input())
A = [int(x) for x in input().split()]


Answer = False
for i in range(N - 2):
  for j in range(i + 1, N - 1):
    for k in range(j + 1, N):
      total = A[i] + A[j] + A[k]
      if total == 1000:
        Answer = True
        break

if Answer:
  print("Yes")
else:
  print("No")
