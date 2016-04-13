void sort_num_arr(int arr[], int lim)
{
	int temp;
	for (int i = 0; i < lim - 1; i++) {
		for (int j = i + 1; j < lim; j++) {
			if (arr[j] > arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
}
