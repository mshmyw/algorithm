/** flat array convert to tree
 * 其本质在于：
 * 1 知道子节点的父节点指针 pid
 * 2 对父节点改查：游走到父节点后，对其操作子节点（改）
 * */
const groupBy = (arrList, key) => {
  const nodeMap = arrList.reduce((curReduce, curNode) => {
    const keyValue = curNode[key];
    curReduce[keyValue] = curNode;
    return curReduce;
  }, {});
  return nodeMap;
};
const flatArrayToTree = (arrList) => {
  const treeList = [];
  // list to map
  const nodeMap = groupBy(arrList, 'id');
  for(const node of arrList) {
    if(!node.pid) {
      treeList.push(node);
      continue;
    }
    const pid = node.pid;
    const pNode = nodeMap[pid];
    if(!pNode) {
      continue;
    }
    if(!pNode.children) {
      pNode.children = [];
    }
    pNode.children.push(node);
  }
  console.log("hello", JSON.stringify(treeList));
}
const arr = [
  { id: 1, title: '杂货铺1', pid: 0 },
  { id: 2, title: '杂货铺2', pid: 0 },
  { id: 3, title: '杂货铺2-1', pid: 2 },
  { id: 4, title: '杂货铺3-1', pid: 3 },
  { id: 5, title: '杂货铺4-1', pid: 4 },
  { id: 6, title: '杂货铺5-1', pid: 2 },
];
// flatArrayToTree(arr);

const treeList = [
  { id: 1, title: '杂货铺1', pid: 0 },
  {
    id: 2,
    title: '杂货铺2',
    pid: 0,
    children: [
      {
        id: 3,
        title: '杂货铺2-1',
        pid: 2,
        children: [
          {
            id: 4,
            title: '杂货铺3-1',
            pid: 3,
            children: [{ id: 5, title: '杂货铺4-1', pid: 4 }],
          },
        ],
      },
      { id: 6, title: '杂货铺5-1', pid: 2 },
    ],
  },
];

/**
 * tree flat to array
*/
const treeToFlatArr1 = (treeList) => {
  const arrList = [];
  for(const node of treeList) {
    if(!node.children) {
      arrList.push(node);
      continue;
    }
    const {children, ...rest} = node;
    if(rest) {
      arrList.push(rest);
    }
    const childList = treeToFlatArr(children);
    arrList.push(...childList);
  }
  return arrList;
};

const treeToFlatArr = (treeList) => {
  const arrList = treeList.reduce((curList, curNode) => {
    const {children, ...rest} = curNode;
    if(rest) {
      curList.push(rest);
    }
    if(children) {
      const cList = treeToFlatArr(children);
      curList.push(...cList);
    }
    return curList;
  }, []);

  return arrList;
}

const flatArr = treeToFlatArr(treeList);
console.log("arr", flatArr);