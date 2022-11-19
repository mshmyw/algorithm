


/**
获取最长子串
case:
abcaeb   abc 3
bbb  b 1
ababcda abcd 4

*/  
const getLongestSubStr = (str: string) => {
  if (typeof str !== 'string') {
    return;
  }
  if (!str) {
    return 0;
  }
  if (str.length === 1) {
    return 1;
  }
    

  let leftPosition = 0;
  let rightPostion = 0;
  let maxSubStrLen = 1;
  for (leftPosition = 0; leftPosition < str.length; leftPosition++) {
    for (rightPostion = leftPosition + 1; rightPostion < str.length; rightPostion++) {
      if (str[leftPosition] === str[rightPostion]) {
        maxSubStrLen = Math.max(rightPostion - leftPosition, maxSubStrLen);
        // 记得右边指针游走的时候，一旦不满足条件，则立即结束此次遍历
        break;
      }
    }
  }

  return maxSubStrLen;
}

const testStrList :string[] = [
  'abcaeb',
  'bbb',
  'ababcda',
];

for(const testItem of testStrList) {
  const result = getLongestSubStr(testItem);
  console.log(`${testItem} ${result}`);
}