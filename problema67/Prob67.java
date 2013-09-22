import java.util.List;
import java.util.ArrayList;
import java.io.FileReader;
import java.util.Scanner;

public class Prob67 {
	static public int PIR_LVLS = 100;
	static public int PIR_SIZE = levelToPosition(PIR_LVLS+1);
	public static void main(String[] args){
		
		List<TriangleNode> lista = new ArrayList<TriangleNode>();
		
		lista = makePiramide(PIR_SIZE);
		System.out.println(lista);
	}

	public static List<TriangleNode> makePiramide(int size){
		List<TriangleNode> lst = new ArrayList<TriangleNode>();
		int i;
		FileReader fin = new FileReader("lal.txt");
        Scanner src = new Scanner(fin);
		for(i = 0 ; i < size ; i++){
			lst.add(new Triangle(lst, src.nextInt(), , PositionToLevel(i));
		}
		return lst;
	}
	
	private static int levelToPosition(int lvl){
		int i, sum = 0;
		for(i = 1 ; i < lvl ; i++)
			sum += i;
		return sum;
	}
	private static int PositionToLevel(int pos){
		int i;
		for(i = 1 ; i <= pos ; i++)
			pos -= i;
		return i;
	}
}
