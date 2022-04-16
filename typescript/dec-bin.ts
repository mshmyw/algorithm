/**
 * 进制转换 10 -> 2
 */

const decToBin = (num: number, base = 2) => {
  const stack = [];

  let result = num;
  while(result) {
    const mod = result % base;
    stack.push(mod);
    result = Math.floor(result / base);    
  }

  return stack.reverse();
}

/** test */
const testData = [1, 2, 3, 6, 13, 16, 31, 32];
for(const item of testData) {
  const result = decToBin(item);
  console.log(item, ' => ', result.join(''));
}