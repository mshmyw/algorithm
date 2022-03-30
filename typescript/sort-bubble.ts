/**
 * 冒泡排序(默认左侧为水面，右侧为池底)
 * 每次从最右侧开始，比较相邻两个元素，
 * 较小元素进行冒泡
*/

const sortBubble = (numList: number[]) => {
  for(let i = 0; i < numList.length; i++) {
    for(let j = numList.length - 1; j >= i; j--) {
      if(numList[j] <= numList[j-1]) {
        // 比较并交换
        const temp = numList[j];
        numList[j] = numList[j-1];
        numList[j-1] = temp;
      }
    }
  }
  return numList;  
}
const testData = [1, 3, 7, 2, 5, 0];
sortBubble(testData);
console.log("res ", testData);
