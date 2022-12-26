// Name = Anupam
// Roll No = 7210
// SE COMP-B

#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

// Quick sort

void quicksort(int arr[],int start,int end,int n)
{
  int i=start+1,j=end;
  if(i<=j)
  {
      int pivot=arr[start];
      while(i<j)
  {
      while(arr[i]<=pivot && i<end)
        i++;
      while(arr[j]>=pivot && j>start)
        j--;
      if(i<j) swap(arr[i],arr[j]);
      else break;
  }
  if(i>=j)
  { 
      if(arr[j]<arr[start])
      swap(arr[j],arr[start]);
  } 

  for(int i=0;i<n;i++)
  {cout<<arr[i]<<" ";}
  cout<<endl; 
    
  quicksort(arr,j+1,end,n);
  quicksort(arr,start,j-1,n);
  }
}

// Radix sort

void radix_sort(int size, int array[])
{
	int x, arr_max=0;
	int length=1;

  int arr[size];
  queue<int> q[10];
  for(int i = 0; i < size ; i++)
    {
      arr[i] = array[i];
      q[arr[i]%10].push(arr[i]);
      if (arr[i] > arr_max)
      { arr_max = arr[i];}
    }

	while (arr_max>0) 
	{arr_max/=10; length++; }

	int d =10;
	while(length--){
		int n=0;

		for (int i=0; i<10; i++){
			
			while(!q[i].empty())
			{		
				arr[n] =q[i].front();
				q[i].pop(); n++;
			}
		}
		
		for (int i=0; i<size; i++)
		{
			int r=arr[i]; 
			cout << arr[i] << " ";
			q[(r/d)%10].push(arr[i]);
		}
		d*=10;
		cout << endl;
	}
}


signed main()
{
    int n;
    cout<<"enter the total number of students : ";
    cin>>n;
    int arr[n];
    cout<<"enter percentage marks of students : ";
    for(int i = 0; i < n ; i++)
    {
      cin>>arr[i];
    }
    cout<<endl;
    
    int start=0, end=n-1; 
    cout<<"-----------------------quick sort---------------------"<<endl;
    quicksort(arr,start,end,n);
    
    cout<<"-----------------------radix sort---------------------"<<endl;
    radix_sort(n, arr);

    return 0;
}

