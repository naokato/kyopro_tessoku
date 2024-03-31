D = int(input())
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
  L[i], R[i] = [int(x) for x in input().split()]

diff = [ 0 ] * (D + 2)

for i in range(N):
  diff[L[i]] += 1
  diff[R[i] + 1] -= 1

S = [ 0 ] * (D + 1)
for i in range(1, D + 1):
  S[i] = S[i - 1] + diff[i]
  print(S[i])
