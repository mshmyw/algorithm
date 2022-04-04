/**
 * 归并排序
 * 1 分割
 * 2 排序
 * 3 归并
 */
const _sortMerge = (
  numList: number[],
  leftIndex: number,
  rightIndex: number
) => {
  if (leftIndex >= rightIndex) {
    return;
  }
  // 1 分割
  const middleIndex = leftIndex + Math.floor((rightIndex - leftIndex) / 2);

  // 2  排序左
  _sortMerge(numList, leftIndex, middleIndex);
  // 3 排序右
  _sortMerge(numList, middleIndex + 1, rightIndex);
  // 4 归并左右
  const newNumList = [];
  let i = leftIndex,
    j = middleIndex + 1;
  for (; i <= middleIndex && j <= rightIndex; ) {
    if (numList[i] < numList[j]) {
      newNumList.push(numList[i]);
      i++;
    } else {
      newNumList.push(numList[j]);
      j++;
    }
  }
  for (; i <= middleIndex; i++) {
    newNumList.push(numList[i]);
  }
  for (; j <= rightIndex; j++) {
    newNumList.push(numList[j]);
  }
  for (i = leftIndex; i <= rightIndex; i++) {
    numList[i] = newNumList[i - leftIndex];
  }
};

const sortMerge = (numList: number[]) => {
  _sortMerge(numList, 0, numList.length - 1);
};

const testData = [5, 1, 3, 10, 7, 2, 15, 8, -1, 7];
sortMerge(testData);
console.log('res ', testData);
