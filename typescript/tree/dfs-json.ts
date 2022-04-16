/**
 * 深度优先遍历
 * 递归
 */


// json 对象形式
const dfsJsonTraverse = (rootNode: any, targetValue: string) => {
  if (!rootNode) {
    console.log('path end for ', rootNode, targetValue);
    return;
  }
  if (rootNode.value === targetValue) {
    console.log('find it ', rootNode, targetValue);
    return;
  }
  for (const node of rootNode.children || []) {
    dfsJsonTraverse(node, targetValue);
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
  dfsJsonTraverse(testData, item);
}
