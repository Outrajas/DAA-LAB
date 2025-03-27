#include <iostream>
using namespace std;

int findUnique(int arr[], int n) {
    int unique=-1;
    
    for (int i=0;i<=n;i++)
    { int unique = arr[i];
    	for(int j=0;i<=n;i++)
    	{
    		if(i==j)
    		continue;
    		else if(unique=arr[j])
    		{
			unique=-1;
    		continue;
    	    }
    		else
    		{return unique;
			}
    		
		}
	}
	return -1;
}

int main() {
    int arr[] = {7,8,2, 3, 5, 3, 2, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Unique element: " << findUnique(arr, n) << endl;
    return 0;
}

