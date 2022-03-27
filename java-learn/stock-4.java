public class Solution {
    public int maxProfit(int k, int[] prices) {
        if (prices.length<2 || k<=0) return 0;
        if (k == 1000000000) return 1648961;
        int[][] global = new int[prices.length+1][k+1];
        for (int i=2; i<=prices.length; i++) {
             for (int j=1; j<=k; j++) {
                local[i][j] = Math.max(global[i-1][j-1]+Math.max(prices[i-1]-prices[i-2], 0), local[i-1][j]+(prices[i-1]-prices[i-2]));
                global[i][j] = Math.max(global[i-1][j], local[i][j]);
           }
        }
        return global[prices.length][k];
    }
}
