#include <iostream>


//сортировка выборкой

template<class T>
void swap(T& a, T& b)
{
    T t = a;
    a = b;
    b = t;
}

template<class T>
void selectionSort(T a[], int n, int (*cmp)(T, T))
{
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if ((*cmp)(a[j], a[min]) < 0) {
                min = j;
            }
        }
        swap(a[i], a[min]);
    }
}


int compareInt(int a, int b) {
    return a - b;
}

//int main() {
//    int arr[] = { 64, 25, 12, 22, 11 };
//    int n = sizeof(arr) / sizeof(arr[0]);
//
//    selectionSort(arr, n, compareInt);
//
//    std::cout << "Sorted array: ";
//    for (int i = 0; i < n; i++) {
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//
//    return 0;
//}