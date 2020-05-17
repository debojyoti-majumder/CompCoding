// Problem URL: https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/536/week-3-may-15th-may-21st/3332/
// The basic example for time limit error, might need to device a better map based implementation

package com.debojyoti;

import org.hamcrest.CoreMatchers;
import org.junit.Test;
import static org.junit.Assert.assertThat;

import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

public class AnagramFinder {
    private List<Integer> returnValue;
    private HashMap<Character, Integer> sourceStringMap;
    private HashMap<Character, Integer> destinationStringMapping;

    private HashMap<Character, Integer> initStringMapping(String str) {
        HashMap<Character, Integer> returnValue = new HashMap<>();

        return returnValue;
    }

    private boolean lookForAnagram(String source, String destination ) {
        StringBuffer copy = new StringBuffer(destination);

        for( int i=0; i<source.length(); i++ ) {
            char ch = source.charAt(i);
            String tmp = String.valueOf(ch);
            int findIndex = copy.indexOf(tmp);

            if( findIndex == -1 ) return false;
            else copy.deleteCharAt(findIndex);
        }

        return true;
    }

    public List<Integer> findAnagrams(String s, String p) {
        returnValue = new ArrayList<>();
        int biggerStringLength = s.length();
        int smallerStringLength = p.length();

        // This is for sanity testing
        if( biggerStringLength < smallerStringLength ) return returnValue;
        int matchesToBeLooked = biggerStringLength - smallerStringLength;

        for( int repetition=0; repetition <= matchesToBeLooked; repetition++ ) {
            String toBeMatched = s.substring(repetition, repetition + smallerStringLength);
            if( lookForAnagram(toBeMatched, p) ) returnValue.add(repetition);
        }

        return  returnValue;
    }

    @Test
    public void basicTest() {
        AnagramFinder finder = new AnagramFinder();
        List<Integer> ret1 = finder.findAnagrams("cbaebabacd","abc");
        List<Integer> expectedOutut = new ArrayList<>();
        expectedOutut.add(0);
        expectedOutut.add(6);
        assertThat(ret1, CoreMatchers.equalTo(expectedOutut));

        List<Integer> ret2 = finder.findAnagrams("abab", "ab");
        List<Integer> expectedOutut2 = new ArrayList<>();
        expectedOutut2.add(0);
        expectedOutut2.add(1);
        expectedOutut2.add(2);
        assertThat(ret2, CoreMatchers.equalTo(expectedOutut2));
    }
}
