package alpha;

import java.util.List;

// Problem URL: https://leetcode.com/explore/featured/card/august-leetcoding-challenge/549/week-1-august-1st-august-7th/3410/
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
    }

    public void remove(int key) {

    }

    /** Returns true if this set contains the specified element */
    public boolean contains(int key) {
        return false;
    }
}
