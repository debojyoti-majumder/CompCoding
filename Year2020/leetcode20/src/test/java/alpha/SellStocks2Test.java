package alpha;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.DisplayName;
import org.junit.jupiter.api.Test;

@DisplayName("Leetcode 122")
public class SellStocks2Test {
    @Test
    public void basicTest() {
        int[] input1 = new int[] {7,1,5,3,6,4};
        int[] input2 = new int[] {1,2,3,4,5};
        int[] input3 = new int[] {5,4,2,1};

        SellStocks2 solver = new SellStocks2();

        Assertions.assertEquals(7, solver.maxProfit(input1));
        Assertions.assertEquals(4, solver.maxProfit(input2));
        Assertions.assertEquals(0, solver.maxProfit(input3));
    }
}
