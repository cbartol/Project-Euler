package week;

public class Friday extends WeekDay{
	public Friday(){
		super("Friday");
	}
	public WeekDay nextDay(){
		return new Saturday();
	}
}
