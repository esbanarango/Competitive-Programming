import java.util.Arrays;
import java.util.Scanner;

public class triangle {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    String[] t1 = in.nextLine().split(" ");
    String[] t2 = in.nextLine().split(" ");
    Arrays.sort(t1);
    Arrays.sort(t2);
    if(!Arrays.equals(t1, t2)) {
      System.out.println("NO");
      return;
    }
    int a = Integer.parseInt(t2[0]);
    int b = Integer.parseInt(t2[1]);
    int c = Integer.parseInt(t2[2]);

    boolean result = (c * c == (a * a) + (b * b));
    System.out.println(result ? "YES" : "NO");
  }
}
