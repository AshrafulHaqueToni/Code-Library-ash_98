https://www.geeksforgeeks.org/sum-xor-possible-subsets/

Take a OR of all arr[] elements, we get 
= 1 | 5 | 6
= 001 | 101 | 110
= 111

Now to find final summation, we can write it down as:-
= 1*2n-1+2 + 1*2n-1+1 + 1*2n-1+0
= 2n-1 * (1*22 + 1*21 + 1*20 )
= 2n-1 * (1112)
= 2n-1 * 7

Put n = 3,  we get
= 28

int xorSum(int arr[], int n) 
{ 
    int bits = 0; 
  
    // Finding bitwise OR of all elements 
    for (int i=0; i < n; ++i) 
        bits |= arr[i]; 
  
    int ans = bits * pow(2, n-1); 
  
    return ans; 
}