import java.util.ArrayList;

public class Prob14{
	public ArrayList<ArrayList<Double> > table;

	public Prob14(){
		table = new ArrayList<ArrayList<Double> >();
		ArrayList<Double> xp = new ArrayList<Double>();
		xp.add(1.0);
		table.add(xp);
		for(int i = 1 ; i < 1000000.0; i++){
			table.add(new ArrayList<Double>());
		}
	}

	public static void main(String[] args){
		Prob14 teste = new Prob14();
		Double num = 0.0;
		int chain_length = 0;
		for(Double i = 2.0 ; i < 1000000.0 ; i++){
			teste.makeChain(i);
		}
		for(ArrayList<Double> chain : teste.table){
			if(chain.size() > chain_length){
				chain_length = chain.size();
				num = chain.get(0);
			}
		}
		System.out.println(num + " " + chain_length);
	}
	
	public void makeChain(Double startchain){
		ArrayList<Double> chain = new ArrayList<Double>();
		Double n;
		chain.add(startchain);
		for(n = next(startchain); n > startchain ; ){
			chain.add(n);
			n = next(n);
		}
		chain.addAll(table.get(n.intValue()-1));
		table.set(startchain.intValue() - 1 , chain);
	}
	
	public Double next(Double num){
		if(num == 1) return 1.0;
		if(num % 2 == 0)
			num = num/2;
		else
			num = 3*num + 1;
		return num;
	}

}
