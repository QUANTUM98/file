# Name = Anupam 
# Roll number = 7210
# class = SE Comp B 

n1 = int(input('enter number  of rows in 1st matrix :',))
m1 = int(input('enter number  of columns in 1st matrix :',))
a = []				#1st matrix
for i in range(n1) :
	b = list(map(int,input('enter entries of row :',).split()))
	a.append(b)

def cloning(l1) :
	l2 = [i for i in l1]
	return l2

z = cloning(a)
y = cloning(a)

n2 = int(input('enter number  of rows in 2nd matrix :',))
m2 = int(input('enter number  of columns in 2nd matrix :',))
c = []				#2nd matrix
for i in range(n2) :
	b = list(map(int,input('enter entries of row :',).split()))
	c.append(b)

#upper triangle matrix
g = True
for i in range(n1) :
	for j in range(m1) :
		if i>=j :
			if z[i][j] != 0 :
				g = False
if g == True :				
	print("it is a upper triangular matrix")
else :
	print("it is not a upper triangular matrix")

#transpose
print('original matrix is')
for i in range(len(a)) :
	print(*(a[i]))
print('transpose of matrix is')
e = []
for i in range(m1) :
	b = []
	for j in range(n1) :
		b.append(a[j][i])
	e.append(b)		
for i in range(len(e)) :
	print(*(e[i]))

# addition
addition = []
for i in range(n1) :
	b = []
	for j in range(m1) :
		b.append(a[i][j] + c[i][j])
	addition.append(b)
print('added matrix is : ')
for i in range(len(addition)) :
	print(*(addition[i]))

#multiplication
if m1 == n2 :
	multiply = []
	for i in range(n1) :
		b = []
		for j in range(m2) :
			d = []
			for k in range(m1):
				d.append(a[i][k] * c[k][j])
			b.append(sum(d))
		multiply.append(b)
	print('multiplied matrix is : ')
	for i in range(len(multiply)) :
		print(*(multiply[i]))
else :
	print('multiplication not possible')

#saddle point
d = 0
e = 0
b = 0
count = 0
g = False
for i in range(n1) :
	b = c[i][0]
	for j in range(m1) :
		if c[i][j] < b :
			b = c[i][j]
			d = j
			e = i
	count = 0
	for k in range(n1) :
		if b < c[k][d] :
			break
		else :
			count+= 1
	if count == n1  :
		g = True
		break
if g == False :
	print('saddle point for 2nd matrix does not exist')
else :
	print('saddle point of 2nd matrix is : ',b)	
	
#magic square

#1st diagonal
sum = 0
for i in range(n1) :
	sum+= a[i][i]
print("sum of diagonal elements of 1st matrix is",sum)

#2nd diagonal
count = 0
for i in range(n1):
	count += a[i][m1 - (i+1)]
if sum == count:
	g = False
	for i in range(n1):
		b = 0
		for j in range(m1) :
			b += a[i][j]
		if sum != b :
			print("1st matrix is not a magic square")
			g = False
			break
		else :
			g = True
	if g == True :
		h = 0
		for j in range(m1) :
			b = 0
			for i in range(n1) :
				b += a[i][j]
			if sum != b :
				print("1st matrix is not a magic square")
				h = 0
				break
			else :
				h = 1
	if h == 1 :
		print("1st matrix is a magic square")
else :
	print("1st matrix is not a magic square")