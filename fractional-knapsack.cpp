#include <iostream>
#include <algorithm>
using namespace std;

struct Item {
    int weight;
    int value;
    double ratio;
};

bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int n, capacity;

    cout << "Enter number of items: ";
    cin >> n;

    Item items[n];

    cout << "Enter weight and value of each item:\n";

    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].value;

        items[i].ratio =
            (double)items[i].value / items[i].weight;
    }

    cout << "Enter capacity of knapsack: ";
    cin >> capacity;

    // Sort items according to value/weight ratio
    sort(items, items + n, compare);

    double totalValue = 0;

    for (int i = 0; i < n; i++) {

        if (capacity >= items[i].weight) {
            // Take the complete item
            capacity -= items[i].weight;
            totalValue += items[i].value;
        }
        else {
            // Take only the required fraction
            totalValue += items[i].ratio * capacity;
            capacity = 0;
            break;
        }
    }

    cout << "Maximum value = " << totalValue << endl;

    return 0;
}
