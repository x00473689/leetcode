/*剑指 Offer 66
构建乘积数组给定一个数组 A[0,1,…,n-1]，请构建一个数组 B[0,1,…,n-1]，
其中 B 中的元素 B[i]=A[0]×A[1]×…×A[i-1]×A[i+1]×…×A[n-1]。不能使用除法。
*/
 
int* constructArr(int* a, int aSize, int* returnSize){
    if (a == NULL || aSize <= 0) {
        *returnSize = 0;
        return a;
    }
    int *res = (int *)malloc(sizeof(int) * aSize);
    memset(res, 0, sizeof(int) * aSize);
    int i;
    res[0] = 1;
    int j = 0;
    for(i = 1; i < aSize; i++)
    {
        res[i] = res[i - 1] * a[i - 1];
    }
    int tmp = 1;
    for (j = aSize - 2; j >= 0; j--) {
        tmp = tmp * a[j + 1];
        res[j] = res[j] * tmp;
    }
    *returnSize = aSize;
    return res;
}
