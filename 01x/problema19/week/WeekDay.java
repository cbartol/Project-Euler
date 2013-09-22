package week;

public abstract class WeekDay{
	private String _day;
	public WeekDay(String day){
		_day = day;
	}
	public abstract WeekDay nextDay();
	public String getWeekDay(){
		return _day;
	}
	public boolean equals(WeekDay day){
		return _day.equals(day.getWeekDay());
	}
}
