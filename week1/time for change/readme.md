Here I implemented a program that calculates the minimum number of coins required to give a user change.

It uses the "greedy algorithm - that always takes the best immediate, or local, solution while finding an answer. Greedy algorithms find the overall, or globally, optimal solution for some optimization problems, but may find less-than-optimal solutions for some instances of other problems."

For example: suppose that a cashier owes a customer some change and on that cashier’s belt are levers that dispense quarters, dimes, nickels, and pennies.

If some customer is owed 41¢, the biggest first (i.e., best immediate, or local) bite that can be taken is 25¢. (That bite is "best" inasmuch as it gets us closer to 0¢ faster than any other coin would.) Note that a bite of this size would whittle what was a 41¢ problem down to a 16¢ problem, since 41 - 25 = 16. That is, the remainder is a similar but smaller problem. Needless to say, another 25¢ bite would be too big (assuming the cashier prefers not to lose money), and so our greedy cashier would move on to a bite of size 10¢, leaving him or her with a 6¢ problem. At that point, greed calls for one 5¢ bite followed by one 1¢ bite, at which point the problem is solved. The customer receives one quarter, one dime, one nickel, and one penny: four coins in total.

$ ./greedy
O hai! How much change is owed?
0.41
4

Why 4? Because we need to return 1 quarter, then 1 dime, then 1 nickel and lastly, 1 penny. 

