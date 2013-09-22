import java.lang.Comparable;

public class Nome implements Comparable{
	private String _name;
	private int _score;
	
	public Nome(String name){
		_name = name;
		_score = 0;
		
		char nome[] = name.toCharArray();
		int nome_len = name.length();
		int i;
		for(i = 0 ; i < nome_len ; i++){
			_score += nome[i] - 'A';
			_score++;
		}
	}
	
	public boolean equals(Object o){
		if(o == null) return false;
		if (o instanceof Nome) {
			Nome n = (Nome) o;
				return _name.equals(n.getName());
			}
		return false;
	}
	
	public String getName(){
		return _name;
	}
	public int getScore(){
		return _score;
	}

	public int compareTo(Object o){
		if(o == null) return 0;
		if (o instanceof Nome) {
			Nome n = (Nome) o;
				return _name.compareTo(n.getName());
			}
		return 0;
	}
	public String toString(){
		return _name;
	}
}
