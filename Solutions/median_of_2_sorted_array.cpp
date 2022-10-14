#include <bits/stdc++.h>
using namespace std;
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    long n = A.size(), m = B.size(), t=(n+m+1)/2;
    if(n>m)return findMedianSortedArrays(B,A);
    if(n==0) return m % 2 == 0 ? (double)(B[m/2 - 1] + B[m/2]) / 2 : B[m/2];
    if(m==0) return n % 2 == 0 ? (double)(A[n/2 - 1] + A[n/2]) / 2 : A[n/2];
    long left = 0, right = n;
    while (left <= right) {
        long partitionA = left + (right-left)/2;
        long partitionB = t - double(partitionA);      // partitionA + partitionB = (n+m+1)/2
        //if partitionA is 0 then take INT_MIN for maxLeftA (nothing is left in the left of partition)
        double maxLeftA = INT_MIN;
        if(partitionA > 0){
            maxLeftA = A[partitionA-1];
        }
            
        //if partitionA is n then take INT_MAX for minRightA (nothing is left in the right of partition)
        double minRightA = INT_MAX;
        if(partitionA < n){
            minRightA = A[partitionA];
        }
        
        //Similarly for maxLeftB and minrightB
        double maxLeftB = INT_MIN;
        if(partitionB > 0){
            maxLeftB = B[partitionB-1];
        }
            
        double minRightB = INT_MAX;
        if(partitionB < m){
            minRightB = B[partitionB];
        }
        if (maxLeftA <= minRightB && maxLeftB <= minRightA) {     // check weather it's a perfect partition or not
            if ((n+m) % 2 == 0) {                                // if the sorted merged array is of even length
                return (max(maxLeftA, maxLeftB) + min(minRightA, minRightB))/2.0;
            } 
            else {
                return max(maxLeftA, maxLeftB);
            }
        } 
        else if (maxLeftA > minRightB) {                          //move left side.
            right = partitionA - 1;
        }
        else {                                                   // move right side
            left = partitionA + 1;
        }
    }
    return 0.0;    // we can't find the median if input is invalid i.e., arrays are not sorted
}
    
    
int main() {
  vector<int> A = {1, 2, 3, 5, 6};
  vector<int> B = {4};
  cout<<findMedianSortedArrays(A, B);
  return 0;
}
