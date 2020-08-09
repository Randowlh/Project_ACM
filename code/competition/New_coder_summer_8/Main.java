import java.util.*;
import java.math.*;
public class Main{
    static BigInteger[] stk= new BigInteger[10000];
    static BigInteger[] pre= new BigInteger[10000];
    static int tail=0;
    public BigInteger pows(BigInteger a, long b){
        BigInteger ans = new BigInteger("1");
        BigInteger now = a;
        if(b==0)
        return new BigInteger("1");
        int tmp=0;
        while(b>0){
            if(b%2==1){
                ans=ans.multiply(now);
            }
            now=now.multiply(now);
            b/=2;
        }
        return ans;
    }
    public  void calc(){
        BigInteger zr= new BigInteger("0");
        String in;
        Scanner cin=new Scanner(System.in);
        in=cin.next();
        int cheng=0;
        int flag=0;
        for(int i=0;i<5000;i++){
            stk[i]=new BigInteger("0");
            pre[i]=new BigInteger("0");
        }
        for(int i=0;i<in.length();i++){
            if(in.charAt(i)=='('){
                cheng=cheng+1;
                flag=0;
            }else
            if(in.charAt(i)==')'){
                stk[cheng]=stk[cheng].add(pre[cheng]);
                pre[cheng]=zr;
                cheng--;
                flag=0;
                stk[cheng]=stk[cheng].add(pows(pre[cheng], stk[cheng+1].longValue()));
                stk[cheng+1]=zr;
                pre[cheng]=zr;
            }else
            if(in.charAt(i)<='9'&&in.charAt(i)>='0'){    
                if(flag>0){
                    pre[cheng]=pre[cheng].multiply(new BigInteger("10"));
                    pre[cheng]=pre[cheng].add(new BigInteger(in.substring(i,i+1)));
                }else{
                    stk[cheng].add(pre[cheng]);
                    flag=1;
                    pre[cheng]=new BigInteger(in.substring(i,i+1));
                }
            }else
            if(in.charAt(i)=='+'){
                stk[cheng]=stk[cheng].add(pre[cheng]);
                pre[cheng]=zr;
                flag=0;
            }
        }
        stk[cheng]=stk[cheng].add(pre[cheng]);
        System.out.println(stk[0]);
    }
    public static void main(String args[]){
        Main a=new Main();
        a.calc();
    }
}