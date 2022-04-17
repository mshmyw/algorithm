/**
 * 击鼓传花
 * 到爆炸
 */

const passGame = (numList: number[], n: number) => {
  const outList = [];
  const queue = [...numList];
  while(queue.length > 1) {
    // 按数字 n 传递
    for(let i = 0; i < n; i++) {
      const head = queue.shift();
      queue.push(head);
    }
    // 该轮次淘汰队首元素
    const outHead = queue.shift();
    outList.push(outHead);
  }
  console.log("... ", queue, outList);
}

const testData = [1, 2, 3, 4, 5, 6, 7];

passGame(testData, 4);