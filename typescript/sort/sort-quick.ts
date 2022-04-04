const swap = (numList: number[], left: number, right: number) {
  const temp = numList[left];
  numList[left] = numList[right];
  numList[right] = temp;
  return numList;
}

/** 快排算法
 * 1 找基准元素
 * 2 划分集合（左侧集合小于基准， 右侧集合大于基准）
 * 3 左右侧分别快排
 */
const _sortQuick = (numList: number[], leftIndex: number, rightIndex: number) => {
  if(leftIndex >= rightIndex) {
    return;
  }
  let baseLineIndex = leftIndex;
  // 1 分成：左侧元素集合（小于参考元素）右侧元素集合（大于参考元素）
  // 注意：其实有两个不断变动指针，baseLineIndex 始终与其中一侧保持一致
  for(let i = leftIndex, j = rightIndex; i < j;) {
    if(baseLineIndex === i) {
      // baseLineIndex 在左
      if (numList[baseLineIndex] > numList[j]) {
        swap(numList, baseLineIndex, j);
        i++;
        baseLineIndex = j;
      } else {
        j--;
      }
    }
    if(baseLineIndex === j) {
      // baseLineIndex 在右
      if(numList[i] > numList[baseLineIndex]) {
        swap(numList, i, baseLineIndex);
        j--;
        baseLineIndex = i;
      }else {
        i++;
      }
    }
  }

  // 2 左侧快排
  _sortQuick(numList, 0, baseLineIndex - 1);
  // 3 右侧快排
  _sortQuick(numList, baseLineIndex + 1, rightIndex);
}

const sortQuick = (numList: number[]) => {
  _sortQuick(numList, 0, numList.length - 1);
}

const testData = [5, 1, 3, 10, 7, 2, 15, 8, -1, 7];
sortQuick(testData);
console.log('res ', testData);
