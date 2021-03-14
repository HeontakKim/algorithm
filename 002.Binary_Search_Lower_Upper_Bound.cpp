#include <stdio.h>

int N, M;
int tree[1000000];


long long int getSum(int tree[], int N, int H)
{
		int part;
		long long int sum = 0;

		for (int i = 0; i < N; i++) {
				part = tree[i] - H;
				part = (part > 0) ? part : 0;
				sum += part;
		}
		
		return sum;
}


int binarySearch(int start, int end, int M)
{
		int mid;
		long long int sum;
		int answer = -1;

		printf("max value : %d\n", end);

		while (start <= end) {
				mid = (start + end) / 2;
				printf("Current H : %d\n", mid);

				sum = getSum(tree, N, mid);
				printf("Sum : %lld\n", sum);

				if (sum == M)
						return mid;
				else if (sum < M)
						end = mid - 1;
				else {
						answer = mid;
						start = mid + 1;
				}
		}

		return answer;
}

int main(void)
{
		int max = -1;
		int result = -1;

		freopen("002.input.txt", "r", stdin);

		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
				scanf("%d", &tree[i]);
				if (tree[i] > max)
						max = tree[i];
		}

		result = binarySearch(0, max, M);
		printf("%d\n", result);

		return 0;
}

