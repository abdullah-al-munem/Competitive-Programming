#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;
int Hash [10005], sg [10005];
void getsg () // Get template for sg function
{
     memset (sg, 0, sizeof (sg));
     for (int i = 1; i <= 10000; i ++)
     {
         memset (Hash, 0, sizeof (Hash));
         for (int j = 1; j + j <i; j ++)
         Hash [sg [j] ^ sg [i-j]] ++;
         for (int j = 0; j <= 10000; j ++)
         if (! Hash [j])
         {
             sg [i] = j;
             break;
         }
     }
}
int main ()
{
     getsg ();
     int i, n, t, cas = 1;
     cin >> t;
     while (t--)
     {
         cin >> n;
         int ans = 0, data;
         for (i = 0; i <n; i ++)
         {
             cin >> data;
             ans ^= sg [data]; // General Nimes XOR
         }
         if (ans)
         printf ("Case% d: Alice\n", cas ++);
         else
         printf ("Case% d: Bob\n", cas ++);
     }
     return 0;
}
