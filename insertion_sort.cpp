#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int insertion_sort(const char* fname, int n){
    ifstream fp(fname);
    int arr[10000];
    int num;
    int i=0;
    while (fp>>num){
        arr[i] = num;
        i++;
    }
    auto start = high_resolution_clock::now();
    for(int j=1;j<n;j++){
        int key = arr[j];
        int i = j-1;
        while (i >= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i = i-1;
        }
        arr[i+1] = key;
    }
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(end - start);
    fp.close();
    return duration.count();
}
void print_array(int *arr, int n){
    for(int i=0;i<n;i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
int main(){
    int time[100];
    for (int k = 1; k <= 100; k++){
        string filename = "generated_num/random_numbers_" + to_string(k) + ".txt";
        time[k-1] = insertion_sort(filename.c_str(),10000);
    }
    print_array(time,100);
    return 0;
}