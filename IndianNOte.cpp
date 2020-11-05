
#include <iostream>
using namespace std;

int DiffWays(int note[], int sum, int n)
{

    // dp matrix is of dp[n+1][sum+1]

    int dp[n + 1][sum + 1];

    //Initialization
    for (int j = 0; j < n + 1; j++)
    {
        dp[j][0] = true;
    }

    for (int i = 1; i < sum + 1; i++)
    {
        dp[0][i] = false;
    }

    //Matrix filling with code after initialization

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < sum + 1; j++)
        {

            if (note[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - note[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{

    int note[] = {10, 20, 50, 100, 200, 500, 1000, 2000};
    int n = sizeof(note) / sizeof(int);
    int sum = 2000;

    int result = DiffWays(note, sum, n);

    cout << result;

    return 0;
}
