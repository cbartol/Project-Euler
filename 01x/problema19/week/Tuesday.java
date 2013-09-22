package week;

public class Tuesday extends WeekDay{
	public Tuesday(){
		super("Tuesday");
	}
	public WeekDay nextDay(){
		return new Wednesday();
	}
}
