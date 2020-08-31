
public class ApplicationRunner {
    private static boolean fourVerifier(int num) {
        double res = Math.log(num) / Math.log(4);
        int intRes = (int) (Math.log(num) / Math.log(4));

        return res == intRes;
    }

    public static void main(String[] args) {
        System.out.println(fourVerifier(32));
        System.out.println(fourVerifier(64));
        System.out.println(fourVerifier(16));
        System.out.println(fourVerifier(624));

        System.out.println("Hello leetcode");
    }
}
