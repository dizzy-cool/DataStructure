void invertSort(int* array, int n) {
	//��n-1�����һ�������ĩβʱ,����Ҫ�ٽ�������
	for (int i = 0; i < n - 1; i++) {
		
		//�����ݲ��� 
		//end���������е����һ��λ��
		int end = array[i];
		//key�Ǵ����������
		int key = array[end + 1];
		while (end >= 0 && array[end] > key) {
			//��ǰ���ݺ���
			array[end + 1] = array[end];
			end--;
		}
		//������������ݲ���
		array[end] = key;
	}
}