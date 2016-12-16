import java.util.Scanner;

public class magic {
  public static void main(String[] args) {
    Scanner in = new Scanner(System.in);
    int result = 0;
    int ops = Integer.parseInt(in.nextLine());
    String[] operations = new String[ops];
    int[] values = new int[ops];
    for (int i = 0; i < ops; i++) {
      String[] line = in.nextLine().split(" ");
      operations[i] = line[0];
      values[i] = Integer.parseInt(line[1]);
    }
    float k;
    int v;
    for (int i = 1; i <= 100; i++) {
      k = i;
      for (int j = 0; j < ops; j++) {
        v = values[j];
        switch (operations[j]) {
          case "ADD":
            k = k + v;
            break;
          case "SUBTRACT":
            k = k - v;
            break;
          case "MULTIPLY":
            k = k * v;
            break;
          case "DIVIDE":
            k = k / v;
            break;
        }
        if (k < 0 || (k != (int)k)) {
          result++;
          break;
        }
      }
    }

    System.out.println(result);
  }
}
