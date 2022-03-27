/*
 * 生成 n 个数的全排列
 * 方式：
 * 1 2 3
 * 1 2 3
 * 1 2 3
 * 1. 生成n^n 排列 2. 剪枝
 */

const fullSortInner = (start, count, result = []) => {
  if (start > count) {
    console.log('result ', result);
    return;
  }

  // 版本1 生成 n^n 排列
  // for(let i = 1; i < count+1; i++) {
  //   result.push(i);
  //   fullSortInner(start+1, count, result);
  //   result.pop(i);
  // }

  // 版本2 剪枝
  for (let i = 1; i < count + 1; i++) {
    if (result.includes(i)) {
      // 剪枝
      continue;
    }
    result.push(i);
    fullSortInner(start + 1, count, result);
    result.pop();
  }
};

const fullSort = (n) => {
  const startTime = new Date().getTime();
  const result = [];
  fullSortInner(1, n, result);
  const endTime = new Date().getTime();
  console.log('time: ', endTime - startTime);
};

const n = 6;
fullSort(n);
