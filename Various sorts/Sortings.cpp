#include <bits/stdc++.h>
using namespace std;
 
#define mod 10000007
#define int long long 
#define N 200005
#define INF 1e9
#define endl "\n"

/* Selection sort:
Find min out of n elements swap with 1st->
Find min out of n-1 elements swap with 2nd ... */

void sort(int *arr, int n){
    for(int i=0;i<n-1;i++){
        int mini=i;
        for(int j=i+1;j<n;i++){
            if(a[j]<a[i])mini=j;
        }
        swap(a[i],a[j]);
    }
}

/*Bubble sort:
Swap adj elements if they are in wrong order in n-1 passes
*/

void sort(int *arr, int n){
    for(int i=0;i<n-1;i++){//nth pass chks if the array is sorted
        for(int i=1;i<n;i++)if(a[i]<a[i-1])swap(a[i],a[i-1]);
    }
}

/*Insertion sort:
We maintain two arrays(sorted & unsorted).
Compare element from US to S.
If the element is smaller than its predecesor,
shift all the elements greater than it by 1 place
*/

void sort(int *arr, int n){
    for(int i=1;i<n;i++){
        int j=i-1,key=arr[i];
        while(j>=0 && arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

/*Merge Sort:
Divide and conquer
*/

void merge(int *arr, int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int tem1[n1],tem2[n2];
    for(int i=0;i<n1;i++)tem1[i]=arr[l+i];
    for(int i=0;i<n2;i++)tem[i]=arr[m+1+i];
    int i=0,j=0;
    while(i<n1 && j<n2){
        if(tem1[i]<tem2[j]){arr[l]=tem1[i];i++;}
        else {arr[l]=tem2[j];j++;}
        l++;
    }
    while(i<n1){arr[l]=tem1[i];i++;l++;}
    while(j<n2){arr[l]=tem2[j];i++;l++;}
}

void sort(int *arr, int l, int r){
    int m=(l+r)/2;
    if(l<r){
        sort(arr,l,m);
        sort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

/*Quick Sort*/

int partition(int *arr, int l, int r){
    int pivot=arr[l];
   int j=l;
   for(int i=l+1;i<=r;i++)
      {
        if(arr[i]<=pivot)
            {j++;
              swap(arr[j], arr[i]);
            }

      }
      swap(arr[l], arr[j]);
  	return j;
}

void sort(int *arr, int l, int r){
    if(l<=r){
        int m=partition(arr,l,r);
        sort(arr,l,m-1);
        sort(arr,m+1,r);
    }
}
