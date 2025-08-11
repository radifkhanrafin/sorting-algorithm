#include <iostream>
using namespace std;

int knapsack(int N, int W, int profit[], int weight[])
{
    int maxProfitTable[N + 1][W + 1];

    for (int i = 0; i <= N; i++)
    {
        for (int w = 0; w <= W; w++)
        {
            if (i == 0 || w == 0)
                maxProfitTable[i][w] = 0;
            else if (weight[i - 1] <= w)
            {  
                maxProfitTable[i][w] = max(profit[i - 1] + maxProfitTable[i - 1][w - weight[i - 1]], maxProfitTable[i - 1][w]);
            }
            else
            { 
                maxProfitTable[i][w] = maxProfitTable[i - 1][w];
            }
        }
    }
    return maxProfitTable[N][W];
}

int main()
{
    int N = 3;
    int W = 4;
    int profit[] = {1, 2, 3};
    int weight[] = {4, 5, 1};

    int maxProfit = knapsack(N, W, profit, weight);
    cout << "Maximum Profit: " << maxProfit << endl;

    return 0;
}
