/** 
 * 图
 * 邻接表表示法
 * 代码文件中插入图片可否？
 *       A
 *    / |  \
 *   B  C - D
 *  /\  /\  /\
 * E  F   G   H
 * |
 * I
*/
class Graph {
  isDirected: boolean; // 是否为有向图
  vertices: string[]; // 图的顶点集合
  adjList;
  constructor(isDirected = false) {
    this.isDirected = isDirected; // {1}
    this.vertices = []; // {2}
    this.adjList = new Map(); // {3}
  }
  /** 添加顶点 */
  addVertex(v) {
    if (!this.vertices.includes(v)) {
      // {5}
      this.vertices.push(v); // {6}
      this.adjList.set(v, []); // {7}
    }
  }
  /** 添加边 */
  addEdge(v, w) {
    if (!this.adjList.get(v)) {
      this.addVertex(v); // {8}
    }
    if (!this.adjList.get(w)) {
      this.addVertex(w); // {9}
    }
    this.adjList.get(v).push(w); // {10}
    if (!this.isDirected) {
      this.adjList.get(w).push(v); // {11}
    }
  }
  getVertices() {
    return this.vertices;
  }
  getAdjList() {
    return this.adjList;
  }
  /** 对邻接表打印 */
  toString() {
    let s = '';
    for (let i = 0; i < this.vertices.length; i++) {
      // {15}
      s += `${this.vertices[i]} -> `;
      const neighbors = this.adjList.get(this.vertices[i]); // {16}
      for (let j = 0; j < neighbors.length; j++) {
        // {17}
        s += `${neighbors[j]} `;
      }
      s += '\n'; // {18}
    }
    return s;
  }
}

// test
const graph = new Graph();
const myVertices = ['A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I']; // {12}
for (let i = 0; i < myVertices.length; i++) { // {13}
graph.addVertex(myVertices[i]);
}
graph.addEdge('A', 'B'); // {14}
graph.addEdge('A', 'C');
graph.addEdge('A', 'D');
graph.addEdge('C', 'D');
graph.addEdge('C', 'G');
graph.addEdge('D', 'G');
graph.addEdge('D', 'H');
graph.addEdge('B', 'E');
graph.addEdge('B', 'F');
graph.addEdge('E', 'I');

const adjList = graph.toString();
console.log(adjList);
/** 
 * "A -> B C D 
B -> A E F 
C -> A D G 
D -> A C G H 
E -> B I 
F -> B 
G -> C D 
H -> D 
I -> E 
" 
*/

// 要访问顶点 v，照如下步骤做：
// (1) 标注 v 为被发现的（灰色）；
// (2) 对于 v 的所有未访问（白色）的邻点 w，访问顶点 w；
// (3) 标注 v 为已被探索的（黑色）。
enum Colors {
  WHITE = 0, // 未访问
  GREY = 1, // 已发现（必要的中间状态）
  BLACK = 2, // 已访问
}

const initializeColor = (vertices: string[]) => {
  const colors: any = {};
  for(const v of vertices) {
    colors[v] = Colors.WHITE;
  }

  return colors;
};

// DFS
const depthFirstSearch = (graph: Graph, callback) => { // {1}
  const vertices = graph.getVertices();
  const adjList = graph.getAdjList();
  const color = initializeColor(vertices);
  for (let i = 0; i < vertices.length; i++) {// {2}
    if (color[vertices[i]] === Colors.WHITE) {// {3}
      depthFirstSearchVisit(vertices[i], color, adjList, callback); // {4}
    }
  }
};

const depthFirstSearchVisit = (u, color, adjList, callback) => {
  color[u] = Colors.GREY; // {5}
  if (callback) {
    // {6}
    callback(u);
  }
  // 注意：仔细思考可知，对于邻接表而言，第 {7} 步骤相当于树的取孩子节点的过程
  const neighbors = adjList.get(u); // {7}
  for (let i = 0; i < neighbors.length; i++) {
    // {8}
    const w = neighbors[i]; // {9}
    if (color[w] === Colors.WHITE) { // {10}
      depthFirstSearchVisit(w, color, adjList, callback); // {11}
    }
  }
  color[u] = Colors.BLACK; // {12}
};  

const printVertex = (vertice: string) => {
  console.log("V ", vertice);
}
depthFirstSearch(graph, printVertex);


/** 
 * 有向图
 *    A     B
 *  /  \  /  \
 * C    D    E
 *  \       /
 *   \    / 
 *     F   
*/
const graph1 = new Graph(true); // 有向图
const myVertices1 = ['A', 'B', 'C', 'D', 'E', 'F'];
for (let i = 0; i < myVertices.length; i++) {
  graph1.addVertex(myVertices1[i]);
}
graph1.addEdge('A', 'C');
graph1.addEdge('A', 'D');
graph1.addEdge('B', 'D');
graph1.addEdge('B', 'E');
graph1.addEdge('C', 'F');
graph1.addEdge('F', 'E');

depthFirstSearch(graph1, printVertex);