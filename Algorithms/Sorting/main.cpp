#include <iostream>

void quickSort(int arr[], int s, int e);
int Partition(int arr[], int s, int e);

int main()
{

    int n;
    std::cout << "Enter Size of Array: " << std::endl;
    std::cin >> n;
    int arr[n];
    std::cout << "Enter " << n << " elements in any order: " << std::endl;

    for(int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    for(int x : arr){std::cout << x << "\t";}

    std::cout << "\nRunning QuickSort" << std::endl;
    quickSort(arr, 0, n-1);

    for(int x : arr) {std::cout << x << "\t";}
    return 0;
}

int Partition(int arr[], int s, int e){
    int pivot = arr[e];
    int pIndex = s;

    for(int i = s; i < e; i++){
        if(arr[i] < pivot){
            int temp = arr[i];
            arr[i] = arr[pIndex];
            arr[pIndex] = temp;
            pIndex++;
        }
    }
    int temp = arr[e];
    arr[e] = arr[pIndex];
    arr[pIndex] = temp;
    return pIndex;
}

void quickSort(int arr[], int s, int e){
    if(s < e){  // When the recursion bottoms out
        int p = Partition(arr, s, e);
        quickSort(arr, s, (p - 1));
        quickSort(arr, (p + 1), e);
    }
}
