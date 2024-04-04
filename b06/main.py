N = int(input())
A = [int(x) for x in input().split()]
Q = int(input())
L = [ None ] * Q
R = [ None ] * Q
for i in range(Q):
  L[i], R[i] = [int(x) for x in input().split()]

sum = [ 0 ] * (N + 1)

for i in range(1, N + 1):
  sum[i] = sum[i - 1] + A[i - 1]

for i in range(Q):
  diff = sum[R[i]] - sum[L[i] - 1]
  criteria = (R[i] - L[i] + 1) / 2
  if diff > criteria:
    print("win")
  elif diff == criteria:
    print("draw")
  else:
    print("lose")
