import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
 public static void main (String[] args) throws java.lang.Exception {
 
  Scanner sc = new Scanner(System.in);
 
  int T = sc.nextInt();
 
  while(T-- > 0) {
   int N = sc.nextInt();
   Map<Integer, Set<Integer>> tree = new HashMap<>();
   for(int i = 1; i < N; i++) addPath(tree, sc.nextInt(), sc.nextInt());
 
            int[] level = new int[N+1];
            int[] parent = new int[N+1];
   preProcess(tree, level, parent);
 
   int Q = sc.nextInt();
   int[] visited = new int[N+1];
   for(int i = 1; i <= Q; i++) {
    int K = sc.nextInt();
    int[] query = new int[K];
    int maxDepth = 0;
    int nodeWithMaxDepth = -1;
    for(int j = 0; j < K; j++) {
     query[j] = sc.nextInt();
     if(level[query[j]] > maxDepth) {
      maxDepth = level[query[j]];
      nodeWithMaxDepth = query[j];
     }
    }
 
    boolean hasPath = process(nodeWithMaxDepth, parent, level, query, visited, i);
    System.out.println(hasPath ? "YES" : "NO");
   }
  }
 
  sc.close();
 }
 
 private static boolean process(int nodeWithMaxDepth, int[] parent, int[] level, int[] query, int[] visited, int marker) {
  visitTillParent(nodeWithMaxDepth, parent, visited, marker);
  int maxDepth = 0;
  nodeWithMaxDepth = -1;
  for(int q : query) {
   if(visited[q] != marker && level[q] > maxDepth) {
    maxDepth = level[q];
    nodeWithMaxDepth = q;
   }
  }
 
  if(nodeWithMaxDepth == -1) return true;
 
  while(visited[nodeWithMaxDepth] != marker) {
   visited[nodeWithMaxDepth] = marker;
   nodeWithMaxDepth = parent[nodeWithMaxDepth];
  }
 
  for(int q : query) {
   if(visited[q] != marker || level[q] < level[nodeWithMaxDepth]) return false;
  }
  return true;
 }
 
 private static void visitTillParent(int nodeWithMaxDepth, int[] parent, int[] visited, int marker) {
  visited[nodeWithMaxDepth] = marker;
  while(parent[nodeWithMaxDepth] != -1) {
   nodeWithMaxDepth = parent[nodeWithMaxDepth];
   visited[nodeWithMaxDepth] = marker;
  }
 }
 
 private static void preProcess(Map<Integer, Set<Integer>> tree, int[] level, int[] parent) {
  boolean[] visited = new boolean[level.length];
  Queue<Integer> bfsQueue = new LinkedList<>();
 
        int u = 1;
  parent[u] = -1;
  level[u] = 0;
  bfsQueue.add(u);
  visited[u] = true;
 
  while(!bfsQueue.isEmpty()) {
   int n = bfsQueue.size();
   while(n-- > 0) {
    int parentNode = bfsQueue.poll();
    Set<Integer> children = tree.get(parentNode);
    for(Integer child : children) {
     if(!visited[child]) {
      parent[child] = parentNode;
      level[child] = level[parentNode]+1;
      visited[child] = true;
      bfsQueue.add(child);
     }
    }
   }
  }
 }
 
 private static void addPath(Map<Integer, Set<Integer>> tree, Integer u, Integer v) {
  addEdge(tree, u, v);
  addEdge(tree, v, u);
 }
 
 private static void addEdge(Map<Integer, Set<Integer>> tree, Integer u, Integer v) {
  if(!tree.containsKey(u)) tree.put(u, new HashSet<>());
  tree.get(u).add(v);
 }
}
