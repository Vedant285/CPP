#include<bits/stdc++.h>
using namespace std;
void mergesort(int arr[],int beg,int mid,int end)
{
    int i,j,k;
    int n1=mid-beg+1,n2=end-mid;
    int a[n1],b[n2];
    for ( i = 0; i < n1; i++)
    {
        a[i]=arr[beg+i];
    }
    for(j=0;j<n2;j++)
    {
        b[j]=arr[mid+1+j];
    }
    i=0,j=0,k=beg;
    while(i<n1 && j<n2)
    {
        if(a[i]<=b[j])
        {
            arr[k++]=a[i++];
        }
        else{
            arr[k++]=b[j++];
        }
    }
    while(i<n1)
    arr[k++]=a[i++];
    while(j<n2)
    arr[k++]=b[j++];
}
void merge(int arr[],int low,int high)
{
    if(low<high)
    {
        int mid=(low+high)/2;
        merge(arr,low,mid);
        merge(arr,mid+1,high);
        mergesort(arr,low,mid,high);
    }
}
int main()
{
    int arr[]={9,3,6,2,88,55,99,66};
    merge(arr,0,8);
    for(int i=0;i<8;i++)
    {
        cout<<arr[i]<<" ";
    }
}