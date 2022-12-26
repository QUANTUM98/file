# Name = Anupam 
# Roll number = 7210
# class = SE Comp B 

# The Average Score Of The Class

def Average(list):
    Sum=0
    count=0
    for j in range(len(list)):
        if list[j]!=-33:
            Sum+=list[j]
            count+=1
    Avg=Sum/count
    print("Total Marks Obtained in Fundamental Of Data Structure  = ", Sum)
    print("Average Marks Obtained in Fundamental Of Data Structure = {:.2f}".format(Avg))


# Highest Score In The Fundamental Of Data Structure Test for the class

def Maximum(list):
    for j in range(len(list)):
        if list[j]!=-33:
            Max=list[0]
            break
    for j in range(1,len(list)):
        if list[j]>Max:
            Max=list[j]
    return(Max)


# Lowest score In The Fundamental of Data Structure test for the class

def Minimum(list):
    for j in range(len(list)):
        if list[j]!=-33:
            Min=list[0]
            break
    for j in range(1,len(list)):
        if list[j]!=-33:
            if list[j]<Min:
                Min=list[j]
    return(Min)


# Count Of Students Wo Are Absent For The Test

def absentcount(list):
    count=0
    for j in range(len(list)):
        if list[j]==-33:
            count+=1
    return(count)


# Display Marks With Highest Frequency
def maxFrequency(list):
    i=0
    Max=0
    print("Marks  ==  Frequency")
    for j in list:
        if (list.index(j)==i):
            print(j,"   ==  ",list.count(j))
            if list.count(j)>Max and j >= 0:
                Max=list.count(j)
                Mark=j
        i=i+1
    return(Mark,Max)


MarksinFDS=[]
N = int(input("Enter total number of students : "))
for j in range(N):
    Marks=int(input("Enter Marks Of Student "+str(j+1)+" : "))
    MarksinFDS.append(Marks)
      
Average(MarksinFDS)
print("Highest Score in Class = ", Maximum(MarksinFDS))
print("Lowest Score in Class = ", Minimum(MarksinFDS))
print("Number Of Students Absent In The Test : ", absentcount(MarksinFDS))
Mark,fr = maxFrequency(MarksinFDS)
print("Highest frequency is of marks {0} that is {1} ".format(Mark,fr))