package week;

public class Wednesday extends WeekDay{
	public Wednesday(){
		super("Wednesday");
	}
	public WeekDay nextDay(){
		return new Thursday();
	}
}
