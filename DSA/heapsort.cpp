#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i){
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;
    if(left <= n && arr[left] > arr[largest]){
        largest = left;
    }
    if(right <= n && arr[right] > arr[largest]){
        largest = right;
    }

    if(largest != i){
        swap(arr[i],arr[largest]);
        heapify(arr, n, largest);
    }
    return;
}

void buildHeap(int arr[], int n){
    for(int i = n/2; i >=1 ; i--){
        int node = i;
        heapify(arr, n , i);
    }
    return;
}

int popHeap(int arr[] , int n){
    swap(arr[1],arr[n]);
    heapify(arr,n-1,1);
    return arr[n];
}

void heapSort(int arr[], int n){
    buildHeap(arr,n);
    for(int i = n; i > 1; i--){
        swap(arr[i],arr[1]);
        heapify(arr,i-1,1);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    int arr[n+1];
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
    }
    // heapSort(arr,n);
    // for(int i = 1; i <= n; i++){
    //     cout << arr[i] << " ";
    // }
    buildHeap(arr,n);
    int x = popHeap(arr,n);
    for(int i = 1; i <= n-1; i++){
        cout << arr[i] << " ";
    }
    cout << x << "\n";
}