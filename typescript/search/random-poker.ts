/**
 * 洗牌算法
 * 1 分为有序和无序区间
 * 2 每次在无序区间随机选一个元素与无序区间第一个元素交换
 */

const shufflePoker = (numList: number[]) => {
  const len = numList.length;
  for(let i = len - 1; i > 0; i--) {
    const randomIndex = Math.floor(Math.random() * i);
    console.log('randomIndex ', randomIndex);
    [numList[randomIndex], numList[i]] = [numList[i], numList[randomIndex]];
  }
}

const testData = [1, 5, 7, 8, 12, 23, 30, 32, 45];
shufflePoker(testData);
console.log("testData ", testData);