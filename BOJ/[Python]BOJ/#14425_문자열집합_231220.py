from itertools import count
import sys
input = sys.stdin.readline

# set 사용
s = set()
count = 0
n, m = map(int, input().split())

for _ in range(n):
    data = input().rstrip()
    s.add(data) # set은 add로 데이터 추가

# s = set([input().rstrip() for _ in range(n)])

for _ in range(m):
    data = input().rstrip()
    if data in s:
        count+=1

print(count)