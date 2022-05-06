/**
 * 最少硬币找零
 * 有如下硬币面值：1 5 10 25
 * 对总钱币数 n， 求最少找零数
 * 方案：动态规划
 * 1 分解为关联子问题 
 * 2 求解子问题
 */

const minNumCoin = (money: number, coins: number[]) => {
  const cache = [];
  const makeChange = (value: number) => {
    if(!value) {
      return [];
    }
    if(cache[value]) {
      return cache[value];
    }
    let min = [];
    let newMin;
    let newAmount;
    for (const coin of coins) {
      newAmount = value - coin;
      if (newAmount >= 0) {
        newMin = makeChange(newAmount);
      }
      if(newAmount >= 0 && (newMin.length < min.length - 1 || !min.length) &&
      (newMin.length || !newAmount)) {
        min = [coin, ...newMin];
        console.log('new Min ' + min + ' for ' + money);        
      }
    }
    cache[value] = min;
    return cache[value];
  };
  return makeChange(money);
}

console.log(minNumCoin(36, [1, 5, 10, 25]));
