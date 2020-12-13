#include <stdio.h>

/*
该函数输入为整型数组，待排数组的起点a和终点b(左闭右开区间)。
然后进入循环，从待排数组的第二个元素开始扫描，若它大于或等于前一个元素，则继续扫描。
否则在前边找到该元素的插入点，移动数组，进行插入。然后继续扫描。扫描到终点后，该数组的插入排序也就完成了。
*/
void insert(int data[], int a, int b) {
    int j, sum;
    for (int i = a + 1; i < b; i++) {
        sum = data[i];
        for (j = i; j > a && data[j - 1] >= sum; j--) {
            data[j] = data[j - 1];
        }
        data[j] = sum;
    }
}

/*
该函数输入为整型数组，a, b分别为待排数组的起始点和终点(左闭右开区间)。
然后将data[a]作为枢轴元素。定义两个指针start和end，
指向待排数组的两端，并且向中间靠拢。当start遇到比枢轴元素大的数，
end遇到比枢轴元素小的数，则这两个数交换位置。直到两指针相遇为止，
然后将枢轴元素赋值给两指针相遇的位置，即枢轴元素在待排序列中的正确位置。
然后调用两次本函数，分别对枢轴元素左边和右边的待排数组进行同样的操作，
不断递归，当待排子序列长度已小于20时进行插入排序。
*/
void quick(int data[], int a, int b) {
    if (b - a < 20) {
        insert(data, a, b);
        return;
    }
    int key = data[a];
    int start = a;
    int end = b - 1;
    while (start < end) {
        while (start < end && data[end] >= key) {
            --end;
        }
        if (start < end) {
            data[start] = data[end];
        }
        while (start < end && data[start] <= key) {
            ++start;
        }
        if (start < end) {
            data[end] = data[start];
        }
    }
    data[start] = key;
    quick(data, a, start);
    quick(data, start + 1, b);
}

/*
该函数和快排函数基本一致，只对枢轴元素的选取作了调整。
不在直接将待排数组的第一个元素直接作为枢轴元素，而是从待排数组的第一个元素，
中间的元素和最后一个元素中选一个大小居中的元素作为枢轴元素。
然后将其和第一个元素交换位置，其余函数和快排函数一致。
*/
void threequick(int data[], int a, int b) {
    if (b - a < 20) {
        insert(data, a, b);
        return;
    }
    int key;  //枢轴
    int start = a;
    int end = b - 1;
    if ((data[(start + end) / 2] >= data[start] &&
         data[(start + end) / 2] <= data[end]) ||
        (data[(start + end) / 2] <= data[start] &&
         data[(start + end) / 2] >= data[end])) {
        key = data[(start + end) / 2];
        data[(start + end) / 2] = data[start];
    } else if ((data[(start + end) / 2] <= data[start] &&
                data[start] <= data[end]) ||
               (data[(start + end) / 2] >= data[start] &&
                data[start] >= data[end])) {
        key = data[start];
    } else {
        key = data[end];
        data[end] = data[start];
    }
    while (start < end) {
        while (start < end && data[end] >= key) {
            --end;
        }
        if (start < end) {
            data[start] = data[end];
        }
        while (start < end && data[start] <= key) {
            ++start;
        }
        if (start < end) {
            data[end] = data[start];
        }
    }
    data[start] = key;
    quick(data, a, start);
    quick(data, start + 1, b);
}