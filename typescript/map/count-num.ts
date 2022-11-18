/**
 * 有 1-100 以内共99个数字，均不重复
 * 如何快速找出缺失的数字
 */
const numList = [1, 2, 4];
const COUNT = 4;
const numMap = {};

for (let i = 1; i <= COUNT; i++) {
    numMap[i] = 1;
}

for (const num of numList) {
    numMap[num] += 1;
}

for (const key of Object.keys(numMap)) {
    if (numMap[key] === 1) {
        console.log('target: ', key, numMap[key]);
    }
}
