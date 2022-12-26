# Name = Anupam 
# Roll number = 7210
# class = SE Comp B 

N = int(input('Enter number of books : ',))

# Take space separated input
Name = input('Enter name of books : ',).split()
Cost = list(map(int,input('Enter cost of books : ',).split()))

#Delet Duplicate entries
def duplicate(x) :	
	Name1 = []
	for i in x :
		if i not in Name1 :
			Name1.append(i)
	return Name1
print('List Of Books After Deleting Duplicate Entries : ',duplicate(Name))

#Arrange books in ascending order of their cost
def ascend(x) :
	Name1 = []
	Cost1 = []
	for i in range(N) :
		if x[i] not in Name1 :
			Name1.append(x[i])
			Cost1.append(Cost[i])
	Cost2 = list(Cost1)
	Name2 = []
	while len(Cost1)>0 :
		A = Cost1.index(min(Cost1)) 
		Name2.append(Name1[A])
		Cost1.pop(A)
		Name1.pop(A)
		if ValueError :
			continue
	return Name2,Cost2
A,B = ascend(Name)
print('Books Are In Ascending Order Of Their Costs Are : ',A)

#Number Of Books With Cost More Than 500
def number(x) :
	count = 0
	for j in x :
		if j > 500 :
			count+=1
	return count
print('Number Of Books With Cost More Than 500 : ',number(B))

#Books Having Cost Less Than 500
def Books(x) :
	lst = []
	for j in range(N) :
		if x[j] < 500 :
			lst.append(Name[j])
	return lst
print('Books Having Cost Less Than 500 : ',duplicate(Books(Cost)))