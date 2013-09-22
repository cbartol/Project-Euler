package week;

public class Saturday extends WeekDay{
	public Saturday(){
		super("Saturday");
	}
	public WeekDay nextDay(){
		return new Sunday();
	}
}
