/**
 * 广度优先遍历
 * 递归
 */

// json 对象形式
const bfsJsonTraverse = (rootNode: any, targetValue: string) => {
  const queue = [rootNode];
  for(; queue.length; ) {
    const node = queue.shift();
    if(node.value === targetValue) {
      console.log('find it ', node, targetValue);
      break;
    }
    for(const childNode of node.children||[]) {
      queue.push(childNode);
    }
  }
};

/**
 * json 对象形式
 *           a
 *       b         c
 *    d     e   f     g
 * j   i  k
 */
const testData = {
  value: 'a',
  children: [
    {
      value: 'b',
      children: [
        {
          value: 'd',
          children: [{ value: 'j' }, { value: 'i' }],
        },
        { value: 'e', children: [{ value: 'k' }] },
      ],
    },
    {
      value: 'c',
      children: [{ value: 'f' }, { value: 'g' }],
    },
  ],
};

const targetList = ['e', 'c', 'i', 'm'];
for (const item of targetList) {
  bfsJsonTraverse(testData, item);
}
