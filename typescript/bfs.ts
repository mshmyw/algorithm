/** 
 * 广度优先遍历
 * 借助队列
*/
const bfsTra = (numList: number[], targetValue: number) => {
  const len = numList.length;
  const queue = [numList[0]];
  for(let i = 0; queue.length; ) {   
    const headerValue = queue.shift();
    if(headerValue === targetValue) {
      console.log(`success: ${targetValue}, i=${i} queue is ${queue}`);
      break;
    }
    const leftChildIndex = 2*i + 1;
    if(leftChildIndex < len) {
      // 有左孩子
      queue.push(numList[leftChildIndex]);
    }
    const rightChildIndex = 2*i + 2;
    if (rightChildIndex < len) {
      // 有右孩子
      queue.push(numList[rightChildIndex]);
    }
    i++;
  }
}

/** 
 * 测试 （以完全二叉树为例，因为完全二叉树可轻易通过数组表示，测试简单）
 *           -3
 *       1         2
 *   2      3   5     7
 * 8  15 21
*/
const testData = [-3, 1, 2, 2, 3, 5, 7, 8, 15, 21];
const targetList = [3, 5, 10, 21, -3, 25];
for (const item of targetList) {
  bfsTra(testData, item);
}