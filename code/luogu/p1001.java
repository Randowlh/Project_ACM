import java.util.*;
import java.math.*;

class p1001 {
  // static int[] num = new int[10];
  static int a, b, c;

  private static boolean ck(int k) {
    int[] num = new int[10], a = new int[3];
    for (int i = 0; i < 10; i++)
      num[i] = 0;
    a[0] = k;
    a[1] = (k / a[0]) * b;
    a[2] = (k / a[0]) * c;
    for (int i = 0; i < 3; i++) {
      if (a[i] >= 1000)
        return false;
    }
    for (int i = 0; i < 3; i++) {
      while (a[i] > 0) {
        num[(a[i]) % 10]++;
        a[i] /= 10;
      }
    }
    a[0] = k;
    a[1] = (k / a[0]) * b;
    a[2] = (k / a[0]) * c;
    for (int i = 0; i < 10; i++) {
      System.out.println(num[i]);
    }
    for (int i = 1; i < 10; i++) {
      if (num[i] != 1)
        return false;
    }
    for (int i = 0; i < 3; i++)
      System.out.printf("%d ???", a[i]);
    System.out.println(11);
    return true;
  }

  public static void main(String[] args) {
    Scanner cin = new Scanner(System.in);
    a = cin.nextInt();
    b = cin.nextInt();
    c = cin.nextInt();
    for (int i = 100; i <= 999; i++) {
      if ((i % a) != 0)
        continue;
      ck(i);
    }
    return;
  }

}