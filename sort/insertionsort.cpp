#include <iostream>
using namespace std;

void printarray(int v[], int n){
    for(int i=0; i<n; i++){
        cout << v[i];
        cout << endl;
    }
}

void swap(int v[], int a, int b){
    int temp = v[a];
    v[a] = v[b];
    v[b] = temp;
}

void insertionsort(int v[], int n){
    for(int i=1; i<n; i++){
        int key = v[i];
        int k = i;
        while(k>0 && key < v[k-1]){
            v[k] = v[k-1];
            k--;
        }
        v[k] = key;
    }

}

int main(){
    int a[5] = {1234,25,435,52,66};
    insertionsort(a, 5);
    printarray(a, 5);
    return 0;
}
