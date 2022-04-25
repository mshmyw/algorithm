/**
 * 二分搜索
 */

const innerBinSearch = (numList: number[], left: number, right: number, target: number) => {
  if(left > right) {
    console.log('failed ', left, right, target);
    return;
  }
  const mid = left + Math.floor((right - left)/2);
  if(numList[mid] === target) {
    console.log('success ', left, right, target);
    return;
  } else if (target < numList[mid]) {
    innerBinSearch(numList, left, mid - 1, target);
  } else if(numList[mid] < target) {
    innerBinSearch(numList, mid + 1, right, target);
  }

  return;
}

const binSearch = (numList: number[], target: number) => {
  innerBinSearch(numList, 0, numList.length - 1, target);
}

const targetList = [1, 3, 5, 6];
const testData = [1, 5, 7, 8, 12, 23, 30, 32, 45];
for(const item of targetList) {
  binSearch(testData, item);
}