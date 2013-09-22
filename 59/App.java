import java.io.*;
import java.util.*;

public class App{
		public static List<String> _words;

		
		public static void main(String[] args){
			_words = new LinkedList<String>();
			try{
				BufferedReader in = new BufferedReader (new FileReader("words.txt"));
				String str;
				while((str=in.readLine()) != null){
					_words.add(str);
				}
			} catch (Exception e){
				System.out.println(e.getMessage());
			}
		
		try{
			//read input
			String str;
			char []frase; 
			BufferedReader in = new BufferedReader (new FileReader("cipher1.txt"));
			str=in.readLine();
			String[] s = str.split(",");
			frase = new char[s.length];
			int i = 0;
			for(String num : s){
				frase[i] = (char) Integer.parseInt(num);
				i++;
			}
			
			char []password = {'a','a','a'};
			char []correctPassword = {'a','a','a'};
			int wordCount = 0;
			int wordCount2 = 0;
			char []temp = new char[1];
			for(password[2] = 'a' ; password[2] <= 'z' ; password[2]++){
				for(password[1] = 'a' ; password[1] <= 'z' ; password[1]++){
					for(password[0] = 'a' ; password[0] <= 'z' ; password[0]++){
						temp = frase.clone();
						for(int n = 0 ; n < temp.length ; n++){
							(temp[n]) ^= password[n%3];
						}
						int word = getMatchs(new String(temp));
						if(word > wordCount){
							if(wordCount > wordCount2)
								wordCount2 = wordCount;
							wordCount = word;
							correctPassword[0] = password[0];
							correctPassword[1] = password[1];
							correctPassword[2] = password[2];
						} else if(word > wordCount2){
							wordCount2 = word;
						}
					}
				}
			}
			
			temp = frase.clone();
			for(int n = 0 ; n < temp.length ; n++){
				(temp[n]) ^= correctPassword[n%3];
			}
			
			
			BufferedWriter out = new BufferedWriter (new FileWriter("temp.txt"));
			out.write(temp,0,temp.length);
			System.out.println(temp);
			int sum = 0;
			for(int z = 0 ; z < temp.length ; z++){
				sum += (int) temp[z];
			}
			System.out.println("First word count: " + wordCount);
			System.out.println("Second word count: " + wordCount2);
			System.out.println("Answer: " + sum);
			out.flush();
			in.close();
			out.close();
			//convert input to char*
			
			//for gigante que vai de aaa -> zzz
		}catch(IOException e){
			System.out.println(e.getMessage());
		}
	
	}
	public static int getMatchs(String str){
		int match = 0;
		for(String s: _words){
			if(str.contains(s)){
				match++;
			}
		}
		return match;
	}
}