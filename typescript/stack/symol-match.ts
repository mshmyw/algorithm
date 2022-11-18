/**
 * 给定字符串，含有符号 () [] {}
 * 判断其是否嵌套匹配
 * case:
 * ()  true
 * x([])  true
 * x([)]y false
 * x( false
 */

/** global variable */
const symbolMap = {
    ')': '(', ']': '[', '}': '{'
};
const leftSymbolList = Object.values(symbolMap);
const rightSymbolList = Object.keys(symbolMap);
/** global variable */

const symbolMatch = (str: string) => {
    const symbolStack: string[] = [];
    for (const item of str) {
        if (leftSymbolList.includes(item)) {
            symbolStack.push(item);
        }
        if (rightSymbolList.includes(item)) {
            const targetLeftSymbol = symbolMap[item];
            if (symbolStack[symbolStack.length - 1] !== targetLeftSymbol) {
                // 与栈顶不匹配，则直接退出 返回false即可！
                return false;
            }
            // 与栈顶匹配，pop            
            symbolStack.pop();            
        }
    }

    return symbolStack.length === 0;
};

const symbolMatchRecur = (str: string, symbolStack: string[]=[]) => { 
    if (!str) {
        return symbolStack.length === 0;
    }
    
    const char = str[0];
    if (leftSymbolList.includes(char)) {
        symbolStack.push(char);
    }
    if (rightSymbolList.includes(char)) {
        const targetLeftSymbol = symbolMap[char];        
        if (symbolStack[symbolStack.length - 1] !== targetLeftSymbol) {
            return false;
        }
        symbolStack.pop();
    }
    const subStr = str.slice(1);
    const result = symbolMatchRecur(subStr, symbolStack);
    return result;
};

const testList = [
    ')', 
    '(', 
    '()', '([)]', '([])', '([]))', '1([()])x'
];

for(const testItem of testList) {
    const result = symbolMatch(testItem);
    const result1 = symbolMatchRecur(testItem, []);    
    console.log(`${testItem} ${result} | ${result1}`);
}