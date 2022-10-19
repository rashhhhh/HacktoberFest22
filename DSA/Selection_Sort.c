#include<stdio.h>

void input(int *,int);
void selection_sort(int *,int);
void output(int *,int);

int main()
{
        int arr[20],n,i;
        printf("\nEnter the number of elements:");
        scanf("%d",&n);
        printf("\nEnter the elements:");
        input(arr,n);
        selection_sort(arr,n);
        printf("\nThe sorted array is:");
        output(arr,n);
        return(0);
}
void input(int arr[],int n)
{
        int i;
        for(i=0;i<n;i++)
                scanf("%d",&arr[i]);
}
void output(int arr[],int n)
{
        int i;
        for(i=0;i<n;i++)
                printf("%d\n",arr[i]);
}
void selection_sort(int arr[],int n)
{
        int i,j,a,t,loc=0;
        for(i=0;i<n && loc==0;i++)
        {
       		a=i;
		loc=1;
		for(j=i+1;j<n;j++)
		{
			if(arr[j]<arr[a])
			{
				a=j;
			}
		loc=0;
		}
		t=arr[a];
		arr[a]=arr[i];
		arr[i]=t;
		

	}
}
