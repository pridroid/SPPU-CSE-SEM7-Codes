#include<iostream>
#include<vector>

using namespace std;

//Iteratively using memoization
int iStepFibbonacci(int n){
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
    //[]
    int cnt = 2;
    for(int i = 2; i < n; i++){
        cnt++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return n;
}

int rSteps = 0;

//Recursively
int rStepFibbonacci(int n){
    rSteps++;
    if(n < 0) return 0;
    if(n == 1 || n == 0) return 1;
    return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
}

int main(){
    int n;
    cin >> n;
    cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';
    cout << "Steps required using Iteration : " << iStepFibbonacci(n) << '\n';
    cout << "Steps required using recursion : " << rSteps << '\n';
    return 0;
}

/*
Recursive fibbonacci:
Time Complexity: O(n*2n)
Auxiliary Space: O(n), For recursion call stack.

Iterative fibbonacci:
Time Complexity: O(n) 
Auxiliary Space: O(1)

Iterative Function with Memoization
cpp
Copy code
//Iteratively using memoization
int iStepFibbonacci(int n){
    vector<int> f;
    f.push_back(0);
    f.push_back(1);
int iStepFibbonacci(int n): Defines a function that calculates Fibonacci numbers iteratively. The input n represents the position in the Fibonacci sequence.
vector<int> f;: Declares a dynamic array (vector) f that will store computed Fibonacci values.
f.push_back(0); and f.push_back(1);: Initializes the first two Fibonacci numbers, 0 and 1, in the vector f.
cpp
Copy code
    int cnt = 2;
    for(int i = 2; i < n; i++){
        cnt++;
        f.push_back(f[i - 1] + f[i - 2]);
    }
    return n;
}
int cnt = 2;: Initializes a counter cnt to track the number of steps taken (starts from 2 because the first two numbers are already added).
for(int i = 2; i < n; i++): Iterates from the 2nd index up to n - 1 to calculate each Fibonacci number up to n.
cnt++: Increments the counter for each iteration.
f.push_back(f[i - 1] + f[i - 2]);: Adds the sum of the previous two values (to get the next Fibonacci number) to the vector f.
return n;: Returns the input n, but ideally, it should return cnt to provide the number of steps taken.
Recursive Function
cpp
Copy code
int rSteps = 0; // Global variable to count steps in the recursive function
int rSteps = 0;: Declares a global variable rSteps to count the number of steps (recursive calls) in the recursive Fibonacci function.
cpp
Copy code
int rStepFibbonacci(int n){
    rSteps++;
    if(n < 0) return 0;
    if(n == 1 || n == 0) return 1;
    return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);
}
int rStepFibbonacci(int n): Defines the recursive function for calculating Fibonacci. The input n is the position in the sequence.
rSteps++;: Increments rSteps to count the recursive call as a step.
if(n < 0) return 0;: Checks if n is negative; if so, it returns 0 (as Fibonacci numbers are typically defined for non-negative indices).
if(n == 1 || n == 0) return 1;: Returns 1 if n is 0 or 1, as the base cases of Fibonacci.
return rStepFibbonacci(n - 1) + rStepFibbonacci(n - 2);: Recursively calls the function with n - 1 and n - 2, adding these two values to get the Fibonacci number at position n.
Main Function
cpp
Copy code
int main(){
    int n;
    cin >> n;
int main(): The main function where the program starts.
int n;: Declares an integer n to store the position in the Fibonacci sequence input by the user.
cin >> n;: Reads an integer input from the user, representing the desired Fibonacci position.
cpp
Copy code
    cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';
    cout << "Steps required using Iteration : " << iStepFibbonacci(n) << '\n';
    cout << "Steps required using recursion : " << rSteps << '\n';
    return 0;
}
cout << "Fibbonacci Value : " << rStepFibbonacci(n) << '\n';: Calls the recursive function and outputs the Fibonacci number at position n.
cout << "Steps required using Iteration : " << iStepFibbonacci(n) << '\n';: Calls the iterative function and outputs the steps (inaccurate here as it returns n instead of cnt).
cout << "Steps required using recursion : " << rSteps << '\n';: Displays the number of steps taken in the recursive approach.
return 0;: Ends the program.
Complexity Analysis
Recursive Approach:
Time Complexity: 
𝑂
(
2
𝑛
)
O(2 
n
 ) as it makes repeated calls for each value.
Auxiliary Space: 
𝑂
(
𝑛
)
O(n) due to the recursive call stack.
Iterative Approach:
Time Complexity: 
𝑂
(
𝑛
)
O(n) as it iterates once up to n.
Auxiliary Space: 
𝑂
(
𝑛
)
O(n) for the vector, though this could be improved to 
𝑂
(
1
)
O(1) by keeping only the last two numbers.
Corrections
In the iterative function, return n; should ideally return cnt to provide the actual number of steps counted.








*/
