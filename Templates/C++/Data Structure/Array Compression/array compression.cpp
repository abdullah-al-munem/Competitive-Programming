#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
using namespace std;

void compress() {
  map < int, int > mymap;
  int input[] = {
    -102,
    1,
    134565589,
    134565589,
    -102,
    66666668,
    134565589,
    66666668,
    -102,
    1,
    -2
  };
  int assign = 0, compressed[100], c = 0, n = sizeof(input) / sizeof(int); //array size;
  for (int i = 0; i < n; i++) {
    int x = input[i];
    if (mymap.find(x) == mymap.end()) { //x not yet compressed
      mymap[x] = assign;
      printf("Mapping %d with %d\n", x, assign);
      assign++;
    }
    x = mymap[x];
    compressed[c++] = x;
  }
  printf("Compressed array: ");
  for (int i = 0; i < n; i++) printf("%d ", compressed[i]);
  puts("");
}

int main(){

    compress();

    ///string
    map < string, int > mymap;
    int edge, assign = 0;
    cin >> edge;
    for (int i = 0; i < edge; i++) {
        char s1[100], s2[100];
        cin >> s1 >> s2;
        if (mymap.find(s1) == mymap.end()) {
            printf("Mapping %s with %d\n", s1, assign);
            mymap[s1] = assign++;
        }
        if (mymap.find(s2) == mymap.end()) {
            printf("Mapping %s with %d\n", s2, assign);
            mymap[s2] = assign++;
        }
        int u = mymap[s1];
        int v = mymap[s2];
        cout << "Edge: " << u << " " << v << endl;
    }



    return 0;
}
