/**
 * 二分法查找
 * 注意：对于取中间数的公式：midIndex = leftIndex + Math.floor((rightIndex - leftIndex) / 2);
 * 可能存在 leftIndex === midIndex
 * 因为位置index 都是整数，取余之后会导致该问题
 * 例如 index [8, 9] mid  = 8 + Math.floor((9 - 8) / 2) = 8
 * 故 在二分查找过程中 需要对范围做特殊区间处理（排除mid元素）
 * 否则 可能存在死循环！
 * @param numList
 */
const _binSearch = (
  numList: number[],
  leftIndex: number,
  rightIndex: number,
  targetValue: number
) => {
  if (leftIndex > rightIndex) {
    console.error('finally failed for ', targetValue);
    return;
  }
  const midIndex = leftIndex + Math.floor((rightIndex - leftIndex) / 2);
  if (numList[midIndex] === targetValue) {
    // 找到
    console.log(`search ${targetValue} success, position at: ${midIndex}`);
    return;
  }

  if (targetValue < numList[leftIndex] || numList[rightIndex] < targetValue) {
    // 超出区间，失败
    console.log('failed for ', targetValue, leftIndex, midIndex, rightIndex);
    return;
  }

  if (targetValue < numList[midIndex]) {
    // 1 在左侧区间(必须排除mid,这是由于mid公式决定，否则死循环可能)
    _binSearch(numList, leftIndex, midIndex - 1, targetValue);
    return;
  }
  if (numList[midIndex] < targetValue) {
    // 2 在右侧区间
    _binSearch(numList, midIndex + 1, rightIndex, targetValue);
    return;
  }
};

const binSearch = (numList: number[], targetValue: number) => {
  _binSearch(numList, 0, numList.length - 1, targetValue);
};

// 测试
const testData = [-3, 1, 2, 2, 3, 5, 7, 8, 15, 21]; // 有序序列
const targetList = [3, 5, 10, 21, -3, 25];
for (const item of targetList) {
  binSearch(testData, item);
}
