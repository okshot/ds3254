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
int selection_sort(const char* fname,int sz){
        ifstream fp(fname);
        int x[10000];
        int num;
        int i=0;
        while (fp>>num){
            x[i] = num;
            i++;
        }
        auto start = high_resolution_clock::now();
        for(int k=0;k<sz;k++){
            int min = get_min(x,k,sz-1);
            swap(x,k,min);
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
        time[k-1] = selection_sort(filename.c_str(),10000);
    }
    print_array(time,100);
    return 0;
}