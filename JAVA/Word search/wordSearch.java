public class Solution {
        public boolean exist(char[][] board, String word) {
            for(int i = 0;i < board.length;i++){
                for(int j = 0;j < board[0].length;j++){
                    if(board[i][j] == word.charAt(0)){
                        // dfs
                        Stack<Integer> x_pos = new Stack<Integer>();
                        Stack<Integer> y_pos = new Stack<Integer>();
                        Stack<Integer> word_index = new Stack<Integer>();
                        Stack<Integer> x_track = new Stack<Integer>();
                        Stack<Integer> y_track = new Stack<Integer>();
                        int[][] subpath_num = new int[board.length][board[0].length];
                        boolean[][] visited = new boolean[board.length][board[0].length];
                        for(int q = 0;q < board.length;q++)
                            for(int p = 0;p < board[0].length;p++)
                                visited[q][p] = false;
                        x_pos.add(i);y_pos.add(j);
                        word_index.add(0);
                        while(!x_pos.isEmpty()){
                            int x = x_pos.pop();
                            int y = y_pos.pop();
                            int index = word_index.pop()+1;
                            if(index == word.length()){return true;}
                            int count_subpath = 0;
                            x_track.add(x);y_track.add(y);
                            visited[x][y] = true;
                            if(x-1 >= 0){
                                if(board[x-1][y] == word.charAt(index) && !visited[x-1][y]){
                                    x_pos.add(x-1);y_pos.add(y);
                                    word_index.add(index);
                                    count_subpath++;
                                }
                            }
                            if(x+1 < board.length){
                                if(board[x+1][y] == word.charAt(index) && !visited[x+1][y]){
                                    x_pos.add(x+1);y_pos.add(y);
                                    word_index.add(index);
                                    count_subpath++;
                                }
                            }
                            if(y-1 >= 0){
                                if(board[x][y-1] == word.charAt(index) && !visited[x][y-1]){
                                    x_pos.add(x);y_pos.add(y-1);
                                    word_index.add(index);
                                    count_subpath++;
                                }
                            }
                            if(y+1 < board[0].length){
                                if(board[x][y+1] == word.charAt(index) && !visited[x][y+1]){
                                    x_pos.add(x);y_pos.add(y+1);
                                    word_index.add(index);
                                    count_subpath++;
                                }
                            }
                            subpath_num[x][y] = count_subpath;
                            // reset the visited mark
                            if(subpath_num[x][y] == 0){
                                int cur_x = x_track.pop();
                                int cur_y = y_track.pop();
                                while(subpath_num[cur_x][cur_y] <= 1){
                                    visited[cur_x][cur_y] = false;
                                    if(x_track.isEmpty()){break;}
                                    cur_x = x_track.pop();
                                    cur_y = y_track.pop();
                                }
                                subpath_num[cur_x][cur_y]--;
                            }
                        }
                    }
                }
            }
            return false;
        }
    }