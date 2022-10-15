//Less optimized using isSafe function which contains multiple while loops

class Solution {
    public List<List<String>> solveNQueens(int n) {
        List<List<String>> answer = new ArrayList<>();
        int i = 0;
        char[][] chessBoard = new char[n][n];
        
        for(int a=0; a<n; a++){
            for(int b=0; b<n; b++){
                chessBoard[a][b] = '.';
            }
        }
        
        dfs(i, n, chessBoard, answer);
        return answer;
    }
    
    public static void dfs
        (int i, int n, char[][] chessBoard, List<List<String>> answer)
    {
	    //base case
        if(i == n){
		    //to convert and add/insert the 2D array to type list 
            answer.add(construct(chessBoard));
            return;
        }
        else{
            for(int j=0; j<n; j++){
			
			    //to check whether the queen will attacked at this specific co-ordinate
                if(isSafe(i, j, chessBoard)){
                    
					//establishing the queen in this i, j co-ordinates
                    chessBoard[i][j] = 'Q';
					
					//recursive call
                    dfs(i+1, n, chessBoard, answer);
					
					//backtrack procedure
                    chessBoard[i][j] = '.';
                }
            }
        }
    }
    
    public static List<String> construct(char[][] chessBoard){
        List<String> oneCombinationOfChessBoard = new ArrayList<>();
        
        for(int i=0; i<chessBoard.length; i++){
            String s = new String(chessBoard[i]);
            oneCombinationOfChessBoard.add(s);
        }
        return oneCombinationOfChessBoard;
    }
    
    public static boolean isSafe(int i, int j, char[][] chessBoard){
        
        int n = chessBoard.length;
        int tempI = i;
        int tempJ = j;
        
        while(tempI >= 0){
            if(chessBoard[tempI][tempJ] == 'Q')return false;
            tempI--;
        }
        
        tempI = i;
        tempJ = j;
        
        while(tempI >=0 && tempJ <n && tempJ >=0){
            if(chessBoard[tempI][tempJ] == 'Q')return false;
            tempI--;
            tempJ--;
        }
        
        tempI = i;
        tempJ = j;
        
        while(tempI >=0 && tempJ <n && tempJ >=0){
            if(chessBoard[tempI][tempJ] == 'Q')return false;
            tempI--;
            tempJ++;
        }
        
        return true;
        
    }
}