#include <iostream>
using namespace std;
int knapsack(int *weights, int *values, int n, int maxWeight)
{
	if(n==0||maxWeight==0){
        return 0;
    }
    if(weights[n-1]<=maxWeight){
        return max(values[n-1]+knapsack(weights,values,n-1,maxWeight-weights[n-1]),
                  knapsack(weights,values,n-1,maxWeight));
         }
    return knapsack(weights,values,n-1,maxWeight);
}
int main()
{
	int n;
	cin >> n;

	int *weights = new int[n];
	int *values = new int[n];

	for (int i = 0; i < n; i++)
	{
		cin >> weights[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> values[i];
	}

	int maxWeight;
	cin >> maxWeight;

	cout << knapsack(weights, values, n, maxWeight) << endl;

	delete[] weights;
	delete[] values;
}
