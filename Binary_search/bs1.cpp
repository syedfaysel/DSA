//Author:@syedrajo20
//

#include<bits/stdc++.h>
using namespace std;
#define nl "\n"
#define ll long long

int binarySearch(int arr[], int size, int key){
	int start = 0;
	int end = size-1;
	int mid = start + (end - size)/2;

	while(start <= end){
		if(arr[mid] == key){
			return mid;
		}

		if(key > arr[mid]){
			start = mid + 1;
		}
		else{
			end = mid - 1;
		}

		mid = start + (end - start)/2;
	}
	return -1;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(NULL);
	int arr[6] = { 10, 20, 30, 35, 50, 52};

	int ans = binarySearch(arr, 6, 30);
	cout << ans << nl;
	return 0;
}
