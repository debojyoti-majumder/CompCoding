package alpha;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.util.Random;

public class SimpleTest {

    @Test
    public void BasicTests() {
        SimpleSolution s = new SimpleSolution();
        var retVal = s.addNumbers(2,3);

        Assertions.assertEquals(retVal, 5);

        Random rnd = new Random();
        var positiveNumber = rnd.nextInt(200);
        var negNumber = -1 * positiveNumber;
        Assertions.assertEquals(s.addNumbers(positiveNumber, negNumber), 0);
    }
}
