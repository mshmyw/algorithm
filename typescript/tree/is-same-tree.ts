/**
 * 判断两颗树是否完全相同，
 * 据说DOM 中判断此问题需要O(n^3)复杂度
 */

class TNode {
  value: number;
  left: TNode;
  right: TNode;
  constructor(val: number, left: TNode, right: TNode) {
    this.value = val;
    this.left = left;
    this.right = right;
  }
}
const isSameTree = (tree1: TNode, tree2: TNode) => {
  if(!tree1 && !tree2) {
    return true;
  }
  if(!tree1 && tree2) {
    return false;
  }
  if(tree1 && !tree2) {
    return false;
  }
  
  if(tree1.value !== tree2.value) {
    return false;
  }

  const isLeftSame = isSameTree(tree1.left, tree2.left);
  const isRightSame = isSameTree(tree1.right, tree2.right);
  return isLeftSame === isRightSame;
}

const n1 = new TNode(1, null, null);
const n2 = new TNode(2, null, null);
const n3 = new TNode(3, null, null);
n1.left = n2;
n1.right = n3;

const n4 = new TNode(1, null, null);
const n5 = new TNode(2, null, null);
const n6 = new TNode(3, null, null);
n4.left = n5;
n4.right = n6;

console.log("isSame: ", isSameTree(n1, n4));


