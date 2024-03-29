N, X = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]

doesInclude = False

for a in A:
  if a == X:
    doesInclude = True
    break

if doesInclude:
  print("Yes")
else:
  print("No")
