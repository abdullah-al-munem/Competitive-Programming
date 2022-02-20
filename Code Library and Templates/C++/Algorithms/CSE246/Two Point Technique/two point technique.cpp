#include <bits/stdc++.h>
using namespace std;

int n,limit;
int ara[100005];

int sizeOfLargestRange(){
	int mx=0,l=0, r=0;
	int sum=0;
	while(r<n){
		sum+=ara[r];
		while(sum>limit){
			sum-=ara[l];
			l++;
		}
		if((r-l+1)>mx) mx=r-l+1;
		r++;
	}
	return mx;
}

int main(){
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		scanf("%d", &ara[i]);
	}
	scanf("%d", &limit);
	printf("%d\n",sizeOfLargestRange());
	return 0;
}

