/**
 * 深度优先遍历
 * 递归
 */

// 数组形式
const _dfsTraverse = (numList: number[], rootIndex: number, targetValue: number) => {
  const len = numList.length;
  if (rootIndex > len - 1) {
    console.log('leaf node : ', rootIndex, targetValue);
    return;
  }
  if (numList[rootIndex] === targetValue) {
    console.log('find target in ', rootIndex, targetValue);
    return;
  }

  // 始终从左孩子开始
  const leftChildIndex = 2 * rootIndex + 1;
  _dfsTraverse(numList, leftChildIndex, targetValue);
  // 右孩子
  const rightChildIndex = 2 * rootIndex + 2;
  _dfsTraverse(numList, rightChildIndex, targetValue);
};

const dfsTraverse = (numList: number[], targetValue: number) => {
  _dfsTraverse(numList, 0, targetValue);
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
  dfsTraverse(testData, item);
}