/**
 * 贪心
 * 最少硬币
 */

const minNumCoin = (money: number, coins: number[]) => {
  let total = 0;
  let minList = [];
  for (let i = coins.length - 1; i >= 0; i--) {
    const coin = coins[i];
    while (total + coin <= money) {
      minList.push(coin);
      console.log('new Min ' + minList + ' for ' + money);
      total = total + coin;
    }
  }
};

minNumCoin(36, [1, 2, 5, 10, 20]);
