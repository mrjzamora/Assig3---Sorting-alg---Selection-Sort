#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>

// Selection Sort algorithm
void selectionSort(std::vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        std::swap(arr[min_idx], arr[i]);
    }
}

// Main function with the chronos library to be able to measure the time and output results
int main() {
    std::vector<int> sizes = { 100, 1000, 10000, 100000 };
    for (int size : sizes) {
        std::vector<int> arr(size);
        // Using "rand" for random values
        std::generate(arr.begin(), arr.end(), std::rand);

        auto start = std::chrono::high_resolution_clock::now();
        selectionSort(arr); // Calling the Algorithing here to run what ever is on the array
        auto stop = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
        std::cout << "Time taken for " << size << " elements: "
            << duration.count() << " milliseconds" << std::endl;
    }
    return 0;
}