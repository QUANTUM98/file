# Name = Anupam 
# Roll number = 7210
# class = SE Comp B 

N = int(input('Total Number Of Students =',))

# Take Space Separated Input
Cricket =  list(map(int,input('Enter Roll Number Of Students Playing Cricket =',).split()))
Football = list(map(int,input('Enter Roll Number Of Students Playing Football =',).split()))
Badminton = list(map(int,input('Enter Roll Number Of Students Playing Badminton =',).split()))

# Students Play Both Cricket And Badminton
def intersection(lst1,lst2) :
	ans = []
	for j in lst1 :
		if j in lst2 :
			ans.append(j)
	return ans

print('Students Play Both Cricket And Badminton Are =',intersection(Cricket,Badminton))

# Students Playing Either Cricket Or Badminton But Not Both
def sym(lis1, lis2):
	final = []
	for j in lis1:
		if j not in lis2:
			final.append(j)
	for j in lis2:
		if j not in lis1:
			final.append(j)
	return final		
print('Students Play Either Cricket Or Badminton But Not Both Are =',sym(Cricket,Badminton))


#Number Of Students Who Play Neither Cricket Nor Badminton
z = sym(Cricket,Badminton) + intersection(Cricket,Badminton)				
print('Number Of Students Play Neither Cricket Nor Badminton Are =',N-len(z))

# Number Of Students Who Play Cricket And Football But Not Badminton
cf = []
for j in Cricket :
	if j in Football:
		if j not in Badminton :
			cf.append(j)
print('Number of students who play cricket and football but not badminton are =', len(cf))

# students playing at least one game
def at_least_one(lst1,lst2,lst3,total) :			#total is total number of students
	ans = []
	for j in range(1,total+1) :
		if j in lst1 or j in lst2 or j in lst3 :
			ans.append(j)
	return ans

print('students playing at least one game : ',at_least_one(Cricket,Badminton,Football,N))

# students playing all three games games
x = []
for j in intersection(Cricket,Badminton) :
	if j in Football :
		x.append(j)
print('students playing all three games games = ',x)

#number of students not playing any game
print("number of students not playing any game = ", N - len(at_least_one(Cricket,Badminton,Football,N)))