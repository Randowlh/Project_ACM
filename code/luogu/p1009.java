import java.util.*;
import java.math.*;
class Main{
    public static void main(String args[]){
        BigInteger a=new BigInteger("1");
        BigInteger ans=new BigInteger("0");
        int n;
        Scanner s = new Scanner(System.in);
        n=s.nextInt();
        BigInteger now=new BigInteger("0");
        for(int i=1;i<=n;i++){
            now=now.add(new BigInteger("1"));
           // System.out.println(now);
            a=a.multiply(now);
            ans=ans.add(a);
        }
        System.out.println(ans);
    }
}