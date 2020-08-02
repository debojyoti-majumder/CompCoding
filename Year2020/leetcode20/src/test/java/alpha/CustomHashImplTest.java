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

    @Test
    public void moreTest() {
        CustomHashImpl hashSet = new CustomHashImpl();

        hashSet.add(1);
        hashSet.add(2);
        Assertions.assertTrue(hashSet.contains(1));
        Assertions.assertFalse(hashSet.contains(3));

        hashSet.add(2);
        Assertions.assertTrue(hashSet.contains(2));
        hashSet.remove(2);
        Assertions.assertFalse(hashSet.contains(2));
    }
}
