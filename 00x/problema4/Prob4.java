public class Prob4 {
	public static boolean isPalindromic(String p){
		char[] array = p.toCharArray();
		int i;
		int j;
		for(i=0, j=p.length()-1; i < j ; i++, j--){
			if(array[i] != array[j])
				return false;
		}
		return true;
	}
	
	public static void main(String[] args){
		int a, b;
		int max = 0;
		for(a = 0; a < 1000 ; a++){
			for(b = 0; b < 1000 ; b++){
				if(isPalindromic(String.valueOf(a*b)) && a*b > max)
					max = a*b;
			}
		}
		System.out.println("MAX: " + max);
	}
}
