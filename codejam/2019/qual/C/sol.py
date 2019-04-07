def gcd(x, y):
  if not y: return x
  return gcd(y, x % y)

def solve(testcase):
  N, L = [int(s) for s in raw_input().split(" ")]
  a = [int(s) for s in raw_input().strip().split(" ")]
  ans = [0] * (L+1)
  start = 1
  for i in range(1, L):
    if a[i] != a[i-1]:
      start = i
      break
  v = gcd(a[start], a[start-1])
  ans[start] = v
  for i in range(start-1, -1, -1):
    ans[i] = a[i] / ans[i+1]
  for i in range(start+1, L+1, 1):
    ans[i] = a[i-1] / ans[i-1]
  primes = set()
  for v in ans:
    primes.add(v)
  mp = dict()
  for i, v in enumerate(sorted(primes)):
    mp[v] = i
  print("Case #{}: {}".format(testcase, ''.join([chr(mp[v]+ord('A')) for v in ans])))

t = int(raw_input()) # read a line with a single integer
for i in range(1, t + 1):
  solve(i)
