N, Q = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
L = [ None ] * Q
R = [ None ] * Q
for i in range(Q):
  L[i], R[i] = [int(x) for x in input().split()]

S = [ None ] * (N + 1)
S[0] = 0

for n in range(1, N + 1):
  S[n] = S[n - 1] + A[n - 1] 

for i in range(Q):
  print(S[R[i]] - S[L[i] -1])
