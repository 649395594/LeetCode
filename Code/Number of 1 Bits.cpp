/*
	题目分析：计算一个数字的二进制数字有多少个1

	我的思路：某位数字为1表示奇数，所以先判断一个数字是否为奇数，然后再将这个数字除以2

	问题：如果这个数字是负数则不能使用，-1 >> 1依然是-1，这是右移运算的性质规定的。
	
	解决方案1：附属转成正数，比如-5和4的和是-1，所以-5的1的个数和4的1的个数的和已知。因此要求负数x的1的个数，只要算出
	-1-x的1的个数即可。

	解决方案2：先将n与1做与运算，判断n的最低位是不是1。然后将1左移一位，将n与2做与运算，判断次低位是不是1。
	如果整数是32位，这个操作需要32步。

	解决方案3：x & (x - 1)的本质是把最右边的1变为0.比如 1100 & (1100 -1) = 1100 & 1011 = 1000。因此能进行多少次
	这样的运算就有多少个1。
*/

// 我的解法，不适用于负数
int hammingWeight(uint32_t n) {
    int c = 0;
    while (n != 0) {
        if (n % 2 == 1) {
            ++c;
        }
        n = n >> 1;
    }
    return c;
}

// 更通用的解法
int numberof1(int n) {
    int c = 0;
    while (n != 0) {
        ++c;
        n &= n -1;
    }
    return c;
}