// Name = Anupam
// Roll No = 7210
// SE COMP-B

#include <bits/stdc++.h>
using namespace std;
int iter = 0;

//linear search
void linear_search(int arr[], int size , int x)
{
        int count_linear = 0;
        bool flg = false;
        for(int i=0;i<size;i++)
        {
                if(x == arr[i])
                {                     
                        count_linear ++;
                        flg = false;
                        break;
                } 
                else 
                {
                        flg = true;
                        count_linear ++;
                }
        }
        
        if (flg == true)
        {
                cout<<"searched student did not attended program (using linear search";
        }
        
        else
        {
                cout<<"searched student attended the program,found with total iterations (using linear search) : "<<count_linear<<endl;
                
        }
}

//sentinel search
void sentinel_search(int arr[], int size , int key)
{
        int arr1[size+1];
        for(int i = 0 ; i<size ; i++)
        {
                arr1[i] = arr[i];
        } 
        arr1[size] = key;
        
        bool flg = true;
        
        for(int j = 0 ; j < size + 1 ; j++)
        {
                if ( j < size)
                {
                        if( arr1[j] == key)
                        {
                                cout<<"searched student attended the program, found at index (using sentinel search) "<<j<<endl;
                                flg = true;
                                break;
                        }
                        else
                        {
                                flg = false;
                        }
                }        
        }
        if (flg == false)
        {
                cout<<"searched student did not attended program (using sentinel search) "<<endl;
        }   
}

int main()
{   
        int n;
        cout<<"enter number of elements of the array : ";
        cin>> n;
        
        int arr[n];
        cout<<"enter the elements of array : ";
        for(int i=0;i<n;i++)
        {
                cin>>arr[i];
        }
        
        int x;
        cout<<"enter the element to search in the array : ";
        cin>>x;

        linear_search(arr,n,x);
        sentinel_search(arr, n , x);
        
        return 0;     
}


