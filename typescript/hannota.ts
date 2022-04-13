/**
 * 汉诺塔
 * 抽象为三步
 * 1 把n-1个盘子由A 移到 B；
 * 2 把第n个盘子由 A移到 C；
 * 3 把n-1个盘子由B 移到 C；
 */

const hannuota = (
  listA: number[],
  listB: number[], // bridge
  listC: number[], // target,
  count: number,
  n: number
) => {
  if (count === 0) {
    return;
  }
  // 1 把 n-1 个盘子由 A 移到 B；
  hannuota(listA, listC, listB, count - 1, n);
  // console.log(
  //   `执行第 ${n - count + 1}-1 步，从 A => B，移动共 ${count - 1} 个盘子 `,
  //   listA,
  //   listB,
  //   listC
  // );

  // 2 把第 n 个盘子由 A 移到 C；
  const numN = listA.pop();
  listC.push(numN);
  console.log(
    `执行第 ${n - count + 1}-2 步，从 A => C，移动第 ${count} 个盘子 `,
    listA,
    listB,
    listC
  );

  // 3 把 n-1 个盘子由 B 移到 C；
  hannuota(listB, listA, listC, count - 1, n);
  // console.log(
  //   `执行第 ${n - count + 1}-3 步，从 B => C，移动共 ${count - 1} 个盘子 `,
  //   listA,
  //   listB,
  //   listC
  // );
  console.log(`--end--`);  
};

const num1List = [3, 2, 1];
const num2List = [];
const num3List = [];
hannuota(num1List, num2List, num3List, num1List.length, num1List.length);
