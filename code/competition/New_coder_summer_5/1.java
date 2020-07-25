package ustc.lichunchun.bigdataapi;
 
import java.math.BigInteger;
 
public class BigIntegerDemo1 {
 
	public static void main(String[] args) {
		BigInteger bi1 = new BigInteger("123456789") ;	
		BigInteger bi2 = new BigInteger("987654321") ;
        BigInteger result[] = bi2.divideAndRemainder(bi1);
        		System.out.println("商是：" + result[0] + "；余数是：" + result[1]) ;
	}
}