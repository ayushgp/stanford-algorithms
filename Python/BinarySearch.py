n,q=[int(x) for x in raw_input().split()]
a=[int(x) for x in raw_input().split()]
a.sort()
for i in range(q):
	b=int(raw_input())
	if b in a:
		print "YES"
	else:
		print "NO"