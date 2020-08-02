// Problem URL: https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/
// Problem ID: 705

package alpha;

import java.util.ArrayList;
import java.util.List;

public class CustomHashImpl {
    private static final int arraySize = 10000;
    private static final int primeNumber = 199;

    private List<Integer> hashContainer[];

    public CustomHashImpl() {
        hashContainer = new List[arraySize];
    }

    public void add(int key) {
        int resKey = (primeNumber * key) % arraySize;
        List<Integer> bucket = hashContainer[resKey];

        if( bucket == null ) {
            hashContainer[resKey] = new ArrayList<>();
            hashContainer[resKey].add(key);
        }
        else {
            // Only add if the item is already not present
            if( !bucket.contains(key)) bucket.add(key);
        }
    }

    public void remove(int key) {
        int resKey = (primeNumber * key) % arraySize;
        List<Integer> bucket = hashContainer[resKey];

        if( bucket != null ) {
            Integer obj = key;
            bucket.remove(obj);
        };
    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        int resKey = (primeNumber * key) % arraySize;
        List<Integer> bucket = hashContainer[resKey];

        if( bucket == null ) return false;
        return bucket.contains(key);
    }
}
