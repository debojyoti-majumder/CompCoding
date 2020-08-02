package alpha;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;


public class CustomHashImplTest {
    @Test
    public void simpleTest(){
        CustomHashImpl impl = new CustomHashImpl();
        impl.add(345);
        impl.add(455);

        impl.remove(345);

        Assertions.assertTrue(impl.contains(455));
        Assertions.assertFalse(impl.contains(345));
    }
}
