export const swap = (numList: number[], left: number, right: number) {
  const temp = numList[left];
  numList[left] = numList[right];
  numList[right] = temp;
  return numList;
}