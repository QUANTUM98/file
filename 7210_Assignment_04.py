# Name = Anupam 
# Roll number = 7210
# class = SE Comp B 

for _ in range(int(input())) :
	a = int(input('Enter Number Of Students In First Class = ',))
	b = int(input('Enter Number Of Students In Second Class = ',))
	print('Details Of Students Of First Class')
	List_A = []				#stores details of division 1
	for i in range(a) :
		x = list(map(int,input('enter PRN,DAY,MONTH : ',).split()))
		List_A.append(x)
	print('Details of students of second class')
	List_B = []				##stores details of division 2
	for i in range(b) :
		x = list(map(int,input('enter PRN,DAY,MONTH : ',).split()))
		List_B.append(x)
	c = 0
	d = 0
	List_SE_Comp_DOB = []
	while c < a and d < b :
		if List_A[c][2] < List_B[d][2] :
			List_SE_Comp_DOB.append(List_A[c])
			c+=1
		elif List_A[c][2] > List_B[d][2] :
			List_SE_Comp_DOB.append(List_B[d])
			d+=1
		else :
			if List_A[c][1] < List_B[d][1] :
				List_SE_Comp_DOB.append(List_A[c])
				c+=1
			elif List_A[c][1] > List_B[d][1] :
				List_SE_Comp_DOB.append(List_B[d])
				d+=1
			else :
				List_SE_Comp_DOB.append(List_A[c])
				List_SE_Comp_DOB.append(List_B[d])
				c+=1
				d+=1
	while c < a :
		List_SE_Comp_DOB.append(List_A[c])
		c+=1
	while d < b :
		List_SE_Comp_DOB.append(List_B[d])
		d +=1
	print('sorted birthday list is : ',List_SE_Comp_DOB)