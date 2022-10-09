//Bubble Sort
#include <iostream>
using namespace std;

int main() {
    int n,temp, flag=0,i,j;
    cout<<"How many values you want to read: ";
    cin>>n;
    int list[n];
     for( i=0; i<n; i++)
      cin>>list[i];
     i=0;
     while(i<n&&flag==0)
     {
         i++;flag=1;
         for(j=0; j<n; j++)
         {
             if(list[j]>list[j+1])
             {
                 temp = list[j];
                 list[j]=list[j+1];
                 list[j+1]=temp;
                 flag=0;
             }
         }
     }
     for(i=0;i<n;i++)
     cout<<list[i]<<" ";
    return 0;
}
