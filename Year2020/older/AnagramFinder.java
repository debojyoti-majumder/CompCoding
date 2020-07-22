// Problem URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
// Regular link: https://leetcode.com/problems/find-all-anagrams-in-a-string/
// Problem ID: 438

// The basic example for time limit error, might need to device a better map based implementation
// Solved time out error with a help of Hash map carefully updating it

package com.debojyoti;

import org.hamcrest.CoreMatchers;
import org.junit.Test;
import static org.junit.Assert.assertThat;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class AnagramFinder {
    private List<Integer> returnValue;
    private HashMap<Character, Integer> sourceStringMap;
    private HashMap<Character, Integer> destinationStringMapping;

    private HashMap<Character, Integer> initStringMapping(String str) {
        HashMap<Character, Integer> returnValue = new HashMap<>();
        int len = str.length();

        for( int i=0; i<len; i++ ) {
            Character ch = str.charAt(i);
            Integer val = returnValue.get(ch);

            if( val == null ) returnValue.put(ch,1);
            else returnValue.put(ch, val + 1);
        }

        return returnValue;
    }

    private void updateStringMap(Character oldChar, Character newChar) {
        Integer oldNum = sourceStringMap.get(oldChar);
        if( oldNum == 1 ) sourceStringMap.remove(oldChar);
        else sourceStringMap.put(oldChar, oldNum - 1);

        Integer newCount = sourceStringMap.get(newChar);
        if ( newCount == null ) sourceStringMap.put(newChar, 1);
        else sourceStringMap.put(newChar, newCount + 1);
    }

    private boolean lookForAnagram() {
        boolean returnValue = true;

        for (Map.Entry<Character, Integer> entry : destinationStringMapping.entrySet()) {
            Character character = entry.getKey();
            Integer integer = entry.getValue();
            Integer lookupValue = sourceStringMap.get(character);

            if (lookupValue == null) {
                returnValue = false;
                break;
            }
            else if(!lookupValue.equals(integer)) {
                returnValue = false;
                break;
            }
        }

        return returnValue;
    }

    public List<Integer> findAnagrams(String s, String p) {
        returnValue = new ArrayList<>();
        int biggerStringLength = s.length();
        int smallerStringLength = p.length();

        destinationStringMapping = initStringMapping(p);

        // This is for sanity testing
        if( biggerStringLength < smallerStringLength ) return returnValue;
        int matchesToBeLooked = biggerStringLength - smallerStringLength;

        for( int repetition=0; repetition <= matchesToBeLooked; repetition++ ) {
            if( repetition == 0 ) {
                sourceStringMap = initStringMapping(s.substring(0, smallerStringLength));
            }
            else {
                Character newChar = s.charAt(repetition + smallerStringLength - 1);
                Character oldChar = s.charAt(repetition - 1);
                updateStringMap(oldChar, newChar);
            }

            if( lookForAnagram() ) returnValue.add(repetition);
        }

        return  returnValue;
    }

    @Test
    public void basicTest() {
        AnagramFinder finder = new AnagramFinder();
        List<Integer> ret1 = finder.findAnagrams("cbaebabacd","abc");
        assertThat(ret1, CoreMatchers.equalTo(List.of(0,6)));

        List<Integer> ret2 = finder.findAnagrams("abab", "ab");
        assertThat(ret2, CoreMatchers.equalTo(List.of(0,1,2)));
    }
}
