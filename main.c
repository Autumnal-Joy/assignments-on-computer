/*
该函数输入为整型数组，a, b分别为待排数组的起始点和终点。
然后将data[a]作为枢轴元素。定义两个指针startptr和endptr，
指向待排数组的两端，并且向中间靠拢。当startptr遇到比枢轴元素大的数，
endptr遇到比枢轴元素小的数，则这两个数交换位置。直到两指针相遇为止，
然后将枢轴元素赋值给两指针相遇的位置，即枢轴元素在待排序列中的正确位置。
然后调用两次本函数，分别对枢轴元素左边和右边的待排数组进行同样的操作，
不断递归，直到只剩一个数待排序为止。
*/
void quick(int data[], int a, int b) {
    if (a == b)
        return;
    int key = data[a];
    int startptr = a;
    int endptr = b;
    int i, j, sum;
    while (startptr != endptr) {
        if (data[startptr] > key) {
            for (; startptr != endptr; endptr--) {
                if (data[endptr] < key) {
                    sum = data[startptr];
                    data[startptr] = data[endptr];
                    data[endptr] = sum;
                    break;
                }
            }
        }
        startptr++;
    }
    quick(data, a, startptr);
    quick(data, startptr, b);
    for (i = 0; i <= b; i++) {
        printf("%d ", data[i]);
    }
};

/*
该函数和快排函数基本一致，只对枢轴元素的选取作了调整。
不在直接将待排数组的第一个元素直接作为枢轴元素，而是从待排数组的第一个元素，
中间的元素和最后一个元素中选一个大小居中的元素作为枢轴元素。
然后将其和第一个元素交换位置，其余函数和快排函数一致。
*/
void threequick(int data[], int a, int b) {
    if (a == b)
        return;
    int key;  //枢轴
    if (data[(a + b) / 2] >= a && data[(a + b) / 2] <= b) {
        key = data[(a + b) / 2];
    } else if (data[(a + b) / 2] <= a && a <= b) {
        key = a;
    } else {
        key = b;
    }
    int startptr = a;
    int endptr = b;
    int i, j, sum;
    while (startptr != endptr) {
        if (data[startptr] > key) {
            for (; startptr != endptr; endptr--) {
                if (data[endptr] < key) {
                    sum = data[startptr];
                    data[startptr] = data[endptr];
                    data[endptr] = sum;
                    break;
                }
            }
        }
        startptr++;
    }
    quick(data, a, startptr);
    quick(data, startptr, b);
    for (i = 0; i <= b; i++) {
        printf("%d ", data[i]);
    }
};

/*
该函数输入为整型数组，待排数组的起点a和终点b。
然后进入循环，从待排数组的第二个元素开始扫描，若它大于或等于前一个元素，则继续扫描。
否则在前边找到该元素的插入点，移动数组，进行插入。然后继续扫描。扫描到终点后，该数组的插入排序也就完成了。
*/
void insert(int data[], int a, int b) {
    int i = 1;
    int j, k, sum;
    while (i <= b) {
        if (data[i] >= data[i - 1]) {
            i++;
        } else {
            for (j = 0; j < i; j++) {
                if (data[i] < data[j]) {
                    sum = data[i];
                    for (k = i; k != j; k--) {
                        data[k] = data[k - 1];
                    }
                    data[j] = sum;
                }
            }
            i++;
        }
    }
    for (i = 0; i <= b; i++) {
        printf("%d ", data[i]);
    }
}

int main() {}
