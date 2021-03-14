#include <stdio.h>

int N, M;
int n[100001];
int m[100001];
int tmp[100001];


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


int binarySearch(int start, int end, int target)
{
		int mid;
		int result = -1;

		while (start <= end) {
				mid = (start + end) / 2;

				if (n[mid] == target)
						return 1;
				else if (n[mid] > target)
						end = mid - 1;
				else
						start = mid + 1;
		}

		return 0;
}


int main(void)
{
		int result = -1;

		freopen("input.txt", "r", stdin);

		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
				scanf("%d", &n[i]);
		}
		scanf("%d", &M);
		for (int i = 0; i < M; i++) {
				scanf("%d", &m[i]);
		}

		mergeSort(n, tmp, 0, N-1);

		for (int i = 0; i < M; i++) {
				result = binarySearch(0, N-1, m[i]);
				printf("%d\n", result);
		}

		return 0;
}
