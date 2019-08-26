// Problem URL: https://leetcode.com/problems/maximum-length-of-pair-chain/
// Problem Id: 646

package app;
import java.util.ArrayList;

class LongestChain {

    private class ChainPair {
        private int _first;
        private int _second;

        public ChainPair(int i, int j) {
            _first = i;
            _second = j;
            _maxVal = 0;
        }

        public boolean canBeChained(ChainPair p) {
            return _second < p._first;
        }
    }

    private ArrayList<ChainPair> _pairs;
    private int _maxVal;

    public LongestChain(int[][] pairs) {
        _pairs = new ArrayList<>();
        for( int i=0; i<pairs.length; i++ ) {
            _pairs.add(new ChainPair(pairs[i][0] , pairs[i][1]));
        }
    }

    private LongestChain(ArrayList<ChainPair> pairs) {
        _pairs = pairs;
    }

    private void updateMaxVal(int v) {
        if( v > _maxVal ) _maxVal = v;
    }

    public int getLongestChainLength() {
        // This is the base case, return value can be 0 or 1
        int pairSize = _pairs.size();
        if( pairSize < 2 ) return pairSize; 

        // Iterating through each list
        for( ChainPair p : _pairs ) {
            ArrayList<ChainPair> subProblem = new ArrayList<>(_pairs);
            
            // Without the item
            subProblem.remove(p);
            LongestChain ch = new LongestChain(subProblem);
            updateMaxVal(ch.getLongestChainLength());

            // With the item, that's why we are adding the 1
            subProblem.removeIf(prob -> p.canBeChained(prob) == false );
            LongestChain ch2 = new LongestChain(subProblem);
            updateMaxVal(1 + ch2.getLongestChainLength());
        }

        return _maxVal;
    }
}
