package org.debojyotim;

import java.util.Arrays;
import java.util.ArrayList;

// Leet 455
class Solution {
    private ArrayList<Object> children;
    
    private boolean removeIfFound(int v) {
        for( Object c : this.children ) {
            Integer apt = (Integer) c;
            if( apt <= v ) {
                this.children.remove(c);
                return true;
            }
        }

        return false;
    }

    public int findContentChildren(int[] g, int[] s) {
        int contentChildrenCount = 0;
        this.children = new ArrayList<>();

        Arrays.sort(s);
        for( int i=0; i<g.length; i++ ) 
            children.add(g[i]);

        for( int i=0; i<s.length; i++ ) {
            if( removeIfFound(s[i]) ) {
                contentChildrenCount++;
            }
        }

        return contentChildrenCount;
    }
}
