void invertSort(int* array, int n) {
	//当n-1是最后一个排序的末尾时,不需要再进行排序
	for (int i = 0; i < n - 1; i++) {
		
		//新数据插入 
		//end是有序数列的最后一个位置
		int end = array[i];
		//key是待插入的数据
		int key = array[end + 1];
		while (end >= 0 && array[end] > key) {
			//当前数据后移
			array[end + 1] = array[end];
			end--;
		}
		//将待插入的数据插入
		array[end] = key;
	}
}