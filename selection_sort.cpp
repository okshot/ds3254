#include <iostream>
#include <fstream>
#include <chrono> 

using namespace std;
using namespace std::chrono;

int get_min(int *arr, int i, int j){
    int min = i;
    for(int k = i+1; k <= j; k++){
        if (arr[k] < arr[min]){
            min = k;
        }
    }
    return min;
}
void swap(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
void selection_sort(int *arr, int n){
    for(int k=0;k<n;k++){
        int min = get_min(arr,k,n-1);
        swap(arr,k,min);
    }
}
void print_array(int *arr, int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    ifstream fp("random_numbers_2.txt");
    int x[100000];
    int num;
    int i=0;
    while (fp>>num){
        x[i] = num;
        i++;
    }
    int sz = 100000;
    auto start = high_resolution_clock::now();
    selection_sort(x,sz);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    cout << "Time taken to sort: " << duration.count() << " milliseconds" << endl;
    fp.close();
    return 0;
}