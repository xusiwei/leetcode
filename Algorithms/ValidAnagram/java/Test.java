public class Test {
    public static void main(String[] args) {
        String s = "anagram";
        String t = "nagaram";
        if (args.length >= 1) s = args[0];
        if (args.length >= 2) t = args[1];
        System.out.println(s);
        System.out.println(t);
        System.out.println(new Solution().isAnagram(s, t));
    }
}
