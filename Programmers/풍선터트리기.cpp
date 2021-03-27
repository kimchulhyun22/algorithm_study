#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int solution(vector<int> a) {
    int answer = 0;
    int size = a.size();
    
    vector<int> left_min(size);
    vector<int> right_min(size);
    
    int left_min_val = a[0];
    
    for(int i = 0; i < size; i++) {
        if(a[i] <= left_min_val) {
            left_min_val = a[i];
        }    
        left_min[i] = left_min_val;
    }
    
    int right_min_val = a[size-1];
    
    for(int i = size - 1; i >= 0; i--) {
        if(a[i] <= right_min_val) {
            right_min_val = a[i];
        }
        right_min[i] = right_min_val;
    }
    
    for(int i = 0; i < size; i++) {
        if(a[i] <= left_min[i] || a[i] <= right_min[i]) {
            answer++;
        }        
    }
    
    return answer;
}