package alpha;

import org.junit.jupiter.api.Disabled;
import org.junit.jupiter.api.Test;
import org.junit.jupiter.api.Assertions;

public class BasicCourseTakerTest {
    @Test
    @Disabled
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
    @Disabled
    public void myAddedTests() {
        BasicCourseTaker sol = new BasicCourseTaker();

        int[][] withoutLoop = {{1,2},{1,3},{1,4},{3,5},{3,6}};
        Assertions.assertTrue(sol.canFinish(6, withoutLoop));

        int[][] withLoop = {{1,2},{1,3},{1,4},{3,5},{3,6},{6,4}};
        Assertions.assertFalse(sol.canFinish(6,withLoop));
    }
}
