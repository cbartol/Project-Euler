package week;

public class Sunday extends WeekDay{
	public Sunday(){
		super("Sunday");
	}
	public WeekDay nextDay(){
		return new Monday();
	}
}
