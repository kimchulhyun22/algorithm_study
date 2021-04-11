/*
    백준 2143번 두 배열의 합
*/

#include <iostream>
#include <vector>
#include <algorithm>

bool BinarySearch(const std::vector<long long>& numbers, const long long& target) {
    long long left = 0;
    long long right = numbers.size();

    while(left <= right) {
        long long mid = (left + right) / 2;

        if(numbers[mid] == target) {
            return true;
        }

        if(numbers[mid] > target) {
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }

    return false;

}

std::vector<long long> CalculateCumlatedSum(const std::vector<long long>& numbers) {
    std::vector<long long> cumulated_vector;
    std::vector<long long> sum;

    long long vector_size = numbers.size();

    for(int i = 0; i < vector_size; i++) {
        long long sum = numbers[i];
        cumulated_vector.push_back(sum);

        for(int j = i + 1; j < vector_size; j++) {
            sum += numbers[j];
            cumulated_vector.push_back(sum);
    
        } 
    }
    sort(cumulated_vector.begin(), cumulated_vector.end());

    return cumulated_vector;
}

long long SumTwoArry(const std::vector<long long>& A, const std::vector<long long>& B, long long target) {
    long long count = 0;

    for(int i = 0; i < A.size(); i++) {
        long long search_number = target-A[i];
        long long upper = upper_bound(B.begin(), B.end(), search_number) - B.begin();
        long long lower = lower_bound(B.begin(), B.end(), search_number) - B.begin();

        count += (upper-lower);
    }

    return count;
}

int main() {
   int T;
   int n,m;

   std::vector<long long> A, B;

   std::cin >> T;

   std::cin >> n;

   for(int i = 0; i < n; i++) {
       long long input;
       std::cin >> input;

       A.push_back(input);
    } 

    std::cin >> m;
    
    for(int i = 0; i < m; i++) {
       long long input;
       std::cin >> input;

       B.push_back(input);
    } 
    
    std::vector<long long> cumulate_a = CalculateCumlatedSum(A);
    std::vector<long long> cumulate_b = CalculateCumlatedSum(B);

    std::cout << SumTwoArry(cumulate_a, cumulate_b, T) << '\n';
}