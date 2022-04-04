/**
 * 选择排序
 * 每次从剩余元素中选取最小值（冒泡是通过相邻比较）
 * 注意：选择排序必须在待排区间假定一个最小元素（比如最左侧的i）
 * (0~i i~n)
*/

const sortSelect = (numList: number[]) => {
  for(let i = 0; i < numList.length; i++) {
    let minItemIndex = i;
    for(let j = i; j < numList.length; j++) {
      if(numList[j] < numList[minItemIndex]) {
        // 更新最小元素
        minItemIndex = j;
      }
    }
    // 交换
    const temp = numList[i];
    numList[i] = numList[minItemIndex];
    numList[minItemIndex] = temp;
  }
  return numList;  
}
const testData = [1, 3, 7, 2, 5, 0];
sortSelect(testData);
console.log("res ", testData);
