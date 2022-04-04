/**
 * 插入排序
 * 将待处理元素插入到有序区间的合适位置
 * 与冒泡和选择的区别是：冒泡和选择关注在待排区间，而此处关注在有序区间
 * (0~i i~0) 
 */

const sortInsert = (numList: number[]) => {
  for(let i = 0; i < numList.length; i++ ) {
    const nextItemIndex = i+1;
    for(let j = nextItemIndex; j > 0; j--) {
      if(numList[j-1] > numList[j]) {
        const temp = numList[j-1];
        numList[j-1] = numList[j];
        numList[j] = temp;
      }
    }
  }
}

const testData = [1, 3, 7, 2, 5, 0];
sortInsert(testData);
console.log('res ', testData);


