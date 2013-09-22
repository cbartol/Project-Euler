import java.util.Iterator;
import java.lang.Exception;
import java.util.List;
import java.util.Comparator;

class ListComparator implements Comparator<List<Integer> >{            
	public int compare(List<Integer> l1, List<Integer> l2){
		Integer n1, n2;
		Iterator<Integer> i1 = l1.iterator();
		Iterator<Integer> i2 = l2.iterator();
		try{
			while(true){
				n1 = i1.next();
				n2 = i2.next();
				if(n1 != n2)
					return n1 - n2;
			}
		}
		catch(Exception e){
			return 0;
		}
	}
}
