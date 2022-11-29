
#include <stdio.h>
#include <conio.h> // for getch()

/*
{100, 50, 200, 400, 20, 60, 10, 90, 300, 200}       Max Profit = 30900
{20, 30, 40, 10, 5, 80, 100, 60}                    Max Profit = 400
{20, 10, 5, 30, 60, 90, 40, 50}                     Max Profit = 105
{20, 5, 15, 35, 10, 50, 80, 40}                     Max Profit = 240
*/

int maximize_profit(int *prices, int size);

int main() {
    int prices[] = {100, 50, 200, 400, 20, 60, 10, 90, 300, 200};
    int size = sizeof(prices)/sizeof(prices[0]);
    int profit = maximize_profit(prices, size);

    printf ("Maximum Profit: %d TL\n", profit);
    getch(); // wait for a key press
    
    return 0;
}


int maximize_profit(int *prices, int size) {
    int i = 0, count = 0, profit = 0;
    while (i < size-1 && prices[i] >= prices[i+1])
        i++;
    if (i >= size-1)
        return 0;
    profit -= prices[i];
    printf("BUY  %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", 1, prices[i], i+1, profit);
    i++;
    while (i < size-1 && prices[i] <= prices[i+1])
        i++;
    if (i >= size-1) {
        profit += prices[size-1];
        printf("SELL %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", 1, prices[i], i+1, profit);
        return profit;
    }
    profit += prices[i];
    printf("SELL %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", 1, prices[i], i+1, profit);
    i++;

    while (1) {
        while (i < size-1 && prices[i] >= prices[i+1])
            i++;
        if (i >= size-1)
            break;
        count = profit/prices[i];
        profit -= count*prices[i];
        printf("BUY  %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", count, prices[i], i+1, profit);
        i++;
        while (i < size-1 && prices[i] <= prices[i+1])
            i++;
        if (i >= size-1) {
            profit += count*prices[size-1];
            printf("SELL %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", 1, prices[i], i+1, profit);
            break;
        }
        profit += count*prices[i];
        printf("SELL %3d at a price %4d TL on day %3d: Current profit = %6d TL\n", count, prices[i], i+1, profit);
        i++;
    }
    return profit;
}
