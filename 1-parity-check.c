# include <stdio.h>
# define bool int
/* Function to get parity of number n. It returns 1
if n has odd parity, and returns 0 if n has even
parity */
bool getParity(int n)
{
bool parity = 0;
while (n)
{
parity = !parity;
n = n & (n - 1);
} 
return parity;
}
void count1s0s(int N)
{
// Initialise count variables
int count0 = 0, count1 = 0;
// Iterate through all the bits
while (N > 0) {
// If current bit is 1
if (N & 1) {
count1++;
}
// If current bit is 0
else {
count0++;
}
N = N >> 1;
}
// Print the count
printf("Count of 0s in N is %d\n", count0);
printf("Count of 1s in N is %d\n", count1);
}
/* Driver program to test getParity() */
int main()
{
int n;
printf("Please enter number whose parity is to be checked - ");
scanf("%d", &n);
count1s0s(n);
printf("Parity of no %d = %s", n,
(getParity(n)? "odd": "even"));
getchar();
return 0;
}
