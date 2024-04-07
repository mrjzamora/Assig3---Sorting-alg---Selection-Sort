#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        int pi = i + 1;

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> sizes = { 100, 1000, 10000, 100000 };
    for (int size : sizes) {
        std::vector<int> arr(size);
        
        std::generate(arr.begin(), arr.end(), std::rand);

        auto start = std::chrono::high_resolution_clock::now();
        quickSort(arr, 0, arr.size() - 1); 
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for " << size << " elements: "
            << duration.count() << " milliseconds" << std::endl;
    }
    return 0;
}
