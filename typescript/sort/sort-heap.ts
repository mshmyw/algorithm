/**
 * 堆排序
 * 1 建堆
 * 2 反复调整
 * (i 树高 1, 2, ...)
 *     i
 *   /  \
 *  2i  2i+1
 */
const swap = (numList: number[], left: number, right: number) {
  const temp = numList[left];
  numList[left] = numList[right];
  numList[right] = temp;
  return numList;
}
const _createHeap = (numList: number[], rootIndex: number, len: number) => {    
    // 调整当前树
    const leftChildIndex = 2 * rootIndex + 1;
    const rightChildIndex = 2 * rootIndex + 2;
    // 先假定最小的孩子节点为index
    let index = rootIndex;
    // 没有孩子
    if(leftChildIndex > len - 1) {
      return;
    }
    // 仅有左孩子
    if(leftChildIndex < len && rightChildIndex > len - 1) {
      index = leftChildIndex;      
    }
    
    // 左右孩子都有
    if(leftChildIndex < len && rightChildIndex < len) {
      index = numList[leftChildIndex] < numList[rightChildIndex]
      ? leftChildIndex
      : rightChildIndex;
    }
    if(numList[index] < numList[rootIndex]) {
      // 找到最小的孩子，与根交换
      swap(numList, index, rootIndex);
      // 该孩子所在子树已被破坏，需接着调整该孩子所在子树
      _createHeap(numList, index, len);
    }
}

const sortHeap = (numList: number[]) => {
  // 1 建堆（自底而上）
  for(let i = numList.length/2-1; i >=0; i--) {
    _createHeap(numList, i, numList.length);
  }
  // 2 堆排序
  for(let i = numList.length - 1; i >=0; i--) {
    // 首尾交换
    swap(numList, i, 0);
    // 调整
    _createHeap(numList, 0, i);
  }
};

const testData = [1, 3, 7, 2, 5, 8];
sortHeap(testData);
// 1 2 7 3 5 8
console.log('res ', testData);
/** 
 *       1 
 *    3    7
 *  2  5 8 
*/