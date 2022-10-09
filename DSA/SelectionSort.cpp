//Selection Sort
#include <iostream>
using namespace std;

int main() {
    int n,temp,pos,i,j,small;
    cout<<"How many values you want to read: ";
    cin>>n;
    cout<<"\nRead the values";
    int list[n];
    for( i=0; i<n; i++)
      cin>>list[i];
     for(i=0;i<n;i++)
     {
        small=list[i];
        pos=i;
        for(j=i+1;j<n; j++)
        {
            if(small>list[j])
            {
                small=list[j];
                pos=j;
            }
        }
        temp = list[i];
        list[i] = list[pos];
        list[pos] = temp;
     }
    for(i=0;i<n;i++)
     cout<<list[i]<<" ";
    return 0;
}
