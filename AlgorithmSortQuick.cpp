#include "AlgorithmSortQuick.h"

AlgorithmSortQuick::AlgorithmSortQuick(int k):SelectionAlgorithm(k){
    // it will use base class' construction to assing k
}

int AlgorithmSortQuick::select(){

    int *arrSortQuick = 0;
    int size = 0;
    cin >> size;
    arrSortQuick = new int[size];

    for(int i = 0; i < size ; i++){
        cin >> arrSortQuick[i];
    }

    if(size <= 10){
        //Decreasing order Insertion sort
        int i = 0, j = 0, key = 0;
        for (j = 1; j < this->k; j++){
            key = arrSortQuick[j];
            for (i = j - 1; (i >= 0) && (arrSortQuick[i] < key); i--){
                arrSortQuick[i + 1] = arrSortQuick[i];
            }
            arrSortQuick[i + 1] = key; 
        }

        int result = arrSortQuick[this->k - 1];
        delete [] arrSortQuick;
        arrSortQuick = 0;
        return result;   
    }

    int result = 0;
    result = quickselect(arrSortQuick,0,size-1,k);
    delete[] arrSortQuick;
    arrSortQuick = 0;
    return result;
}

int AlgorithmSortQuick::quickselect(int *numbers, int left, int right, int k){
    if (k > 0 && k <= right - left + 1) {
        /*
        //median
		int center = (left + right) / 2;

		if (numbers[center] < numbers[left]){
	
            int temp = numbers[left];
            numbers[left] = numbers[center];
            numbers[center] = temp;
		}
		if (numbers[right] < numbers[left]){
	
            int temp = numbers[right];
            numbers[right] = numbers[left];
            numbers[left] = temp;
		}
		if (numbers[right] < numbers[center]){
		
            int temp = numbers[right];
            numbers[right] = numbers[center];
            numbers[center] = temp;
		}
		
        int temp = numbers[right -1];
        numbers[right-1] = numbers[center];
        numbers[center] = temp;

		int x = numbers[right-1];
*/
		
        //int x = numbers[(left+right)/2];

        int x = numbers[right];
        int i = left;

        //partition
		for (int j = left; j <= right - 1; j++) {
			if (numbers[j] <= x) {
                //swap
				int temp = numbers[i];
				numbers[i] = numbers[j];
				numbers[j] = temp;
				i++;
			}
		}
		int temp2 = numbers[i];
		numbers[i] = numbers[right];
		numbers[right] = temp2;

        int pIndex = i;
        int s1 = pIndex - left +1;

		if (s1 == k){
			return numbers[pIndex + 1];
        }
        if (s1 > k){
			return quickselect(numbers, left, pIndex - 1, k);
        }
		else{
			return quickselect(numbers, pIndex + 1, right, k - pIndex + left - 1);
        }
    } 
    return -1;
}


   /*
     if (left + 10 <= right) {	
		//median
		int center = (left + right) / 2;

		if (numbers[center] < numbers[left]){
	
            int temp = numbers[left];
            numbers[left] = numbers[center];
            numbers[center] = temp;
		}
		if (numbers[right] < numbers[left]){
	
            int temp = numbers[right];
            numbers[right] = numbers[left];
            numbers[left] = temp;
		}
		if (numbers[right] < numbers[center]){
		
            int temp = numbers[right];
            numbers[right] = numbers[center];
            numbers[center] = temp;
		}
		
        int temp = numbers[right -1];
        numbers[right-1] = numbers[center];
        numbers[center] = temp;

		int pivot = numbers[right-1];
        
		int i = left;
		int j = right;
		while (true){
			
			while (numbers[i] > pivot){
                i++;
            }
            
            while (pivot > numbers[j]){
                j--;
            }

			if (i < j){
                int temp = numbers[i];
                numbers[i] = numbers[j];
                numbers[j] = temp;
                i++;
                j--;
			}
			else{
				break;
			}
		}
        
        int temp2 = numbers[j];
        numbers[j] = numbers[left+1];
        numbers[left+1] = temp2;
		
		int pindex = j;
		int s1 = pindex - left + 1;


        if (k == s1) 
			return numbers[pindex +1];
		if (k <= s1)
			return quickselect(numbers, left, pindex - 1, k);
		//otherwise
		else
			return quickselect(numbers, pindex + 1, right, k - s1);
	    }
     else{
        //Decreasing order Insertion sort
        int i = 0, j = 0, key = 0;
        for (j = 1; j < this->k; j++){
            key = numbers[j];
            for (i = j - 1; (i >= 0) && (numbers[i] < key); i--){
                numbers[i + 1] = numbers[i];
            }
            numbers[i + 1] = key;

            return numbers[this->k - 1]; 
        }   */
