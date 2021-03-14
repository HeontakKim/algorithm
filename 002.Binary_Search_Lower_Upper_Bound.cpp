#include <stdio.h>

int N, M;
int height[1000010];
int tmp[1000010];


void mergeSort(int arr[], int tmp[], int start, int end)
{
	int mid = (start + end) / 2;
	int i, j, k;

	if (start >= end)
		return;

	mergeSort(arr, tmp, start, mid);
	mergeSort(arr, tmp, mid + 1, end);

	i = start;
	j = mid + 1;
	k = start;

	while (i <= mid && j <= end) {
		if (arr[i] < arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while (i <= mid)
		tmp[k++] = arr[i++];
	while (j <= end)
		tmp[k++] = arr[j++];

	for (i = start; i <= end; i++) {
		arr[i] = tmp[i];
	}
}


int binarySearch_LowerBound(int start, int end, int H)
{
	int mid;
	int sol = -1;

	while (start <= end) {
		mid = (start + end) / 2;

		if (height[mid] > H) {
			sol = mid;
			end = mid - 1;
		}
		else {
			start = mid + 1;
		}
	}

	return sol;
}

long long int getSum(int idx, int target_H)
{
	long long int sum = 0;

	for (int i = idx; i <= N; i++) {
		sum += (height[i] - target_H);
	}

	return sum;
}


int find_max_H(int start_H, int end_H)
{
	int target_H;
	int first_tree_idx;
	long long int partial_sum;
	int sol = -1;

	while (start_H <= end_H) {
		target_H = (start_H + end_H) / 2;
		first_tree_idx = binarySearch_LowerBound(1, N, target_H);
		partial_sum = getSum(first_tree_idx, target_H);

		if (partial_sum >= M) {
			sol = target_H;
			start_H = target_H + 1;
		}
		else {
			end_H = target_H - 1;
		}
	}

	return sol;
}


int main(void)
{
	int i;
	int max_H;

    freopen("002.input.txt", "r", stdin);

	scanf("%d %d", &N, &M);
	for (i = 1; i <= N; i++) {
		scanf("%d", &height[i]);
	}

	mergeSort(height, tmp, 1, N);
	max_H = find_max_H(0, height[N] - 1);
	printf("%d", max_H);

	return 0;
}
