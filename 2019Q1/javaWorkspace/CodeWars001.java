// Problem URL: https://www.codewars.com/kata/battleship-field-validator/train/java

import java.util.Vector;

import com.sun.crypto.provider.BlowfishKeyGenerator;

public class CodeWars001 {
    public static class BattleField {
        private class Position {
            public int x;
            public int y;

            public Position() {
                x = -1;
                y = -1;
            }
        }

        private class Blocks {
            public Position start;
            public Position end;
            public boolean isHorizontal;

            public Blocks(Position s, Position e, boolean b) {
                start = s;
                end = e;
                isHorizontal = b;
            }
        }

        private Blocks getBlock(int[][] field, boolean isHorizontal, Position s) { 
            Position end = new Position();
            int rows = field.length;
            int cols = field[0].length;

            if( isHorizontal ) {
                end.x = s.x;
                int index = s.y;
                
                while( field[s.x][index] != 0 && index < cols) {
                    index = index + 1;
                }

                end.y = index;
            } else {
                end.y = s.y;
                int index = s.x;

                while( field[index][s.y] != 0 && index < rows ) {
                    index = index + 1;
                }   

                end.x = index;
            }

            return new Blocks(s, end, isHorizontal);
        }

        private boolean isValidBlock(int[][] field, Block b) {
            return false;
        }

        public boolean fieldValidator(int[][] field) {
            if( field.length == 0 )
                return 0;

            blocksCopy = field.clone();
            Vector<Blocks> blocks = new Vector<>();

            for( int i=0; i<blocksCopy.length; i++ ) {
                for(int j=0; j<blocksCopy[0].length - 1; j++) {    
                    if( blocksCopy[i][j] == 1 && blocksCopy[i][j+1] == 1 ) {
                        Position pos = new Position();
                        pos.x = i;
                        pos.y = j;

                        Blocks b = this.getBlock(blocksCopy, true, pos);
                        blocks.add(b);

                        for(int m = b.start.y; m<=b.end.y; m++) {
                            blocksCopy[b.start.x][m] = 0;   
                        }
                    }
                }
            }

            for(int i=0; i<blocksCopy.length - 1; i++) {
                for(int j=0; j<blocksCopy[0].length; j++) {
                    if( blocksCopy[i][j] == 1 && blocksCopy[i+1][j] == 1 ) {
                        Position pos = new Position();
                        pos.x = i;
                        pos.y = j;

                        Blocks b = this.getBlock(blocksCopy, false, pos);
                        blocks.add(b);

                        for(int m=b.start.x; m<=b.end.x; m++) {
                            blocksCopy[m][b.start.y] = 0;
                        }
                    } 
                }
            }

            for( Blocks b : blocks ) {
                if( isValidBlock(field, b) == false )
                    return false;
            }

            return true;
        }
    }

    public static void main(String args[]) {
        int[][] battleField = {
            {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
            {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
            {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
            {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
            {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
        };

        // Should output true
        BattleField fd = new BattleField();
        System.out.println("Is valid:" + fd.fieldValidator(battleField));
    }
}
