#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Job
{
    string id;
    int deadline;
    int profit;
};

// Sort jobs in decreasing order of profit
bool compare(Job a, Job b)
{
    return a.profit > b.profit;
}

int main()
{
    int n;

    cout << "Enter number of jobs: ";
    cin >> n;

    Job jobs[n];

    cout << "Enter job id, deadline and profit:\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Enter job " << i + 1 << ": ";

        cin >> jobs[i].id
            >> jobs[i].deadline
            >> jobs[i].profit;
    }

    // Sort jobs according to decreasing profit
    sort(jobs, jobs + n, compare);

    // Find maximum deadline
    int maxDeadline = 0;

    for (int i = 0; i < n; i++)
    {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    // Create time slots
    string slot[maxDeadline + 1];

    for (int i = 0; i <= maxDeadline; i++)
        slot[i] = "-";

    int totalProfit = 0;

    // Schedule jobs
    for (int i = 0; i < n; i++)
    {
        // Find the latest available slot
        for (int j = jobs[i].deadline; j >= 1; j--)
        {
            if (slot[j] == "-")
            {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    // Display job sequence
    cout << "\nJob Sequence: ";

    for (int i = 1; i <= maxDeadline; i++)
    {
        if (slot[i] != "-")
            cout << slot[i] << " ";
    }

    cout << "\nMaximum Profit = " << totalProfit << endl;

    return 0;
}
