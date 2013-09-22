package week;

public class Thursday extends WeekDay{
	public Thursday(){
		super("Thursday");
	}
	public WeekDay nextDay(){
		return new Friday();
	}
}
