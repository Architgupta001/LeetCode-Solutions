class Solution {
    public int countArrangement(int n) {
        boolean[] visited = new boolean[n+1];
        return countBeautifulArrangements(n, 1, visited);
    }
    
    private int countBeautifulArrangements(int n, int idx, boolean[] visited){
        if(idx > n){
            return 1;
        }
        int count = 0;
        for(int i=1; i<=n; i++){
            if(visited[i] == false && (i % idx == 0 || idx % i == 0)){
                visited[i] = true;
                count += countBeautifulArrangements(n, idx+1, visited);
                visited[i] = false;
            }
        }
        return count;
    }
}