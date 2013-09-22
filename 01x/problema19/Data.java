import java.lang.Comparable;
import java.io.Serializable;
import week.*;

public class Data implements Comparable<Data>, Serializable{
	private int _day;
	private int _month;
	private int _year;
	private WeekDay _weekDay;

	public Data(int day, int month, int year, WeekDay week){
		_day = day;
		_month = month;
		_year = year;
		_weekDay = week;
	}
/*	public Data(String s){
		String[] data = s.split("-");
		_day = Integer.valueOf(data[0]);
		_month = Integer.valueOf(data[1]);
		_year = Integer.valueOf(data[2]);
		_weekDay = null;
	}*/
	
	public int getDay() {return _day;}
	public int getMonth() {return _month;}
	public int getYear() {return _year;}
	public WeekDay getWeekDay() {return _weekDay;}
	
	public void nextDay(){
		_weekDay = _weekDay.nextDay();
		boolean nextMonth;
		boolean bissexto = (_year % 4 == 0 && !(_year % 100 == 0 && _year % 400 != 0));
		_day++;
		nextMonth = (_day > 31 && (_month == 1 || _month == 3 || _month == 5
				|| _month == 7 || _month == 8 || _month == 10 || _month == 12));
				
		nextMonth = nextMonth || (_day > 30 && (_month == 4 || _month == 6
				|| _month == 9 || _month == 11));
				
		nextMonth = nextMonth || (_month == 2 &&
				((bissexto) ? _day > 29 : _day > 28));
				
		if(nextMonth){
			_day = 1;
			_month++;
			if(_month > 12){
				_month = 1;
				_year++;
			}
		}
	}
	/*
	public int operator -(const Date & d){
		int age = _year - d.getYear();
		if(_month > d.getMonth())
			return age;
		else if(_month < d.getMonth())
			return age + 1;
		else if(_day >= d.getDay())
			return age;
		else
			return age + 1;
	}
	*/
	public int compareTo(Data d){
		if(_year - d.getYear() != 0)
			return _year - d.getYear();
		else if(_month - d.getMonth() != 0)
			return _month - d.getMonth();
		else if(_day - d.getDay() != 0)
			return _day - d.getDay();
		else
			return 0;
	}
	
	@Override
	public String toString(){
		return _day + "/" + _month + "/" + _year;
	}
	
	public boolean equals(Data d){
		return _day==d.getDay() && _month==d.getMonth() && _year==d.getYear();
	}
}
