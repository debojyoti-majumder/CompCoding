package alpha;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName(value = "Leetcode 125")
public class PalindromeSentenceTest {
    @Test
    public void voidBasicTest() {
        PalindromeSentence sentence = new PalindromeSentence();

        Assertions.assertTrue(sentence.isPalindrome("A man, a plan, a canal: Panama"));
        Assertions.assertFalse(sentence.isPalindrome("Race a car"));
    }
}
