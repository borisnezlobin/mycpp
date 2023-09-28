#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
        void insert(int key){
            heap[size] = key;
            size++;
            int index = size - 1;
            while(index > 0 && heap[index] > heap[(index - 1) / 2]){
                swap(heap[index], heap[(index - 1) / 2]);
                index = (index - 1) / 2;
            }
        }
        int deleteMax(){
            if(size == 0){
                return -1;
            }
            int max = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapify(0);
            return max;
        }
        void print(){
            for (int i = 0; i < size; i++)
            {
                cout << heap[i] << " ";
            }
            cout << "\n";
        }
    private:
        int heap[1000000];
        int size = 0;
        void swap(int &a, int &b){
            int temp = a;
            a = b;
            b = temp;
        }
        void heapify(int index){
            int left = index * 2 + 1;
            int right = index * 2 + 2;
            int largest = index;
            if(left < size && heap[left] > heap[largest]){
                largest = left;
            }
            if(right < size && heap[right] > heap[largest]){
                largest = right;
            }
            if(largest != index){
                swap(heap[index], heap[largest]);
                heapify(largest);
            }
        }
};