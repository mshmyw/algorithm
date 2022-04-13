/**
 * 汉诺塔
 * 抽象为三步
 * 1 把n-1个盘子由A 移到 B；
 * 2 把第n个盘子由 A移到 C；
 * 3 把n-1个盘子由B 移到 C；
 */

interface Inum {
  name: string;
  order: number;
  data: number[];
};
const getRightList = (  
  numA: Inum,
  numB: Inum, 
  numC: Inum, ) => {
    const result = [numA, numB, numC].sort((a1: Inum, a2: Inum) => a1.order - a2.order);
    return result.map((item: any) => item.data);
};

const hannuota = (
  numA: Inum,
  numB: Inum, // bridge
  numC: Inum, // target,
  count: number,
  n: number
) => {
  if (count === 0) {
    return;
  }
  // 1 把 n-1 个盘子由 A 移到 B；
  hannuota(numA, numC, numB, count - 1, n);
  // console.log(
  //   `执行第 ${n - count + 1}-1 步，从 A => B，移动共 ${count - 1} 个盘子 `,
  //   numA,
  //   numB,
  //   numC
  // );

  // 2 把第 n 个盘子由 A 移到 C；（!其实真正具有可操作性的就是此步）
  const numN = numA.data.pop();
  numC.data.push(numN);
  console.log(
    `执行第 ${n - count + 1}-2 步，从 ${numA.name} => ${
      numC.name
    }(A->C)，移动第 ${count} 个盘子 `,
    getRightList(numA, numB, numC)
  );

  // 3 把 n-1 个盘子由 B 移到 C；
  hannuota(numB, numA, numC, count - 1, n);
  // console.log(
  //   `执行第 ${n - count + 1}-3 步，从 B => C，移动共 ${count - 1} 个盘子 `,
  //   numA, numB, numC
  // );
  // console.log(`--end--`);
};

const numA = {
  name: 'A',
  order: 1,
  data: [3, 2, 1],
};
const numB = {
  name: 'B',
  order: 2,
  data: [],
};
const numC = {
  name: 'C',
  order: 3,
  data: [],
};
const len = numA.data.length;
hannuota(numA, numB, numC, len, len);
