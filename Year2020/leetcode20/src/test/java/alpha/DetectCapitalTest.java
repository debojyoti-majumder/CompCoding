package alpha;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName(value = "Leetcode 520")
public class DetectCapitalTest {
    @Test
    public void basicTest() {
        DetectCapital cap = new DetectCapital();

        Assertions.assertTrue(cap.detectCapitalUse("HELLO"));
        Assertions.assertTrue(cap.detectCapitalUse("world"));
        Assertions.assertTrue(cap.detectCapitalUse("Debojyoti"));

        Assertions.assertFalse(cap.detectCapitalUse("ggHH"));
        Assertions.assertFalse(cap.detectCapitalUse("FaNNGG"));
    }
}
