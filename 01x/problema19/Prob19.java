import week.*;

public class Prob19{
	public static void main(String[] args){
		int counter = 0;
		Data data = new Data(1, 1, 1901, new Tuesday());
		WeekDay domingo = new Sunday();
		while(data.getYear() != 2001){
			if(data.getDay() == 1 && (data.getWeekDay()).equals(domingo)){
				counter++;
			}
			data.nextDay();
		}
		System.out.println("Resultado: " + counter);
	}

}
