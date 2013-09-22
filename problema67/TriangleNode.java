import java.util.List;
import java.util.ArrayList;

public class TriangleNode{
	private int _value;
	private List<Integer> _somatorios;
	private int _level;
	private int _positionInLine;

	public TriangleNode(List<TriangleNode> tri_lst, int value, int pos, int lvl){
		_value = value;
		_level = lvl;
		_positionInLine = pos;
		
		_somatorios = new ArrayList<Integer>();
		TriangleNode left;
		TriangleNode right;
		if(pos > 0){
			left = tri_lst.get((pos-1)+levelToPosition(lvl-1));
			_somatorios.addAll(left.getSomatorios());
		}
		if(pos < (lvl-1)){
			right = tri_lst.get(pos+levelToPosition(lvl-1));
			_somatorios.addAll(left.getSomatorios());
		}
		if(!_somatorios.isEmpty()){
			for(Integer i : _somatorios){
			 i += value;
			}
		}
		else{
			_somatorios.add(value);
		}
	}

	private int levelToPosition(int lvl){
		int i, sum = 0;
		for(i = 1 ; i < lvl ; i++)
			sum += i;
		return sum;
	}
	public List<Integer> getSomatorios(){
		return _somatorios;
	}
	
	public String toString(){
		return String.valueOf(_value);
	}
}
