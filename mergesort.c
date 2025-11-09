#include <stdio.h>
void merge(int arr[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int left[n1];
    int right[n2];
    int i,j,k;
    for(int i=0;i<n1;i++)
    {
        left[i]=arr[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        right[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(left[i]<=right[j])
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        else
        {
            arr[k]=right[j];
            k++;
            j++;
        }
    }
        while(i<n1)
        {
            arr[k]=left[i];
            k++;
            i++;
        }
        while(j<n2)
        {
            arr[k]=right[j];
            k++;
            j++;
        }
    
}
void mergesort(int arr[],int l,int r)
{
    if(l>=r) return;
    int mid=(l+r)/2;
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);
    merge(arr,l,mid,r);
    
}
int main()
{
    int arr[]={2,3,4,6,4,7};
    int n=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
    mergesort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
