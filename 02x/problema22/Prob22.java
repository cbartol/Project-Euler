/*
 *	Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.
 *
 *	For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 x 53 = 49714.
 *
 *	What is the total of all the name scores in the file?
 */

import java.io.FileReader;
import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.io.IOException;
import java.util.Collections;

public class Prob22{
	public static List<Nome> _nomes = new ArrayList<Nome>();
	public static void main(String[] args) throws IOException{
		int i;
		Scanner src = new Scanner(new FileReader("names.txt"));
		for(i = 0 ; i < 5163 ; i++){
			_nomes.add(new Nome(src.next()));
		}
		src.close();
		Collections.sort(_nomes);
		int score = 0;
		for(i = 1 ; i <= 5163 ; i++){
			score += ((_nomes.get(i-1)).getScore()*i);
		}
		System.out.println(score);
	}




}
