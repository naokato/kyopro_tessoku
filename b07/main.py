T = int(input())
N = int(input())
L = [ None ] * N
R = [ None ] * N
for i in range(N):
  L[i], R[i] = [int(x) for x in input().split()]

diff = [ 0 ] * (T + 1)

for i in range(N):
  diff[L[i]] += 1
  diff[R[i]] -= 1

S = [ 0 ] * (T)
S[0] = diff[0]

for i in range(1, T):
  S[i] = S[i - 1] + diff[i]

for i in range(0, T):
  print(S[i])
