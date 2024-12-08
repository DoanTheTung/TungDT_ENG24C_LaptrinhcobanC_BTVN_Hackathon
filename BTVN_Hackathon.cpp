#include<stdio.h>
int main (){
	int arr[100];
	int size;
	int choice;
	int i,j;
	int rows;
	int cols;
	do{
		printf("\n\tMENU\n");
		printf("1. Nhap so luong va gia tri cho cac phan tu\n");
		printf("2. In mang (arr[0]=...,arr[1]=...)\n");
		printf("3. Dem so luong hoan hao\n");
		printf("4. Dem so luong nguyen to\n");
		printf("5. Tim gia tri lon thu 2 (khong sap xep)\n");
		printf("6. Tim gia tri nho thu 2 (khong sap xep)\n");
		printf("7. Them phan tu tai vi tri\n");
		printf("8. Xoa phan tu tai vi tri\n");
		printf("9. Sap xep mang tang dan (sap xep chen)\n");
		printf("10. Sap xep mang giam dan (sap xep chen)\n");
		printf("11. Tim kiem phan tu(Tim kiem nhi phan)\n");
		printf("12. Xoa phan tu trung lap va in phan tu doc nhat\n");
		printf("13. Sap xep va hien thi so chan dung truoc va so le dung sau\n");
		printf("14. Dao nguoc mang\n");
		printf("15. Thoat\n");
		printf("Lua chon cua ban la: ");
		scanf("%d", &choice);
		switch(choice){
			case 1 : //Nhap so luong va gia tri cho cac phan tu
			printf("Nhap so luong phan tu : ");
			scanf("%d",&size);
			if(size>100){
				printf("Kich thuoc mang vuot qua gioi han!");
				size=0;
			break;
			}
			for(int i=0;i<size;i++){
					printf("Phan tu thu %d la : ", i+1);
					scanf("%d", &arr[i]);
				}
			break;
			case 2 : //In mang (arr[0]=...,arr[1]=...)
			printf("Cac phan tu trong mang la:\n");
			for(int i=0; i<size;i++){
			printf("arr[%d]=%d\n",i,arr[i]);
			}
			break;
			case 3 : //Dem so luong so hoan hao
			{int count = 0;
                for (int i = 0; i < size; i++){
                    int sum = 0;
                    for (int j = 1; j <= arr[i] / 2; j++){
                        if (arr[i] % j == 0) sum += j;
                    }
                    if (sum == arr[i] && arr[i] > 1) count++;
                }
                printf("So luong so hoan hao: %d\n", count);	
			break;}
			case 4 : //Dem so luong so nguyen to
			{int count = 0;
                for (int i = 0; i < size; i++){
                    int isPrime = 1;
                    if (arr[i] < 2) isPrime = 0;
                    for (int j = 2; j * j <= arr[i]; j++){
                        if (arr[i] % j == 0){
                            isPrime = 0;
                            break;
                        }
                    }
                    if (isPrime) count++;
                }
            printf("So luong so nguyen to: %d\n", count);
			break;}
			case 5 : //Tim gia tri lon thu 2 (khong sap xep)
			{int max = -1e9, secondMax = -1e9;
                for (int i = 0; i < size; i++){
                    if (arr[i] > max){
                        secondMax = max;
                        max = arr[i];
                    } else if (arr[i] > secondMax && arr[i] != max){
                        secondMax = arr[i];
                    }
                }
                printf("Gia tri lon thu 2: %d\n", secondMax);	
			break;}
			case 6 : //Tim gia tri nho thu 2 (khong sap xep)
			{int min = 1e9, secondMin = 1e9;
                for (int i = 0; i < size; i++){
                    if (arr[i] < min){
                        secondMin = min;
                        min = arr[i];
                    } else if (arr[i] < secondMin && arr[i] != min){
                        secondMin = arr[i];
                    }
                }
                printf("Gia tri nho thu 2: %d\n", secondMin);
			break;}	
			case 7 : //Them phan tu tai vi tri
			{int pos, value;
                printf("Nhap vi tri can them: ");
                scanf("%d", &pos);
                printf("Nhap gia tri can them: ");
                scanf("%d", &value);
                if (pos < 0 || pos > size){
                    printf("Vi tri khong hop le!\n");
                }else{
                    for(int i = size; i > pos; i--){
                        arr[i] = arr[i - 1];
                    }
                    arr[pos] = value;
                    size++;
                }	
			break;}
			case 8 : //Xoa phan tu tai vi tri
			{int pos;
                printf("Nhap vi tri can xoa: ");
                scanf("%d", &pos);
                if (pos < 0 || pos >= size) {
                    printf("Vi tri khong hop le!\n");
                }else{
                    for (int i = pos; i < size - 1; i++){
                        arr[i] = arr[i + 1];
                    }
                    size--;
                }	
			break;}
			case 9 : //Sap xep mang tang dan
			{for(int i = 1; i < size; i++){
                    int key = arr[i];
                    int j = i - 1;
                    while(j >= 0 && arr[j] > key){
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep tang dan: ");
                for(int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");	
			break;}
			case 10 : //Sap xep mang giam dan
			{for(int i = 1; i < size; i++){
                    int key = arr[i];
                    int j = i - 1;
                    while (j >= 0 && arr[j] < key){
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                printf("Mang sau khi sap xep giam dan: ");
                for(int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");	
			break;}
			case 11 : //Tim kiem phan tu (tim kiem nhi phan)
			{printf("Tim kiem nhi phan\n");
                int target, left = 0, right = size - 1, mid;
                printf("Nhap gia tri can tim: ");
                scanf("%d", &target);
                for (int i = 1; i < size; i++){
                    int key = arr[i], j = i - 1;
                    while (j >= 0 && arr[j] > key){
                        arr[j + 1] = arr[j];
                        j--;
                    }
                    arr[j + 1] = key;
                }
                int found = 0;
                while (left <= right){
                    mid = (left + right) / 2;
                    if (arr[mid] == target){
                        printf("Tim thay %d o vi tri %d\n", target, mid);
                        found = 1;
                        break;
                    } else if (arr[mid] < target){
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) printf("Khong tim thay %d trong mang.\n", target);	
			break;}
			case 12 : //Xoa phan tu trung lap va in phan tu doc nhat
			{printf("Xoa phan tu trung lap va in phan tu doc nhat:\n");
                int unique[100], uniqueSize = 0;
                for (int i = 0; i < size; i++){
                    int isDuplicate = 0;
                    for (int j = 0; j < uniqueSize; j++){
                        if (arr[i] == unique[j]) {
                            isDuplicate = 1;
                            break;
                        }
                    }
                    if (!isDuplicate) {
                        unique[uniqueSize++] = arr[i];
                    }
                }
                size = uniqueSize;
                for (int i = 0; i < size; i++){
                    arr[i] = unique[i];
                }
                printf("Mang sau khi xoa phan tu trung lap: ");
                for (int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");	
			break;}
			case 13 : //Sap xep va hien thi so chan dung truoc va so le dung sau
			{printf("Sap xep so chan dung truoc so le dung sau:\n");
                int even[100], odd[100], evenCount = 0, oddCount = 0;
                for (int i = 0; i < size; i++){
                    if (arr[i] % 2 == 0) {
                        even[evenCount++] = arr[i];
                    } else {
                        odd[oddCount++] = arr[i];
                    }
                }
                for (int i = 0; i < evenCount; i++) arr[i] = even[i];
                for (int i = 0; i < oddCount; i++) arr[evenCount + i] = odd[i];

                printf("Mang sau khi sap xep: ");
                for (int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");
			break;}	
			case 14 : //Dao nguoc mang
			for (int i = 0; i < size / 2; i++){
                    int temp = arr[i];
                    arr[i] = arr[size - i - 1];
                    arr[size - i - 1] = temp;
                }
                printf("Mang sau khi dao nguoc: ");
                for (int i = 0; i < size; i++) printf("%d ", arr[i]);
                printf("\n");
			break;	
			case 15 : // thoat chuong trinh
				printf("Thoat chuong trinh");
				return 0;
				}
			}while(1);
		return 0;	
		}

