#include <iostream>
#include <stdio.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

/*
template using orderedSet =
    tree<T, null_type, less, rb_tree_tag, tree_order_statistics_node_update>;

*/

typedef tree<int, null_type, less<int>, rb_tree_tag,
        tree_order_statistics_node_update> orderedSet;


int main(){

    orderedSet os;
    /*
    os.insert(5);
    os.insert(2);
    os.insert(6);
    os.insert(4);
    os.insert(2);
    os.insert(7);

    cout << *os.find_by_order(0)<<endl; // 2
    cout << *os.find_by_order(1)<<endl; // 4
    cout << *os.find_by_order(2)<<endl; // 5
    cout << *os.find_by_order(3)<<endl; // 6
    cout << *os.find_by_order(4)<<endl; // 7

    cout << os.order_of_key(5) << endl;  // 2
    cout << os.order_of_key(2) << endl;  // 0
    cout << os.order_of_key(6) << endl;  // 3
    cout << os.order_of_key(4) << endl;  // 1
    cout << os.order_of_key(7) << endl;  // 4

    */
    // 1521. War games 2 (TIMUS)
    orderedSet::iterator it;
    int n,k;
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        os.insert(i);

    int cur = 0;

    while(n)
    {
        cur = (cur + k - 1) % n;
        it = os.find_by_order(cur);
        cout << *it << endl;
        os.erase(it);
        n--;
    }

    return 0;
}
