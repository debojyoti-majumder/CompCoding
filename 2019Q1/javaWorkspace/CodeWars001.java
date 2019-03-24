// Problem URL: https://www.codewars.com/kata/battleship-field-validator/train/java

import java.util.Vector;

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

            public Blocks(Position s, Position e) {
                start = s;
                end = e;
            }
        }

        private Vector getBlocks(int[][] field, boolean isHorizontal) {
            Vector blocks = new Vector<>();
            int rows = field.length;
            int cols = field[0].length;
                
            if( isHorizontal ) {
                for(int i=0; i<rows; i++) {
                    Position start = new Position();
                    Position end = new Position();

                    start.x = i;
                    end.x = i;

                    for( int j=0; j<cols; j++ ) {
                        if( field[i][j] == 1 ) {
                            if( start.y == -1 )
                                start.y = j;
                            end.y = j;
                        } else if( end.y != -1 ) { 
                            // This means a new block is starting again
                            blocks.add(new Blocks(start, end));

                            start.y = -1;
                            end.y = -1;
                        }
                    }

                    if( start.x != -1 && start.y != -1 ) {
                        Blocks bl = new Blocks();
                        bl.start = start;
                        bl.end = end;

                        blocks.add(bl);
                    }
                }

                return blocks;
            } else {

            }

            return blocks;
        }

        public boolean fieldValidator(int[][] field) {
            if( field.length == 0 )
                return 0;

            return false;
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
