
#include <bits/stdc++.h>
using namespace std;
vector<int> linearSearch(vector<vector<int>> arr, int target)
{
for (int i = 0; i < arr.size(); i++) {
	for (int j = 0; j < arr[i].size(); j++) {
	if (arr[i][j] == target) {
		return {i, j};
	}
	}
}
return {-1, -1};
}


int main()
{

vector<vector<int>> arr = { { 3, 12, 9 },
							{ 5, 2, 89 },
							{ 90, 45, 22 } };
int target = 89;
vector<int> ans = linearSearch(arr, target);
cout << "Element found at index: [" << ans[0] << "," <<ans[1] <<"]";

return 0;
}


