package week;

public class Monday extends WeekDay{
	public Monday(){
		super("Monday");
	}
	public WeekDay nextDay(){
		return new Tuesday();
	}
}
