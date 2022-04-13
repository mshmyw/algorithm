/** 
 * 求最大公约数
*/
const gcd = (num1: number, num2: number) => {
  const result = num1 % num2;
  if(num2 === 0) {
    console.log("num1 ", num1);
    return;
  }
  gcd(num2, result);
}


const num1List = [143, 22];
const num2List = [13, 11];
for (let i = 0; i < num1List.length;i++) {
  gcd(num1List[i], num2List[i]);
}