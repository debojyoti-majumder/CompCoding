package alpha;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

public class BasicCourseTakerTest {
    @Test
    public void basicTest() {
        BasicCourseTaker sol = new BasicCourseTaker();

        int[][] input1= {{1,0}, {0,1}};
        int[][] input2 = {{1,0}};

        var r1 = sol.canFinish(2, input1);
        var r2 = sol.canFinish(2, input2);

        Assertions.assertTrue(r2);
        Assertions.assertFalse(r1);
    }

    @Test
    public void myAddedTests() {
        BasicCourseTaker sol = new BasicCourseTaker();
    }
}
